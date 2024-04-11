#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; a <= i; i--)
#define ll long long
#define fi first
#define se second
using namespace std;

const int N = 555000;

int n, m, p[N], q[N], link[N], cnt;
set<int> all;
map<int, int> e[N];
vector<int> star[N];

bool dfs(int v, int fa) {
	link[v] = v;
	all.erase(v);
	int child = -1, u = 0, have = 0;
	while (1) {
		auto it = all.upper_bound(u);
		if (it == all.end()) break;
		u = *it;
		if (!e[v][u]) {
			if (dfs(u, v)) {
				link[u] = v;
				have = 1;
			}
			else
				child = u;
		}
	}
	if (!have) {
		if (child > 0) {
			if (link[child] == child)
				link[v] = child;
			else
				link[child] = v;
		}
		else if (!fa) 
			p[v] = q[v] = cnt++, link[v] = -1;
		else return 1; 
	}		
	return 0;
}

void solve() {
	cin >> n >> m;
	rep(i, 1, n) all.insert(i);
	rep(i, 1, n) e[i].clear(), star[i].clear();
	rep(i, 1, m) {
		int a, b;
		cin >> a >> b;
		e[a][b] = 1;
		e[b][a] = 1;
	}
	cnt = 1;
	while (!all.empty()) 
		dfs(*all.begin(), 0);
	rep(i, 1, n) if (link[i] > 0 && link[i] != i) star[link[i]].push_back(i);
	rep(i, 1, n) {
		if (link[i] != i) continue;
		p[i] = cnt;
		for (auto x : star[i]) {
			q[x] = cnt;
			p[x] = ++cnt;
		}
		q[i] = cnt++;
	}
	rep(i, 1, n) cout << p[i] << " "; cout << endl;
	rep(i, 1, n) cout << q[i] << " "; cout << endl;
}	
 
int main() {
	int T;
	scanf("%d", &T);
	while (T--) solve();
	return 0;
}