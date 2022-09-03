#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int> > v[2];

int main () {
	int n, m;
	scanf ("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf ("%d%d", &a, &b); a--;
		v[a].push_back (make_pair (b, i + 1));
	}
	sort (v[0].begin (), v[0].end ());
	sort (v[1].begin (), v[1].end ());
	reverse (v[0].begin (), v[0].end ());
	reverse (v[1].begin (), v[1].end ());
	int ans = 0, a1 = 0, a2 = 0;
	int cur = 0, c1 = 0, c2 = 0;
	for (int i = 0; i < v[0].size () && c1 < m; i++) {
		c1++;
		cur += v[0][i].first;
	}
	do {
		while (c2 < v[1].size () && c1 + 2 * (c2 + 1) <= m) {
			cur += v[1][c2].first;
			c2++;
		}
		if (cur > ans) {
			ans = cur;
			a1 = c1;
			a2 = c2;
		}
		c1--;
		if (c1 < 0) break;
		cur -= v[0][c1].first;
	} while (true);
	printf ("%d\n", ans);
	for (int i = 0; i < a1; i++) printf ("%d ", v[0][i].second);
	for (int i = 0; i < a2; i++) printf ("%d ", v[1][i].second);
	printf ("\n");
}