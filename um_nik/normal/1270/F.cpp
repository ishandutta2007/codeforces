#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef long double ld;
#define mp make_pair
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define tm jnyhrt

void eprintTime() {
	eprintf("time = %.5lf\n", (double)clock() / CLOCKS_PER_SEC);
}

const int N = 200200;
const int B = 160;
//const int B = 0;
char s[N];
int st[N];
int n;
ll ans;
ll b[N];

ll solve1old(ll R1, ll R2, ll k) {
//	eprintf("solve1 %lld %lld %lld\n", R1, R2, k);
	ll M1 = R1 % k, M2 = R2 % k;
	ll V1 = R1 / k, V2 = R2 / k;
	ll res = 0;
	if (M1 <= M2) {
		res += M1 * (V1 + 1) * (V2 + 1);
		res += (M2 - M1) * V1 * (V2 + 1);
		res += (k - M2) * V1 * V2;
	} else {
		res += M2 * (V1 + 1) * (V2 + 1);
		res += (M1 - M2) * (V1 + 1) * V2;
		res += (k - M1) * V1 * V2;
	}
	return res;
}
int ord[6];
int ord2[6];
ll solve1(int L1, int R1, int L2, int R2, int k) {
	ll res = 0;
/*
	res += solve1old(R1, R2, k) + solve1old(L1, L2, k);
	res -= solve1old(R1, L2, k) + solve1old(L1, R2, k);
	return res;
*/
	ord[0] = L1 % k;
	ord[1] = R1 % k;
	ord[2] = L2 % k;
	ord[3] = R2 % k;
	for (int i = 0; i < 4; i++)
		ord2[i] = ord[i];
	ord2[4] = 0;
	ord2[5] = k;
	sort(ord2, ord2 + 6);
	int V1 = R1 / k - L1 / k;
	int V2 = R2 / k - L2 / k;
	for (int i = 0; i < 5; i++) {
		int C1 = V1, C2 = V2;
		if (ord[0] > ord2[i]) C1--;
		if (ord[1] > ord2[i]) C1++;
		if (ord[2] > ord2[i]) C2--;
		if (ord[3] > ord2[i]) C2++;
		res += (ll)C1 * C2 * (ord2[i + 1] - ord2[i]);
	}
	return res;
}

int curVal[N];
ll lastBal[N];
int tm[N];
int T;
void addOne(ll x) {
	int p = x % N;
	if (tm[p] != T || lastBal[p] != x) {
		curVal[p] = 0;
		lastBal[p] = x;
		tm[p] = T;
	}
	curVal[p]++;
}
int getVal(ll x) {
	int p = x % N;
	if (tm[p] != T || lastBal[p] != x) return 0;
	return curVal[p];
}
ll solve2(ll toAdd, int minLen) {
	T++;
	ll res = 0;
	b[0] = n;
//	map<ll, int> mapchik;
	for (int i = 1; i <= n; i++) {
		b[i] = b[i - 1];
		if (s[i - 1] == '1')
			b[i] += toAdd;
		else
			b[i]--;
		if (i >= minLen) addOne(b[i - minLen]);
		res += getVal(b[i]);
	}
	return res;
}

int main()
{
//	freopen("big.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%s", s);
	n = strlen(s);

//	n = 200000;
//	for (int i = 0; i < n; i++)
//		s[i] = '0' + (rng() & 1);

	int bal = 0;
	st[0] = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '1') {
			bal++;
			st[bal] = i + 1;
		}
	}
	st[bal + 1] = n + 1;
//	for (int i = 0; i <= bal + 1; i++)
//		eprintf("%d ", st[i]);
//	eprintf("\n");
	for (int k = 1; k <= B && k <= bal; k++) {
		for (int i = 0; i + k <= bal; i++) {
			ans += solve1(st[i], st[i + 1], st[i + k], st[i + k + 1], k);
//			eprintf("ans = %lld\n", ans);
		}
	}
//	eprintTime();
	for (int k = 1; k <= n; k++) {
		int minLen = k * (B + 1);
		if (minLen > n) break;
		ans += solve2(k - 1, minLen);
	}
//	eprintTime();
	printf("%lld\n", ans);

	return 0;
}