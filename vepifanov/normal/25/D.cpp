#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v[1000], w;
vector<pair<int, int> > e;
int was[1000];

int go (int x, int p) {
	was[x] = 1;
	for (int i = 0; i < v[x].size (); i++) {
		int y = v[x][i];
		if (y == p) continue;
		if (was[y] == 0) go (y, x); else
		if (was[y] == 1) e.push_back (make_pair (x + 1, y + 1));
	}
	was[x] = 2;
}

int main() {
	int n;
	scanf ("%d\n", &n);
	for (int i = 0; i + 1 < n; i++) {
		int a, b;
		scanf ("%d%d", &a, &b); a--; b--;
		v[a].push_back (b);
		v[b].push_back (a);
	}
	for (int i = 0; i < n; i++)
		if (!was[i]) {
			w.push_back (i + 1);
			go (i, -1);
		}
	printf ("%d\n", e.size ());
	for (int i = 0; i < e.size (); i++)
		printf ("%d %d %d %d\n", e[i].first, e[i].second, w[i], w[i + 1]);
	return 0;
}