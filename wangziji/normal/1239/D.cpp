#include <iostream>
#include <stack>
#include <set>
#include <cstring>
#include <stdio.h>
using namespace std;
const int M = 1e6 + 9;
const int N = 1e6 + 9;
struct edge {
	int v, nxt;
}e[M], ne[M];
int p[N], eid;
void add(int u, int v){
	eid++;
	e[eid].v = v, e[eid].nxt = p[u];
	p[u] = eid;
}
int dfn[N], low[N], du[N];
int scc_cnt, times, sccno[N];
set<int> scc[N];
stack<int> s;
void dfs(int u) {
	dfn[u] = low[u] = ++times;
	s.push(u);
	for (int i = p[u]; i; i = e[i].nxt) {
		int v = e[i].v;
		if(dfn[v] == 0) dfs(v), low[u] = min(low[u], low[v]);
		else if (!sccno[v]) low[u] = min(low[u], dfn[v]);
	}
	if (low[u] == dfn[u]) {
		++scc_cnt;
		while(1) {
			int x = s.top(); s.pop();
			sccno[x] = scc_cnt, scc[scc_cnt].insert(x);
			if (x == u) break;
		}
	}
}
int vis[N];
int main() {
	int T;
	cin >> T;
	while(T--)
	{
		int n, m; scanf("%d%d", &n, &m);
		while(!s.empty()) s.pop();eid=times=scc_cnt=0;
		for(int i=1;i<=n;i++) vis[i]=dfn[i]=du[i]=sccno[i]=low[i]=p[i]=0,scc[i].clear();
		for (int i = 0; i < m; ++i) {
			int u, v; scanf("%d%d", &u, &v);
			if(u^v) add(u, v);
		}
		times = scc_cnt = 0;
		for (int i = 1; i <= n; ++i) if (!dfn[i]) dfs(i);
		for(int u = 1; u <= n; ++u) for(int i = p[u]; i; i = e[i].nxt) if(sccno[u] != sccno[e[i].v]) du[sccno[u]]++;
		int ans = 0, sum = 0,flag=0;
		for(int i=1;i<=scc_cnt;i++)
		{
			if(!du[i]&&scc[i].size()!=n)
			{
				puts("Yes");
				cout << scc[i].size() << " " << n-scc[i].size() << endl;
				for(int j:scc[i])
				{
					if(!j) continue;
					vis[j]=1;
					cout << j << " ";
				}
				cout << endl;
				for(int j=1;j<=n;j++)
				{
					if(!vis[j])
						cout << j << " ";
				}
				flag=1;
				break;
			}
		}
		if(!flag) puts("No");
	}
	return 0;
}