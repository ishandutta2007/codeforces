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

const ll MOD = (ll)1e9 + 7;
ll add(ll x, ll y) {
	x += y;
	if (x >= MOD) return x - MOD;
	return x;
}
ll sub(ll x, ll y) {
	x -= y;
	if (x < 0) return x + MOD;
	return x;
}
ll mult(ll x, ll y) {
	return (x * y) % MOD;
}

const int N = 5050;
int n, m;
vector<int> a[N];
vector<int> b[N];
int ans1 = 0;
ll ans2 = 1;

void relaxAns(int x, ll y) {
	if (x > ans1) {
		ans1 = x;
		ans2 = 0;
	}
	if (x == ans1) ans2 = add(ans2, y);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		x--;
		a[x].push_back(i);
	}
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		if (y <= (int)a[x].size()) b[x].push_back(y);
	}
	for (int i = 0; i < n; i++)
		sort(b[i].begin(), b[i].end());
	for (int id = 0; id < n; id++)
		for (int i = 0; i < (int)b[id].size(); i++) {
//			eprintf("solving %d %d\n", id, i);
			int cur1 = 1;
			ll cur2 = 1;
			int p = a[id][b[id][i] - 1];
			for (int c = 0; c < n; c++) {
				int q1 = 0, q2 = 0;
				while(q1 < (int)b[c].size() && a[c][b[c][q1] - 1] < p) q1++;
				while(q2 < (int)b[c].size() && a[c][(int)a[c].size() - b[c][q2]] > p) q2++;
				if (c == id) {
					q1 = 0;
					if (q2 > i) q2--;
				}
//				eprintf("%d %d %d\n", c, q1, q2);
				if (q1 < q2) swap(q1, q2);
				if (q1 == 0) {

				} else if (q2 == 0) {
					cur1++;
					cur2 = mult(cur2, q1);
				} else if (q1 == 1) {
					cur1++;
					cur2 = mult(cur2, 2);
				} else {
					cur1 += 2;
					cur2 = mult(cur2, q2 * (q1 - 1));
				}
			}
			relaxAns(cur1, cur2);
		}
	for (int id = 0; id < n; id++)
		for (int i = 0; i < (int)b[id].size(); i++) {
			int cur1 = 1;
			ll cur2 = 1;
			int p = a[id][(int)a[id].size() - b[id][i]];
			for (int c = 0; c < n; c++) {
				int q = 0;
				while(q < (int)b[c].size() && a[c][(int)a[c].size() - b[c][q]] > p) q++;
				if (c == id) {
					q = 0;
				}
				if (q > 0) {
					cur1++;
					cur2 = mult(cur2, q);
				}
			}
			relaxAns(cur1, cur2);
		}
	printf("%d %lld\n", ans1, ans2);

	return 0;
}