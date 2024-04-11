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

const int LOG = 19;
const int N = 500500;
int n, m;
vector<int> ev[N];
multiset<int> setik;
int a[N][LOG];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		int l, r;
		scanf("%d%d", &l, &r);
		ev[l].push_back(r);
		ev[r].push_back(-r);
	}
	for (int t = 0; t < N; t++) {
		a[t][0] = t;
		for (int x : ev[t]) {
			if (x > 0) {
				setik.insert(x);
			} else {
				setik.erase(setik.find(-x));
			}
		}
		if (!setik.empty())
			a[t][0] = *setik.rbegin();
	}
	for (int k = 0; k < LOG - 1; k++) {
		for (int i = 0; i < N; i++)
			a[i][k + 1] = a[a[i][k]][k];
	}
	while(m--) {
		int l, r;
		scanf("%d%d", &l, &r);
		int ans = 0;
		for (int k = LOG - 1; k >= 0; k--) {
			if (a[l][k] < r) {
				ans += 1 << k;
				l = a[l][k];
			}
		}
		ans++;
		if (ans > n) ans = -1;
		printf("%d\n", ans);
	}

	return 0;
}