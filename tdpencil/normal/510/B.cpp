	#include <bits/stdc++.h>
	using namespace std;

	using ll = long long;
	#define rep(i, a, b) for(int i = a; i < (b); ++i)
	#define all(x) begin(x), end(x)
	#define sz(x) (int)(x).size()
	#define f first
	#define s second
	typedef long long ll;
	typedef pair<int, int> pii;
	typedef vector<int> vi;

	string g[50];
	int n, m;
	bool allsamecolor(pii s, pii st) {
		char c = g[s.f][s.s];    
		for(int i = s.f; i <= st.f; ++i) {
		    for(int j = s.s; j <= st.s; ++j) {
		        if(i > s.f && j > s.s && i < st.f && j < st.f)
		            continue;
		        if(g[i][j] != c)
		            return 0;
		    }
		}
		return 1;
	}

	set<pii> adj[50][50];

	char colors[50][50];
	bool dfs(pii cur, pii par={-1, -1}) {
		colors[cur.f][cur.s] = 1;
		bool w = 0;
		for(auto e : adj[cur.f][cur.s]) {
		    if(e == par)
		        continue;
		    if(colors[e.f][e.s] == 0) {
		        w |= dfs(e, cur);
		    } else if(colors[e.f][e.s] == 1) {
		        w = 1;
		    }
		}
		colors[cur.f][cur.s] = 2;
		return w;
	}
	int main() {
		// first brute force over every rectangle    

		cin >> n >> m;
		for(int i = 0; i < n; ++i)
		    cin >> g[i];
		bool works = 0;
		for(int i = 0; i < n; ++i) {
		    for(int j = 0; j < m; ++j) {
		        if(i) {
		            if(g[i][j]==g[i-1][j])
		                adj[i][j].insert({i-1, j}), adj[i-1][j].insert({i, j});
		        }
		        if(j) {
		            if(g[i][j]==g[i][j-1])
		                adj[i][j].insert({i, j-1}), adj[i][j-1].insert({i, j});
		        }
		        if(i<n-1) {
		            if(g[i][j]==g[i+1][j])
		                adj[i][j].insert({i + 1, j}), adj[i+1][j].insert({i, j});
		        }
		        if(j<m-1) {
		            if(g[i][j]==g[i][j+1])
		                adj[i][j].insert({i, j+1}), adj[i][j+1].insert({i, j});
		        }
		    }
		}
		for(int i = 0; i < n; ++i) {
		    for(int j = 0; j < m; ++j) {
		        if(colors[i][j] == 2)
		            continue;
		        works |= dfs({i, j});
		    }
		}
		cout << (works ? "Yes\n" : "No\n");
	}