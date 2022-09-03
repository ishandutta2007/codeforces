#include <cstdio>
#include <set>
#include <cstring>
#include <algorithm>

using namespace std;

#define mp make_pair

typedef pair<int, int> ii;

int n, m;
int mark[1 << 15], d[1 << 15];
int ea[2000], eb[2000], ec[2000], p[15], was[15];
set<ii> all;

int update (int mask, int x, int y) {
	return mask ^ (1 << x) ^ (1 << y);
}

int main() {
	scanf ("%d%d", &n, &m);
	for (int i = 0; i < n; i++) p[i] = i;
	int mask = 0, s = 0;
	for (int i = 0; i < m; i++) {
		scanf ("%d%d%d", &ea[i], &eb[i], &ec[i]);
		ea[i]--;
		eb[i]--;
		mask = update (mask, ea[i], eb[i]);
		was[ea[i]] = 1;
		was[eb[i]] = 1;
		s += ec[i];
		if (p[ea[i]] != p[eb[i]]) {
			int t = p[eb[i]];
			for (int j = 0; j < n; j++)
				if (p[j] == t)
					p[j] = p[ea[i]];
		}
	}
	for (int i = 1; i < n; i++)
		if (was[i] && p[i] != p[0]) {
			printf ("-1\n");
			return 0;
		}
	memset (mark, 0, sizeof (mark));
	mark[mask] = 1;
	all.insert (mp (0, mask));
	while (!all.empty ()) {
		int mask = all.begin ()->second;
		all.erase (all.begin ());
		if (mask == 0) {
			printf ("%d\n", d[mask] + s);
			return 0;
		}
		mark[mask] = 2;
		for (int i = 0; i < m; i++) {
			int nmask = update (mask, ea[i], eb[i]);
			if (mark[nmask] == 0 || mark[nmask] == 1 && d[nmask] > d[mask] + ec[i]) {
				if (mark[nmask] == 1) all.erase (mp (d[nmask], nmask));
				mark[nmask] = 1;
				d[nmask] = d[mask] + ec[i];
				all.insert (mp (d[nmask], nmask));
			}
		}
	}
	printf ("-1\n");
	return 0;
}