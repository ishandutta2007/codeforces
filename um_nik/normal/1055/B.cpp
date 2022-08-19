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

const int N = 100100;
int n, m;
ll L;
ll a[N];
int ans;

bool check(int p) {
	return a[p] > L && a[p - 1] <= L;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d%lld", &n, &m, &L);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	for (int i = 1; i <= n; i++) {
		ans += (int)check(i);
	}
	while(m--) {
		int t;
		scanf("%d", &t);
		if (t == 0)
			printf("%d\n", ans);
		else {
			int p;
			ll d;
			scanf("%d%lld", &p, &d);
			ans -= (int)check(p);
			ans -= (int)check(p + 1);
			a[p] += d;
			ans += (int)check(p);
			ans += (int)check(p + 1);
		}
	}

	return 0;
}