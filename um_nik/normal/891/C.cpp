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

struct Change {
	int* pos;
	int oldVal;

	Change() : pos(), oldVal() {}
	Change(int* _pos, int _oldVal) : pos(_pos), oldVal(_oldVal) {}

	void apply() {
		*pos = oldVal;
	}
};

const int S = (int)3e6;
Change st[S];
int stSz;

void makeChange(int* pos, int val) {
	st[stSz++] = Change(pos, *pos);
	*pos = val;
}

void undoChanges(int oldSz) {
	while(stSz > oldSz) {
		st[--stSz].apply();
	}
}

const int N = 500500;
int ed[N][3];
int xs[N];
int par[N];
int sz[N];
bool ans[N];
vector<pii> a[N];
vector<int> all[N];
int n, m, k, q;

int getPar(int v) {
	if (par[v] == -1) return v;
	return getPar(par[v]);
}
bool unite(int v, int u) {
	v = getPar(v);
	u = getPar(u);
	if (v == u) return false;
	if (sz[v] < sz[u]) swap(v, u);
	makeChange(&par[u], v);
	makeChange(&sz[v], sz[v] + sz[u]);
	return true;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		par[i] = -1;
		sz[i] = 1;
	}
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &ed[i][0], &ed[i][1], &ed[i][2]);
		ed[i][0]--;
		ed[i][1]--;
		xs[k++] = ed[i][2];
	}
	sort(xs, xs + k);
	k = unique(xs, xs + k) - xs;
	for (int i = 0; i < m; i++) {
		ed[i][2] = lower_bound(xs, xs + k, ed[i][2]) - xs;
		all[ed[i][2]].push_back(i);
	}
	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		ans[i] = 1;
		int z;
		scanf("%d", &z);
		while(z--) {
			int id;
			scanf("%d", &id);
			id--;
			a[ed[id][2]].push_back(mp(id, i));
		}
	}

	for (int d = 0; d < k; d++) {
		stSz = 0;
		int L = 0;
		while(L < (int)a[d].size()) {
			int R = L;
			while(R < (int)a[d].size() && a[d][L].second == a[d][R].second) R++;
			for (int i = L; i < R; i++)
				ans[a[d][L].second] &= unite(ed[a[d][i].first][0], ed[a[d][i].first][1]);
			undoChanges(0);
			L = R;
		}
		for (int id : all[d])
			unite(ed[id][0], ed[id][1]);
	}
	for (int i = 0; i < q; i++) {
		if (ans[i])
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}