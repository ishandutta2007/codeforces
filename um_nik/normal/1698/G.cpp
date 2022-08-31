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
#include <bitset>
#include <array>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) {fprintf(stderr, __VA_ARGS__);fflush(stderr);}
#else
	#define eprintf(...) 42
#endif

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
template<typename T>
using pair2 = pair<T, T>;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (ull)rng() % B;
}

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

clock_t startTime;
double getCurrentTime() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

const int N = 36;
int m;
struct Item {
	ll a[N];

	Item() {
		for (int i = 0; i < m; i++)
			a[i] = 1LL << i;
	}

	Item operator * (const Item &I) const {
		Item R = Item();
		for (int i = 0; i < m; i++) {
			R.a[i] = 0;
			for (int j = 0; j < m; j++)
				if ((a[i] >> j) & 1)
					R.a[i] ^= I.a[j];
		}
		return R;
	}

	ll eval(ll mask) const {
		ll res = 0;
		for (int i = 0; i < m; i++)
			if ((mask >> i) & 1)
				res ^= a[i];
		return res;
	}
};

Item bin_pow(Item I, ll p) {
	if (p == 0) return Item();
	if (p & 1) return I * bin_pow(I, p - 1);
	return bin_pow(I * I, p / 2);
}

map<ll, ll> mapchik;
ll solve(ll mask) {
	m = 0;
	while(mask >= (1LL << m)) m++;
	eprintf("solve %lld %d\n", mask, m);
	int k = min(m, m / 2 + 1);
	Item I = Item();
	for (int i = 1; i < m; i++)
		I.a[i] = 1LL << (i - 1);
	I.a[0] = mask;
	for (int i = 0; i < k; i++)
		I = I * I;
	ll cur = 1;
	for (int i = 0; i < (1 << k); i++) {
		//eprintf("i = %d, cur = %lld\n", i, cur);
		mapchik[cur] = i;
		ll nxt = cur >> 1;
		if (cur & 1) nxt ^= mask;
		cur = nxt;
		//eprintf("i = %d, cur = %lld\n", i, cur);
		//if (cur == 1) return i + 1;
	}
	cur = 1;
	for (int i = 1;; i++) {
		cur = I.eval(cur);
		if (mapchik.count(cur)) {
			return ((ll)i << k) - mapchik[cur];
		}
	}
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	char s[40];
	scanf("%s", s);
	int L = strlen(s);
	while(L > 0 && s[L - 1] == '0') L--;
	if (L == 0) {
		printf("-1\n");
		return 0;
	}
	int p = 0;
	while(s[p] == '0') p++;
	if (p + 1 == L) {
		printf("%d %d\n", p + 1, p + 2);
		return 0;
	}
	ll mask = 0;
	for (int i = L - 1; i > p; i--)
		mask = mask * 2 + (ll)(s[i] - '0');
	assert(mask > 0);
	ll ans = solve(mask);
	printf("%d %lld\n", p + 1, ans + p + 1);

	return 0;
}