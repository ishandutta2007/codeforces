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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__);fflush(stderr);
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

struct Frac {
	ll p, q;

	Frac() : p(0), q(1) {}
	Frac(ll _p, ll _q) : p(_p), q(_q) {}

	bool operator < (const Frac &F) const {
		return (__int128)p * F.q < (__int128)F.p * q;
	}
};

const int N = 100100;
int n, m, k;
ll cur[N];
int bstImp[N][2];
vector<pii> pl[N];
vector<pair<Frac, int>> res;
int tp[N];

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &k, &n, &m);
	for (int i = 0; i < k; i++) {
		scanf("%lld", &cur[i]);
		bstImp[i][0] = cur[i];
		bstImp[i][1] = -1;
	}
	for (int i = 1; i <= n; i++) {
		int p, x;
		scanf("%d%d%d", &tp[i], &p, &x);
		p--;
		if (tp[i] == 1) {
			if (x > bstImp[p][0]) {
				bstImp[p][0] = x;
				bstImp[p][1] = i;
			}
		} else if (tp[i] == 2) {
			pl[p].push_back(mp(x, i));
		} else {
			res.push_back(mp(Frac(x, 1), i));
		}
	}
	for (int i = 0; i < k; i++) {
		if (bstImp[i][1] != -1)
			pl[i].push_back(mp(bstImp[i][0] - (int)cur[i], bstImp[i][1]));
		sort(all(pl[i]));
		reverse(all(pl[i]));
		for (pii t : pl[i]) {
			res.push_back(mp(Frac(cur[i] + t.first, cur[i]), t.second));
			cur[i] += t.first;
		}
	}
	sort(all(res));
	reverse(all(res));
	while ((int)res.size() > m) res.pop_back();
	printf("%d\n", (int)res.size());
	for (int x = 1; x <= 3; x++)
		for (auto t : res) {
			int id = t.second;
			if (tp[id] == x)
				printf("%d ", id);
		}
	printf("\n");
	
	return 0;
}