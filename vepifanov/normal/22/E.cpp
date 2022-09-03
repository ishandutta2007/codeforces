#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n, cnt[100000], f[100000], was[100000], next[100000];

vector<pair<int, int> > v;

int go (int x) {
	if (was[x]) return next[x];
	was[x] = 1;
	next[x] = x;
	next[x] = go (f[x]);
	return next[x];
}

int main() {
	scanf ("%d", &n); 
	for (int i = 0; i < n; i++) {
		int a;
		scanf ("%d", &f[i]); f[i]--;
		cnt[f[i]]++;
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
		if (cnt[i] == 0) v.push_back (make_pair (i + 1, go (i) + 1));
	for (int i = 0; i < n; i++)
		if (!was[i]) { 
			go (i);
			v.push_back (make_pair (i + 1, i + 1));
		}
	int m = v.size ();
	if (m == 1 && v[0].first == v[0].second) printf ("0\n"); else {
		printf ("%d\n", m);
		for (int i = 0; i < m; i++) printf ("%d %d\n", v[i].second, v[(i + 1) % m].first);
	}
	return 0;
}