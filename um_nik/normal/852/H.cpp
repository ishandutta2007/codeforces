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

	void scan() {
		scanf("%lld%lld", &x, &y);
	}
	void print() {
		printf("(%lld %lld)\n", x, y);
	}
	Point operator + (const Point &a) const {
		return Point(x + a.x, y + a.y);
	}
	Point operator - (const Point &a) const {
		return Point(x - a.x, y - a.y);
	}
	ll operator % (const Point &a) const {
		return x * a.x + y * a.y;
	}
	ll operator * (const Point &a) const {
		return x * a.y - y * a.x;
	}

	bool operator < (const Point &a) const {
		return *this * a > 0;
	}
};

bool cmp(const Point &a, const Point &b) {
	if (a.x != b.x) return a.x < b.x;
	return a.y < b.y;
}

const int N = 202;
const int K = 50;
ll ANS = 0;
int k;
Point a[N];
Point z[N];
ll dp[N][N][K];
ll inner[K];
bool good[N][N];
pair<Point, int> b[N];

ll solve(int n) {
	sort(a, a + n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int h = 0; h <= k; h++)
				dp[i][j][h] = -1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			good[i][j] = false;
	for (int i = 0; i < n - 1; i++) {
		good[i][i + 1] = true;
		Point P = a[i + 1];
		for (int j = i + 2; j < n; j++) {
			Point Q = a[j];
			if ((Q - a[i]) * (P - a[i]) > 0) continue;
			P = Q;
			good[i][j] = true;
		}
	}
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (good[i][j])
				dp[i][j][0] = a[i] * a[j];
	for (int i = 1; i < n - 1; i++) {
		int m = 0;
		for (int j = 0; j < i; j++) {
			if (good[j][i])
				b[m++] = mp(a[i] - a[j], j);
		}
		for (int j = i + 1; j < n; j++)
			if (good[i][j])
				b[m++] = mp(a[j] - a[i], j);
		sort(b, b + m);
		for (int j = 0; j <= k; j++)
			inner[j] = -1;
		for (int j = 0; j < m; j++) {
			int id = b[j].second;
			if (id < i) {
				for (int h = 0; h <= k; h++)
					inner[h] = max(inner[h], dp[id][i][h]);
			} else {
				ll S = a[i] * a[id];
				for (int h = 0; h < k; h++)
					if (inner[h] != -1)
						dp[i][id][h + 1] = max(dp[i][id][h + 1], inner[h] + S);
			}
		}
	}
	ll ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			ans = max(ans, dp[i][j][k]);
	return ans;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int n;
	scanf("%d%d", &n, &k);
	k -= 3;
	for (int i = 0; i < n; i++)
		z[i].scan();
	sort(z, z + n, cmp);
	for (int i = 0; i < n; i++) {
		int m = 0;
		for (int j = i + 1; j < n; j++)
			a[m++] = z[j] - z[i];
		ANS = max(ANS, solve(m));
	}
	printf("%lld.", ANS / 2);
	if (ANS & 1)
		printf("50\n");
	else
		printf("00\n");

	return 0;
}