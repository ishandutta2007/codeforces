#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define PB push_back
#define ar2 array<int,2> 
const int N = 5e6+5, N1 = 1e5+5;
 
int x[N1], y[N1], dfn[N], low[N], scc[N];
bool v[N];
char s[N1][50];
int n,m,d,T=0,SCC=0;
vector<int> g[N]; 
stack<int> stk;
 
inline int key(int city,int day){return (city-1)*d+day;}
 
void tarjan(int x){
	stk.push(x);
	dfn[x] = low[x] = ++T;
	v[x] = true;
	for(auto u:g[x]){
		if(!dfn[u]){
			tarjan(u);
			low[x] = min(low[x], low[u]);
		}else if (v[u]) low[x] = min(low[x], low[u]);
	}
	if(low[x] == dfn[x]){
		++SCC;
		while(stk.top()!=x) v[stk.top()] = false, scc[stk.top()] = SCC, stk.pop();
		v[x] = false, scc[x] = SCC, stk.pop();
	}
}
 
int dfs(int x){
	if(~scc[x]) return scc[x];
	int res = 0;
	for(auto u:g[x]) res = max(res, dfs(u));
	return scc[x] = res + dfn[x];
}
 
int main() {
	scanf("%d%d%d",&n,&m,&d);
	rep(i,1,m) scanf("%d%d",x+i,y+i);
	rep(i,1,n) scanf("%s\n",s[i]);
	rep(i,1,m){
		int a = x[i], b = y[i];
		rep(j,0,d-1) g[key(a,j)].PB(key(b,(j+1)%d));
	}
	memset(v,0,sizeof v);
	rep(i,0,n*d-1) if(!dfn[i]) tarjan(i);
	
	memset(low,-1,sizeof low);
	memset(dfn,0,sizeof dfn); 
	rep(i,0,n*d-1) if(s[i/d+1][i%d]=='1' && ( i/d+1>low[scc[i]] )) low[scc[i]] = i/d+1, ++dfn[scc[i]];
	rep(i,0,n*d-1) g[i].clear();
	rep(i,1,m){
		int a = x[i], b = y[i];
		rep(j,0,d-1){
			int q = scc[key(a,j)], w = scc[key(b,(j+1)%d)];
			if(q!=w) g[q].PB(w); 
		}
	}
	int tmp = scc[0];
	memset(scc,-1,sizeof scc);
	cout<<dfs(tmp)<<endl;
}