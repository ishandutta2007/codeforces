#include <cstdio>
#include <cstring>
#include <algorithm>
#define max_n 5000
#define cs const
using namespace std;
typedef cs int& ci;
struct edge_node{
	int v,nxt;
	edge_node(){}
	edge_node(ci _v,ci _nxt):v(_v),nxt(_nxt){}
};
struct tree{
	int head[max_n+1],cnt;
	edge_node edge[(max_n-1)<<1];
	void build(){
		memset(head,-1,sizeof(head)),cnt=-1;
	}
	void insert(ci u,ci v){
		push(u,v);
		push(v,u);
	}
	void push(ci u,ci v){
		edge[++cnt]=edge_node(v,head[u]);
		head[u]=cnt;
	}
};
tree tr;
int n,lf,mxbl,lcnt[max_n+1],deg[max_n+1];
int f[max_n+1][max_n+1][2],tmp[max_n+1][2];
void dfs2(int u,int fa) {
	if(deg[u]==1){
		f[u][0][0]=f[u][1][1]=0,lcnt[u]=1;
		return;
	}
	bool vis=0;
	for(int i=tr.head[u],v; ~i; i=tr.edge[i].nxt){
		if((v=tr.edge[i].v)==fa)
			continue;
		dfs2(v,u);
		if(!vis)
			for(int k=-1; ++k<=lcnt[v]; f[u][k][0]=min(f[v][k][0],f[v][k][1]+1),f[u][k][1]=min(f[v][k][0]+1,f[v][k][1]));
		else{
			memcpy(tmp,f[u],sizeof(tmp));
			memset(f[u],127,sizeof(f[u]));
			for(int j=-1,ed=min(lcnt[u],mxbl); ++j<=ed; )
				for(int k=-1,ed=min(lcnt[v],mxbl-j); ++k<=ed; f[u][j+k][0]=min(f[u][j+k][0],tmp[j][0]+min(f[v][k][0],f[v][k][1]+1)),f[u][j+k][1]=min(f[u][j+k][1],tmp[j][1]+min(f[v][k][1],f[v][k][0]+1)));
		}
		vis=1;
		lcnt[u]+=lcnt[v];
	}
}
int main() {
	scanf("%d",&n),tr.build();
	for(int i=n,u,v; --i; tr.insert(u,v),++deg[u],++deg[v])
		scanf("%d%d",&u,&v);
	for(int i=0; ++i<=n; lf+=(deg[i]==1));
	memset(f,127,sizeof(f)),mxbl=lf>>1;
	int rt=0;
	while(deg[++rt]==1);
	dfs2(rt,0);
	printf("%d",min(f[rt][mxbl][0],f[rt][mxbl][1]));
	return 0;
}