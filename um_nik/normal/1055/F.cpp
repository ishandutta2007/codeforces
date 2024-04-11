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

const int N = (int)1e6 + 7;
const int K = 62;
ll a[N];
int n;
ll k;
int curV[N];
ll cnt[N * 2];
int go[N][2];
int goSz;
int curList[N][2];
int nwList[N][2];
int listSz;

ll countZero(int pw) {
	memset(cnt, 0, sizeof cnt);
	for (int i = 0; i < n; i++) {
		int v = curV[i];
		int t = (a[i] >> pw) & 1;
		cnt[2 * v + t]++;
	}
	ll res = 0;
	for (int i = 0; i < listSz; i++) {
		int v = curList[i][0], u = curList[i][1];
		res += cnt[2 * v] * cnt[2 * u];
		res += cnt[2 * v + 1] * cnt[2 * u + 1];
	}
	return res;
}
void buildNew(int pw, int t) {
	memset(go, -1, sizeof go);
	goSz = 0;
	for (int i = 0; i < n; i++) {
		int v = curV[i];
		int c = (a[i] >> pw) & 1;
		if (go[v][c] == -1)
			go[v][c] = goSz++;
		curV[i] = go[v][c];
	}
	int newSz = 0;
	for (int i = 0; i < listSz; i++) {
		int v = curList[i][0], u = curList[i][1];
		for (int c = 0; c < 2; c++) {
			if (go[v][c] == -1 || go[u][c ^ t] == -1) continue;
			nwList[newSz][0] = go[v][c];
			nwList[newSz][1] = go[u][c ^ t];
			newSz++;
		}
	}
	listSz = newSz;
	for (int i = 0; i < listSz; i++)
		for (int j = 0; j < 2; j++)
			curList[i][j] = nwList[i][j];
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%lld", &n, &k);
	for (int i = 1; i < n; i++) {
		int v;
		ll x;
		scanf("%d%lld", &v, &x);
		v--;
		a[i] = a[v] ^ x;
	}
	for (int i = 0; i < n; i++)
		curV[i] = 0;
	curList[0][0] = curList[0][1] = 0;
	listSz = 1;
	k--;
	ll ANS = 0;
	for (int pw = K - 1; pw >= 0; pw--) {
		ll z = countZero(pw);
		if (z > k) {
			buildNew(pw, 0);
		} else {
			k -= z;
			ANS ^= 1LL << pw;
			buildNew(pw, 1);
		}
	}
	printf("%lld\n", ANS);

	return 0;
}