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

struct Item {
	int l, r, cnt;

	Item() : l(), r(), cnt() {}

	bool operator < (const Item &I) const {
		return l < I.l;
	}
};

const int N = 200200;
Item b[N];
int n, m;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int q;
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		if (b[x].cnt == 0) {
			b[x].l = i;
		}
		b[x].r = i;
		b[x].cnt++;
	}
	m = 0;
	for (int i = 0; i < N; i++) {
		if (b[i].cnt != 0)
			b[m++] = b[i];
	}
	sort(b, b + m);
	int ans = n;
	int R = -1, mx = 0;
	for (int i = 0; i < m; i++) {
		if (R != -1 && R < b[i].l) {
			ans -= mx;
			R = -1;
			mx = 0;
		}
		R = max(R, b[i].r);
		mx = max(mx, b[i].cnt);
	}
	ans -= mx;
	printf("%d\n", ans);

	return 0;
}