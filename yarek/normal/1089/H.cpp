#include <bits/stdc++.h>
using namespace std;

namespace SAT {

	#define FOR(i,n) for(int i = 0; i < (n); i++)
	#define FORI(i,n) for(int i = 1; i <= (n); i++)
	#define FOREACH(i,t) for(auto i = t.begin(); i != t.end(); ++i)
	#define pb push_back
	#define vi vector < int >
	#define pii pair < int, int >
	#define SZ(x) (int)(x).size()
	#define fi first
	#define se second
	
	const int N = 200007;
	int n, ind[N], low[N], onstack[N], last, n2, t[N];
	vi adj[N], st;
	int mx[N];
	
	void go(int v) {
		ind[v] = low[v] = ++last;
		st.pb(v);
		onstack[v] = 1;
		FOREACH(w, adj[v]) {
			if(!ind[*w]) {
				go(*w);
				low[v] = min(low[v], low[*w]);
			} else if(onstack[*w]) {
				low[v] = min(low[v], low[*w]);
			}
		}
		if(low[v] == ind[v]) {
			++n2;
			for(int w = -1; w != v; ) {
				w = st.back();
				st.pop_back();
				onstack[w] = 0;
				t[w] = n2;
			}
		}
	}
	
	void scc() {
		last = n2 = 0;
		FORI(i, n) ind[i] = onstack[i] = 0;
		FORI(i, n) if(!ind[i]) go(i);
		FORI(i, n) t[i] = n2 + 1 - t[i];
	}
	
	int k, val[N]; vector < pii > clauses; vi adjtr[N];
	
	void dwasat_dfs(int v, bool wart, vi *adja) {
		if(val[v] != -1) return;
		val[v] = wart;
		FOREACH(it, adja[v]) dwasat_dfs(*it, wart, adja);
	}
	
	bool dwasut() {
		n = 2 * k;
		FORI(i, n) adj[i].clear(), adjtr[i].clear();
		FOR(i, SZ(clauses)) {
			int a = clauses[i].fi, b = clauses[i].se;
			if(a < 0) a = n + 1 + a;
			if(b < 0) b = n + 1 + b;
			adj[n + 1 - a].pb(b);
			adj[n + 1 - b].pb(a);
			adjtr[b].pb(n + 1 - a);
			adjtr[a].pb(n + 1 - b);
		}
		scc();
		FORI(i, k) if(t[i] == t[n + 1 - i]) return 0;
		/*FORI(i, n) val[i] = -1;
		FORI(i, k) if(val[i] == -1) {
			int v = (t[i] > t[n + 1 - i]) ? i : n + 1 - i;
			dwasat_dfs(v, 1, adj);
			dwasat_dfs(n + 1 - v, 0, adjtr);
		}*/
		return 1;
	}
	
	void calc_mx() {
		vector<pair<int, int>> vec(n + 1);
		for(int i = 1; i <= n; i++)
			vec[i] = { t[i], i };
		sort(vec.begin(), vec.end());
		reverse(vec.begin(), vec.end());
		for(auto p: vec)
		{
			int v = p.second;
			for(int u: adj[v])
				mx[t[v]] = max(mx[t[v]], mx[t[u]]);
		}
	}
}

const int N = 100002;
char str[N];

void remax(int &a, int b)
{
	a = max(a, b);
}

int main()
{
	srand(163454);
	int test;
	scanf("%d", &test);
	while(test--)
	{
		int n, m;
		scanf("%d %d", &n, &m);
		scanf("%s", str + 1);
		vector<int> all;
		for(int i = 1; i <= n; i++)
			if(str[i] == 'A')
				all.push_back(i);
		int k = all.size();
		auto &cl = SAT::clauses;
		SAT::k = n;
		cl.resize(m);
		bool ok = true;
		for(int i = 0; i < m; i++)
		{
			scanf("%d %d", &cl[i].first, &cl[i].second);
			int a = abs(cl[i].first), b = abs(cl[i].second);
			if(a > b) swap(a, b);
			if(str[a] == 'A' && str[b] == 'A' && cl[i].first != -cl[i].second)
				ok = false;
		}
		if(!ok || !SAT::dwasut())
		{
			puts("FALSE");
			continue;
		}
		fill(SAT::mx, SAT::mx + 2 * n + 1, 0);
		for(int i = 1; i <= n; i++)
		{
			int val = str[i] == 'E' ? 0 : i;
			remax(SAT::mx[SAT::t[i]], val);
			remax(SAT::mx[SAT::t[2*n+1-i]], val);
		}
		SAT::calc_mx();
		for(int i = 1; i <= n; i++)
			if(str[i] == 'E')
			{
				if(SAT::mx[SAT::t[i]] > i)
					cl.push_back({ -i, -i });
				if(SAT::mx[SAT::t[2*n+1-i]] > i)
					cl.push_back({ i, i });
			}
		int t = cl.size();
		cl.resize(t + k);
		for(int i = 0; ok && i < 60; i++)
		{
			for(int j = 0; j < k; j++)
			{
				int x = all[j] * (rand() % 2 * 2 - 1);
				cl[t+j] = { x, x };
			}
			if(!SAT::dwasut()) ok = false;
		}
		puts(ok ? "TRUE" : "FALSE");
	}
}