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
#include <map> 
#include <stack> 
#include <set> 
using namespace std;
#define ll long long
const int maxn=109;
const int maxm=10009;
int n,m,head[maxn],tot;
struct pp{int nxt,to;}g[maxm];
void add(int u,int v){g[++tot].nxt=head[u],g[tot].to=v,head[u]=tot;}
queue<int> q;
ll f[maxn],h[maxn];
int dis1[maxn],vis[maxn],dis2[maxn];
void bfs1(int x){
	while(!q.empty()) q.pop();
	memset(dis1,-1,sizeof(dis1));
	memset(f,0,sizeof(f));
	memset(vis,0,sizeof(vis));
	q.push(x);vis[x]=1,dis1[x]=0,f[x]=1;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=head[u];i!=-1;i=g[i].nxt){
			int v=g[i].to;
			if(dis1[v]==-1||dis1[v]==dis1[u]+1){
				dis1[v]=dis1[u]+1,f[v]+=f[u];
				if(!vis[v]){
					vis[v]=1;
					q.push(v);
				}
			}
		}
	}
}
void bfs2(int x){
	while(!q.empty()) q.pop();
	memset(dis2,-1,sizeof(dis2));
	memset(h,0,sizeof(h));
	memset(vis,0,sizeof(vis));
	q.push(x);vis[x]=1,dis2[x]=0,h[x]=1;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=head[u];i!=-1;i=g[i].nxt){
			int v=g[i].to;
			if(dis2[v]==-1||dis2[v]==dis2[u]+1){
				dis2[v]=dis2[u]+1,h[v]+=h[u];
				if(!vis[v]){
					vis[v]=1;
					q.push(v);
				}
			}
		}
	}
}
int main(){
	memset(f,0,sizeof(f));
	memset(head,-1,sizeof(head));tot=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v;scanf("%d%d",&u,&v);add(u,v);add(v,u);
	}
	bfs1(1);bfs2(n);
	ll sum=f[n];ll ans=0;
	for(int i=1;i<=n;i++)
		if(dis1[i]+dis2[i]==dis1[n]) 
			if(i==1||i==n) ans=max(ans,f[i]*h[i]);
			else ans=max(ans,f[i]*h[i]*2);
	double las=double(ans)/double(sum);
	printf("%.13lf",las);	
	return 0;
}