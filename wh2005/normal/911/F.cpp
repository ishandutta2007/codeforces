#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <string>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
#define ll long long
int n,head[200009],tot;
struct pp{int nxt,to;}g[400009];
void add(int u,int v){g[++tot].nxt=head[u],g[tot].to=v,head[u]=tot;}
int t[200009][2],w[200009][2];
int f[200009][21];
ll d[200009];
void dfs(int u,int fa){
	d[u]=d[fa]+1,f[u][0]=fa;
	w[u][0]=u,w[u][1]=u;
	for(int i=head[u];i!=-1;i=g[i].nxt){
		int v=g[i].to;
		if(v==fa) continue;
		dfs(v,u);
		if(t[v][0]+1>t[u][0]) t[u][1]=t[u][0],t[u][0]=t[v][0]+1,w[u][1]=w[u][0],w[u][0]=w[v][0];
		else if(t[v][0]+1>t[u][1]) t[u][1]=t[v][0]+1,w[u][1]=w[v][0];
	}
}
int lca(int a,int b){
	if(d[a]<d[b]) swap(a,b);
	for(int i=20;i>=0;i--)
		if(d[f[a][i]]>=d[b]) a=f[a][i];
	if(a==b) return a;
	for(int i=20;i>=0;i--)
		if(f[a][i]!=f[b][i]) a=f[a][i],b=f[b][i];
	return f[a][0];		
}
ll dis(int a,int b){
	return d[a]+d[b]-2*d[lca(a,b)];
}
int x,y,ansx[200009],ansy[200009],ansc[200009],top;
ll ans;
int vis[200009];
void flag(int u,int v){
	while(u!=v){
		vis[u]=1;
		u=f[u][0];
	}
	vis[v]=1;
	return ;
}
void Dfs(int u,int fa){
	for(int i=head[u];i!=-1;i=g[i].nxt){
		int v=g[i].to;
		if(v==fa) continue;
		Dfs(v,u);
	}
	if(!vis[u]){
		if(dis(u,x)>dis(u,y)){
			ansx[++top]=u,ansy[top]=x,ansc[top]=u,ans+=dis(u,x);
		}
		else{
			ansx[++top]=u,ansy[top]=y,ansc[top]=u,ans+=dis(u,y);
		} 
	}
}

int main(){
	memset(f,0,sizeof(f));
	memset(head,-1,sizeof(head));tot=0;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);add(v,u);
	}
	d[1]=0;
	dfs(1,1);
	int sum=0;
	for(int i=1;i<=n;i++){
		if(t[i][0]+t[i][1]>sum) sum=t[i][0]+t[i][1],x=w[i][0],y=w[i][1];
	}
	for(int j=1;j<=20;j++){
		for(int i=1;i<=n;i++) f[i][j]=f[f[i][j-1]][j-1];
	}
	memset(vis,0,sizeof(vis));
	int p=lca(x,y);
	top=0,ans=0;
	flag(x,p);flag(y,p);
	Dfs(p,p);
	while(x!=p){
		ansx[++top]=x,ansy[top]=y,ansc[top]=x,ans+=dis(x,y);
		x=f[x][0];
	}
	while(y!=p){
		ansx[++top]=x,ansy[top]=y,ansc[top]=y,ans+=dis(x,y);
		y=f[y][0];
	}
	printf("%lld\n",ans);
	for(int i=1;i<=top;i++) printf("%d %d %d\n",ansx[i],ansy[i],ansc[i]);
	return 0;
}
/*

1.k
kk
 
2.*/