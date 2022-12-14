#include <cstdio>
#include <cstring>
#include <algorithm>
#define max_n 200000
using namespace std;
struct node{
	int v,nxt;
	node(){}
	node(int _v,int _nxt):v(_v),nxt(_nxt){}
};
struct tree{
	int head[max_n+1];
	int cnt;
	node edge[max_n-1<<1];
	void build(){
		memset(head,-1,sizeof(head)),
		cnt=-1;
	}
	void insert(int u,int v){
		push(u,v);
		push(v,u);
	}
	void push(int u,int v){
		edge[++cnt]=node(v,head[u]);
		head[u]=cnt;
	}
};
tree g;
int d[max_n+1],deg[max_n+1],c[max_n];
void dfs(int u,int lim,int cp=0){
	if(deg[u]>lim){
//		printf("*%d %d\n",u,deg[u]);
		for(int i=g.head[u]; ~i; i=g.edge[i].nxt)
			!c[i>>1]&&(c[i>>1]=1)&&(dfs(g.edge[i].v,lim,1),1);
		return;
	}
	int cnt=0;
	for(int i=g.head[u]; ~i; i=g.edge[i].nxt)
		!c[i>>1]&&(c[i>>1]=((++cnt)==cp?++cnt:cnt))&&(dfs(g.edge[i].v,lim,cnt),1);
}
int main(){
	int n,k;
	scanf("%d%d",&n,&k),g.build();
	for(int i=n,u,v; --i; g.insert(u,v),++d[u],++d[v])
		scanf("%d%d",&u,&v);
	memcpy(deg,d,sizeof(d)),k=n-k;
	nth_element(d+1,d+k,d+n+1),memset(c,0,sizeof(c));
	printf("%d\n",d[k]);
	dfs(1,d[k]);
	for(int i=-1; ++i<n-1; printf("%d ",c[i]));
	return 0;
}