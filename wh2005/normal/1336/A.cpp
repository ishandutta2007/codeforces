#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <deque>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
using namespace std;
#define ll long long
int n,k;
int head[200009],tot;
struct pp{int nxt,to;}g[400009];
void add(int u,int v){g[++tot].nxt=head[u],g[tot].to=v,head[u]=tot;}
int d[200009],siz[200009];
void dfs(int u,int fa){
	d[u]=d[fa]+1,siz[u]=1;
	for(int i=head[u];i!=-1;i=g[i].nxt){
		int v=g[i].to;if(v==fa) continue;dfs(v,u);siz[u]+=siz[v];
	}
}
priority_queue<int >q;
int main() {
	memset(head,-1,sizeof(head));tot=0;+
	scanf("%d%d",&n,&k);
	for(int i=1;i<n;i++){int u,v;scanf("%d%d",&u,&v);add(u,v);add(v,u);}
	d[1]=0;dfs(1,1);
	for(int i=1;i<=n;i++) q.push(d[i]-siz[i]);
	ll ans=0;
	for(int i=1;i<=k;i++){ans+=q.top();q.pop();}
	printf("%lld\n",ans);
	return 0;
}