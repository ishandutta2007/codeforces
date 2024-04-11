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

map<int, int> cnt;
map<int, vector<int>> forCnt;
set<pii> banned;

bool isBad(int x, int y) {
	if (x > y) swap(x, y);
	return banned.count(mp(x, y)) == 1;
}

void solve() {
	cnt.clear();
	forCnt.clear();
	banned.clear();
	int n, m;
	scanf("%d%d", &n, &m);
	while(n--) {
		int x;
		scanf("%d", &x);
		cnt[-x]++;
	}
	while(m--) {
		int x, y;
		scanf("%d%d", &x, &y);
		x *= -1;
		y *= -1;
		if (x > y) swap(x, y);
		banned.insert(mp(x, y));
	}
	ll ans = 0;
	for (auto t : cnt)
		forCnt[t.second].push_back(t.first);
	vector<int> xx;
	for (auto t : forCnt)
		xx.push_back(t.first);
	for (int x : xx) {
		sort(all(forCnt[x]));
		//reverse(all(forCnt[x]));
	}
	for (int i = 0; i < (int)xx.size(); i++) {
		auto it1 = forCnt[xx[i]].begin();
		int sz1 = (int)forCnt[xx[i]].size();
		set<pair<int, pii>> setik;
		if (sz1 >= 2) {
			setik.clear();
			setik.insert(mp(*it1 + *(it1 + 1), mp(0, 1)));
			while(!setik.empty()) {
				auto cur = *setik.begin();
				setik.erase(setik.begin());
				int p = cur.second.first, q = cur.second.second;
				if (!isBad(*(it1 + p), *(it1 + q))) {
					ans = min(ans, (ll)(xx[i] + xx[i]) * cur.first);
					break;
				}
				if (p + 1 < q) setik.insert(mp(*(it1 + p + 1) + *(it1 + q), mp(p + 1, q)));
				if (q + 1 < sz1) setik.insert(mp(*(it1 + p) + *(it1 + q + 1), mp(p, q + 1)));
			}
		}
		for (int j = 0; j < i; j++) {
			auto it2 = forCnt[xx[j]].begin();
			int sz2 = (int)forCnt[xx[j]].size();
			setik.clear();
			setik.insert(mp(*it1 + *it2, mp(0, 0)));
			while(!setik.empty()) {
				auto cur = *setik.begin();
				setik.erase(setik.begin());
				int p = cur.second.first, q = cur.second.second;
				if (!isBad(*(it1 + p), *(it2 + q))) {
					ans = min(ans, (ll)(xx[i] + xx[j]) * cur.first);
					break;
				}
				if (p + 1 < sz1) setik.insert(mp(*(it1 + p + 1) + *(it2 + q), mp(p + 1, q)));
				if (q + 1 < sz2) setik.insert(mp(*(it1 + p) + *(it2 + q + 1), mp(p, q + 1)));
			}
		}
	}
	printf("%lld\n", -ans);
}

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	while(t--) solve();

	return 0;
}