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

const int N = 200100;
int n, w, h;
vector<pii> a[N];
vector<int> b[N];
int ans[N][2];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &w, &h);
	for (int i = 0; i < n; i++) {
		int g, p, t;
		scanf("%d%d%d", &g, &p, &t);
		int val = p - t + N / 2;
		if (g == 2) p *= -1;
		a[val].push_back(mp(p, i));
		if (g == 2) {
			p *= -1;
			p = h + w - p;
		}
		b[val].push_back(p);
	}
	for (int x = 0; x < N; x++) {
		if (a[x].empty()) continue;
		sort(a[x].begin(), a[x].end());
		sort(b[x].begin(), b[x].end());
		for (int i = 0; i < (int)a[x].size(); i++) {
			int id = a[x][i].second;
			int y = b[x][i];
			if (y < w) {
				ans[id][0] = y;
				ans[id][1] = h;
			} else {
				ans[id][0] = w;
				ans[id][1] = h + w - y;
			}
		}
	}
	for (int i = 0; i < n; i++)
		printf("%d %d\n", ans[i][0], ans[i][1]);

	return 0;
}