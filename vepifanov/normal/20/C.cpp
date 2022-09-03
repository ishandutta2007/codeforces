#include <cstdio>
#include <vector>
#include <set>
#include <cstring>

using namespace std;

long long res[100000];
vector<pair<int, int> > v[100000];
set<pair<long long, int> > all;
int prev[100000], mark[100000];

int out (int x) {
	if (x != 0) out (prev[x]);
	printf ("%d ", x + 1);
}

int main () {
	int n, m;
	scanf ("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf ("%d%d%d", &a, &b, &c); a--; b--;
		v[a].push_back (make_pair (b, c));
		v[b].push_back (make_pair (a, c));
	}
	memset (mark, 0, sizeof (mark));
	mark[0] = 1;
	res[0] = 0;
	all.insert (make_pair (0, 0));
	while (!all.empty ()) {
		int i = all.begin ()->second;
		long long d = all.begin ()->first;
		all.erase (all.begin ());
		mark[i] = 2;
		for (int j = 0; j < v[i].size (); j++) {
			int k = v[i][j].first;
			long long D = d + v[i][j].second;
			if (mark[k] == 0 || mark[k] == 1 && res[k] > D) {
				if (mark[k] == 1) all.erase (make_pair (res[k], k));
				mark[k] = 1;
				res[k] = D;
				prev[k] = i;
				all.insert (make_pair (D, k));
			}
		}
	}
	if (mark[n - 1] == 2) out (n - 1); else printf ("-1");
	printf ("\n");
}