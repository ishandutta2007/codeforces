#include"bits/stdc++.h"
using namespace std;

const int N=100005;

int n,m,r,s[N],last[N],flag[N];
int h[N],nxt[N*2],to[N*2],val[N*2],tmp;
inline void add(int u,int v,bool c){
	to[++tmp]=v,nxt[tmp]=h[u],h[u]=tmp,val[tmp]=c;
	to[++tmp]=u,nxt[tmp]=h[v],h[v]=tmp,val[tmp]=c;
}

bool vis[N],ans;
void dfs(int x,int mk){
	flag[x] = mk; vis[x] = true;
	for(int i=h[x];i;i=nxt[i])
		if(vis[to[i]]) ans &= flag[to[i]] == (flag[x]^val[i]);
		else dfs (to[i], mk ^ val[i]);
}

int main(){
	int p;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&s[i]);
	for(int i=1;i<=m;i++){
		scanf("%d",&r);
		for(int j=1;j<=r;j++){
			scanf("%d",&p);
			if(last[p]==0)last[p]=i;
			else add(last[p],i,s[p]^1);
		}
	}
	ans=true;
	for(int i=1;i<=m;i++)if(!vis[i])dfs(i,0);
	puts(ans?"YES":"NO");
	return 0;
}