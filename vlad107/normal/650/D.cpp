#include <iostream>
#include <sstream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
 
using namespace std;
 
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n";
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
 
#define equal equalll
#define less lesss

const int INF = 1e9;

int n, m, maxV, maxI;
vector<int> h, le, ri, sa, maxLe, maxRi, v, cnt;
vector< vector< pair<int, int> > > quest;
vector< vector<int> > g, u;
vector<int> ans;

int getmax(int x) {
	int res = 0;
	for (int i = x; i > 0; i = (i & (i - 1))) res = max(res, sa[i]);
	return res;
}

void upd(int x, int val) {
	for (int i = x; i <= maxV; i = (i | (i - 1)) + 1) sa[i] = max(sa[i], val);
}

int main() {
	// freopen("input.txt", "r", stdin);
	scanf("%d%d", &n, &m);
	h.resize(n);
	le.resize(n);
	ri.resize(n);
	maxLe.resize(m);
	maxRi.resize(m);
	v.clear();
	for (int i = 0; i < n; i++) {
		scanf("%d", &h[i]);
		v.pb(h[i]);
	}
	quest.assign(n, vector< pair<int, int> >());
	ans.resize(m);
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		v.pb(y);
		--x;
		quest[x].pb(mp(y, i));
	}
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
	maxV = (int)v.size();
	for (int i = 0; i < n; i++) h[i] = lower_bound(v.begin(), v.end(), h[i]) - v.begin() + 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < (int)quest[i].size(); j++) {
			quest[i][j].fr = lower_bound(v.begin(), v.end(), quest[i][j].fr) - v.begin() + 1;
		}
	}
	sa.assign(maxV + 1, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < (int)quest[i].size(); j++) {
			maxLe[quest[i][j].sc] = getmax(quest[i][j].fr - 1);
		}
		le[i] = getmax(h[i] - 1) + 1;
		upd(h[i], le[i]);
	}
	sa.assign(maxV + 1, 0);
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < (int)quest[i].size(); j++) {
			maxRi[quest[i][j].sc] = getmax((maxV - quest[i][j].fr + 1) - 1);
		}
		ri[i] = getmax((maxV - h[i] + 1) - 1) + 1;
		upd(maxV - h[i] + 1, ri[i]);
	}
	maxI = 0;
	for (int i = 0; i < n; i++) maxI = max(maxI, le[i]);
	g.assign(maxI + 1, vector<int>());
	u.assign(maxI + 1, vector<int>());
	for (int i = 0; i < n; i++) g[le[i]].pb(h[i]);
	for (int i = 0; i < g.size(); i++) {
		if (g[i].empty()) continue;
		sort(g[i].begin(), g[i].end());
		g[i].resize(unique(g[i].begin(), g[i].end()) - g[i].begin());
		u[i].assign(g[i].size(), INF);
	}
	cnt.assign(n + 1, 0);
	for (int i = 0; i < n; i++) {
		if (le[i] == maxI) {
			cnt[i+1]++;
			cnt[n]--;
			break;
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		if (ri[i] == maxI) {
			cnt[0]++;
			cnt[i]--;
			break;
		}
	}
	for (int i = 0; i < n; i++) {
		int id = maxI - ri[i];
		// cerr << id << " " << maxI << endl;
		if (!g[id].empty()) {
			int idx = lower_bound(g[id].begin(), g[id].end(), h[i]) - g[id].begin();
			--idx;
			if ((idx >= 0) && (u[id][idx] != INF)) {
				assert(u[id][idx] < i);
				cnt[u[id][idx]+1]++;
				cnt[i]--;
			}
		}
		id = le[i];
		int idx = lower_bound(g[id].begin(), g[id].end(), h[i]) - g[id].begin();
		assert(g[id][idx] == h[i]);
		while ((idx < (int)u[id].size()) && (u[id][idx] == INF)) u[id][idx++] = i;
	}
	int curb = 0;
	for (int i = 0; i < n; i++) {
		curb += cnt[i];
		int maxWithout = maxI - 1;
		if (curb > 0) maxWithout = maxI;
		for (int j = 0; j < (int)quest[i].size(); j++) {
			int nom = quest[i][j].sc;
			ans[nom] = max(maxWithout, maxLe[nom] + maxRi[nom] + 1);
		}
	}
	for (int i = 0; i < m; i++) printf("%d\n", ans[i]);
	return 0;
}