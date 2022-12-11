#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int t,n,fa[N];
bool tp[N],vis[N],pd;
struct edge{
	int to,nxt;
};
edge ed[N<<1];
int cnt,h[N],deg[N];
void add(int st,int et){
	deg[st]++;
	cnt++;
	ed[cnt].to=et;
	ed[cnt].nxt=h[st];
	h[st]=cnt;
}
void solve(int u){
	vector<int>vec[2];
	for(int i=h[u];i;i=ed[i].nxt){
		int v=ed[i].to;
		if(v!=fa[u])vec[tp[v]].push_back(v);
		else vec[tp[u]].push_back(u);
	}
	int si=deg[u],now=deg[u]%2;
	for(int i=0;i<si;i++){
		int val=vec[now].back();
		if(val==u)printf("%d %d\n",u,fa[u]);
		else solve(val);
		vec[now].pop_back();
		now=1-now;
	}
}
void dfs(int u){
	int ct1=0,ct2=0;
	for(int i=h[u];i;i=ed[i].nxt){
		int v=ed[i].to;
		if(v==fa[u])continue;
		fa[v]=u;
		dfs(v);
		tp[v]?ct2++:ct1++;
	}
	if(u!=1)(tp[u]=(ct1>=ct2))?ct2++:ct1++;
	if(ct2-ct1<0||ct2-ct1>1)pd=1;
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<n;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			add(x,y);
			add(y,x);
		}
		dfs(1);
		if(pd)puts("NO");
		else puts("YES"),solve(1);
		cnt=0;
		pd=0;
		for(int i=1;i<=n;i++){
			h[i]=0;
			deg[i]=0;
		}
	}
	return 0;
}