#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
#define gao(x) cerr << #x << " " << x << "\n"
#define pb push_back
#define sz(x) (int)x.size()
#define fi first
#define se second
#define ll long long
 
using namespace std;

const int N = 1 << 20;

int t, n, a[N], in[N], out[N], id[N], tim, res;
vector<int> e[N];
set<int> T;

void dfs(int v) {
	in[v] = ++tim;
	id[tim] = v;
	for (auto u : e[v])
		dfs(u);
	out[v] = tim;
}	

void solve(int v) {
	int del = -1;
	auto it = T.lower_bound(in[v]);
	if (it == T.end() || *it > out[v]) {
		if (it != T.begin()) {
			it--;
			if (in[v] <= out[id[*it]]) {
				del = *it;
				T.erase(it);
			}
		}
		T.insert(in[v]);
	}
	res = max(res, sz(T));
	for (auto u : e[v])
		solve(u);
	if (T.count(in[v])) {
		T.erase(in[v]);
		if (del != -1)
			T.insert(del);
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin >> t;
	while (t--) {
		cin >> n;
		rep(i, 1, n) e[i].clear();
		rep(i, 2, n) cin >> a[i];
		rep(i, 2, n) {
			int p;
			cin >> p;
			e[p].pb(i);
		}
		dfs(1);
		rep(i, 1, n) e[i].clear();
		rep(i, 2, n) e[a[i]].pb(i);
		res = 0;
		solve(1);
		cout << res << "\n";
	}
	
	return 0;
}