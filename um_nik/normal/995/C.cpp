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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

struct Point {
	ll x, y;

	Point() : x(), y() {}
	Point(ll _x, ll _y) : x(_x), y(_y) {}

	Point operator + (const Point &a) const {
		return Point(x + a.x, y + a.y);
	}
	Point operator - (const Point &a) const {
		return Point(x - a.x, y - a.y);
	}
	ll sqrLen() const {
		return x * x + y * y;
	}

	void scan() {
		scanf("%lld%lld", &x, &y);
	}
};

const int N = 500500;
Point a[N];
vector<int> alive;
int par[N][4];
int n;
int cur[3];
int ans[N];

const ll C = (ll)1e6 * (ll)1e6;

void dfs(int v) {
	if (par[v][0] == -1) return;
	for (int i = 0; i < 4; i += 2) {
		int u = par[v][i];
		ans[u] = ans[v] * par[v][i + 1];
		dfs(u);
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	int oldn = n;
	if (n == 1) {
		printf("1\n");
		return 0;
	}
	for (int i = 0; i < n; i++)
		par[i][0] = -1;
	for (int i = 0; i < n; i++)
		a[i].scan();
	for (int i = 0; i < n; i++)
		alive.push_back(i);
	while((int)alive.size() > 2) {
		for (int i = 0; i < 3; i++) {
			cur[i] = alive.back();
			alive.pop_back();
		}
		bool fnd = false;
		for (int i = 0; !fnd && i < 3; i++)
			for (int j = 0; !fnd && j < i; j++) {
				Point v = a[cur[i]] + a[cur[j]];
				if (v.sqrLen() <= C) {
					a[n] = v;
					par[n][0] = cur[i];
					par[n][1] = 1;
					par[n][2] = cur[j];
					par[n][3] = 1;
					alive.push_back(cur[i ^ j ^ 3]);
					alive.push_back(n);
					n++;
					fnd = true;
					break;
				}
				v = a[cur[i]] - a[cur[j]];
				if (v.sqrLen() <= C) {
					a[n] = v;
					par[n][0] = cur[i];
					par[n][1] = 1;
					par[n][2] = cur[j];
					par[n][3] = -1;
					alive.push_back(cur[i ^ j ^ 3]);
					alive.push_back(n);
					n++;
					fnd = true;
					break;
				}
			}
		if (!fnd) throw;
	}

	for (int i = 0; i < 2; i++) {
		cur[i] = alive.back();
		alive.pop_back();
	}
	Point v = a[cur[0]] + a[cur[1]];
	ans[cur[0]] = 1;
	if (v.sqrLen() <= 2 * C) {
		ans[cur[1]] = 1;
	} else {
		ans[cur[1]] = -1;
	}
	dfs(cur[0]);
	dfs(cur[1]);

	for (int i = 0; i < oldn; i++)
		printf("%d ", ans[i]);
	printf("\n");

	return 0;
}