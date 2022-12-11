#include <iostream>
#include <set>
#include <vector>
#include <map>
/*#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("section-anchors")
#pragma GCC optimize("profile-values,profile-reorder-functions,tracer")
#pragma GCC optimize("vpt")
#pragma GCC optimize("rename-registers")
#pragma GCC optimize("move-loop-invariants")
#pragma GCC optimize("unswitch-loops")
#pragma GCC optimize("function-sections")
#pragma GCC optimize("data-sections")
#pragma GCC optimize("branch-target-load-optimize")
#pragma GCC optimize("branch-target-load-optimize2")
#pragma GCC optimize("btr-bb-exclusive")*/

using namespace std;

const int MAX_N = 1 << 19;

struct Node{
	vector <pair <int, int>> upd;
	Node() {}
};

struct state{
	int pos, v, fi, se, par, sz;
	state() {}
	state(int pos, int v, int fi, int se, int par, int sz) {
		this->pos = pos;
		this->v = v;
		this->fi = fi;
		this->se = se;
		this->par = par;
		this->sz = sz;
	}
};

Node t[2 * MAX_N];
long long res[2 * MAX_N];

void update(int pos, int l, int r, int a, int b, pair <int, int> add) {
	//if (pos == 1) cout << "! " << a << ' ' << b << ' ' << add.first << ' ' << add.second - MAX_N << endl;
	if (l > b || a > r) return;
	if (a <= l && r <= b) {
		t[pos].upd.push_back(add);
		return;
	}
	int m = (l + r) / 2;
	update(2 * pos, l, m, a, b, add);
	update(2 * pos + 1, m + 1, r, a, b, add);
}

vector <state> st;
int sz[2 * MAX_N], par[2 * MAX_N];
pair <long long, long long> cnt[2 * MAX_N];
long long ans = 0;

int get_par(int v) {
	if (par[v] == v) return v;
	return get_par(par[v]);
}

void merge_t(int pos, int v, int u) {
	v = get_par(v);
	u = get_par(u);
	if (v == u) return;
	ans -= cnt[v].first * cnt[v].second;
	ans -= cnt[u].first * cnt[u].second;
	if (sz[v] > sz[u]) {
		st.push_back(state(pos, u, cnt[u].first, cnt[u].second, u, sz[u]));
		st.push_back(state(pos, v, cnt[v].first, cnt[v].second, v, sz[v]));
		cnt[v].first += cnt[u].first;
		cnt[v].second += cnt[u].second;
		sz[v] += sz[u];
		par[u] = v;
		ans += cnt[v].first * cnt[v].second;
	} else {
		st.push_back(state(pos, u, cnt[u].first, cnt[u].second, u, sz[u]));
		st.push_back(state(pos, v, cnt[v].first, cnt[v].second, v, sz[v]));
		cnt[u].first += cnt[v].first;
		cnt[u].second += cnt[v].second;
		sz[u] += sz[v];
		par[v] = u;
		ans += cnt[u].first * cnt[u].second;
	}
}

void go(int pos, int l, int r) {
	//cout << l << ' ' << r << endl;
	for (pair <int, int> elem : t[pos].upd) merge_t(pos, elem.first, elem.second);
	if (l == r) {
		res[l] = ans;
		while (!st.empty() && st.back().pos == pos) {
			state now = st.back();
			st.pop_back();
			int	v = now.v;
			cnt[v] = {now.fi, now.se};
			sz[v] = now.sz;
			par[v] = now.par;
		}
		return;
	}
	long long cur_ans = ans;
	int m = (l + r) / 2;
	go(2 * pos, l, m);
	ans = cur_ans;
	go(2 * pos + 1, m + 1, r);
	ans = cur_ans;
	while (!st.empty() && st.back().pos == pos) {
		state now = st.back();
		st.pop_back();
		int v = now.v;
		cnt[v] = {now.fi, now.se};
		sz[v] = now.sz;
		par[v] = now.par;
	}
}

pair <int, int> point[MAX_N];

int main() {
	//freopen("Desktop/input.txt", "r", stdin);
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < MAX_N; i++) {
		par[i] = i;
		par[MAX_N + i] = MAX_N + i;
		sz[i] = sz[MAX_N + i] = 1;
		cnt[i] = {1, 0};
		cnt[MAX_N + i] = {0, 1};
	}
	set <pair <int, int>> now;
	map <pair <int, int>, int> to_time;
	for (int i = 1; i <= n; i++) {
		//cout << i << endl;
		int x, y;
		cin >> x >> y;
		y += MAX_N;
		if (now.find({x, y}) != now.end()) {
			now.erase({x, y});
			update(1, 1, MAX_N, to_time[make_pair(x, y)], i - 1, make_pair(x, y));
		} else {
			now.insert({x, y});
			to_time[make_pair(x, y)] = i;
		}
	}
	for (pair <int, int> elem : now) {
		int x = elem.first, y = elem.second;
		update(1, 1, MAX_N, to_time[make_pair(x, y)], n, make_pair(x, y)); 
	}
	go(1, 1, MAX_N);
	for (int i = 1; i <= n; i++) cout << res[i] << ' ';
	cout << endl;
	return 0;
}