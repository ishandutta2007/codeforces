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

map<pii, char> mapchik;
int cnt1, cnt2;

int main()
{
	startTime = clock();
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int n, q;
	scanf("%d%d", &n, &q);
	while(q--) {
		char t;
		scanf(" %c", &t);
		if (t == '+') {
			int v, u;
			char c;
			scanf("%d %d %c", &v, &u, &c);
			mapchik[mp(v, u)] = c;
			if (mapchik.count(mp(u, v))) {
				cnt1++;
				if (mapchik[mp(u, v)] == c) cnt2++;
			}
		} else if (t == '-') {
			int v, u;
			scanf("%d%d", &v, &u);
			if (mapchik.count(mp(u, v))) {
				cnt1--;
				if (mapchik[mp(v, u)] == mapchik[mp(u, v)]) cnt2--;
			}
			mapchik.erase(mp(v, u));
		} else {
			int k;
			scanf("%d", &k);
			if (k & 1) {
				if (cnt1)
					printf("YES\n");
				else
					printf("NO\n");
			} else {
				if (cnt2)
					printf("YES\n");
				else
					printf("NO\n");
			}
		}
	}

	return 0;
}