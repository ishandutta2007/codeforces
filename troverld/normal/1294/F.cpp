#include<bits/stdc++.h>
using namespace std;
int n,head[200100],cnt,dis[200100],U,V,W,res;
struct node{
	int to,next;
}edge[400100];
void ae(int u,int v){
	edge[cnt].next=head[u],edge[cnt].to=v,head[u]=cnt++;
}
void dfs1(int x,int fa){
	for(int i=head[x];i!=-1;i=edge[i].next)if(edge[i].to!=fa)dis[edge[i].to]=dis[x]+1,dfs1(edge[i].to,x);
}
bool on[200100];
bool dfs2(int x,int fa){
	if(x==V){on[x]=true;return true;}
	for(int i=head[x];i!=-1;i=edge[i].next){
		if(edge[i].to==fa)continue;
		if(dfs2(edge[i].to,x)){on[x]=true;return true;}
	}
	return false;
}
void dfs3(int x,int fa){
	for(int i=head[x];i!=-1;i=edge[i].next)if(edge[i].to!=fa&&!on[edge[i].to])dis[edge[i].to]=dis[x]+1,dfs1(edge[i].to,x);	
}
int main(){
	scanf("%d",&n),memset(head,-1,sizeof(head));
	for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),ae(x,y),ae(y,x);
	dis[1]=0,dfs1(1,0);
	for(int i=1;i<=n;i++)if(dis[i]>=dis[U])U=i;
	dis[U]=0,dfs1(U,0);
	for(int i=1;i<=n;i++)if(dis[i]>=dis[V]&&i!=U)V=i;
	res+=dis[V];
	dfs2(U,0);
	for(int i=1;i<=n;i++)if(on[i])dis[i]=0,dfs3(i,0);
	for(int i=1;i<=n;i++)if(dis[i]>=dis[W]&&i!=U&&i!=V)W=i;
	res+=dis[W];
	printf("%d\n%d %d %d\n",res,U,V,W);
	return 0;
}