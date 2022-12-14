#include <cstdio>
#include <cstring>
#define max_n 1000
using namespace std;
struct node{
	int v,w,nxt;
	node(){}
	node(int _v,int _w,int _nxt):v(_v),w(_w),nxt(_nxt){}
};
struct huan{
	int head[max_n+1];
	int cnt;
	node edge[max_n<<1];
	void build(){
		memset(head,-1,sizeof(head));
		cnt=-1;
	}
	void push(int u,int v,int w){
		edge[++cnt]=node(v,w,head[u]);
		head[u]=cnt;
	}
};
huan g;
int main(){
	int n,ans=0,sum=0;
	scanf("%d",&n);
	for(int i=0,u,v,c; ++i<=n; g.push(u,v,0),g.push(v,u,c),sum+=c)
		scanf("%d%d%d",&u,&v,&c);
	++n;
	for(int u=1,p=g.edge[g.head[1]].v; --n; g.edge[g.head[u]].v==p?(p=u,u=g.edge[g.edge[g.head[u]].nxt].v,ans+=g.edge[g.edge[g.head[p]].nxt].w):(p=u,u=g.edge[g.head[u]].v,ans+=g.edge[g.head[p]].w));
	ans<<1>sum&&(ans=sum-ans);
	printf("%d\n",ans);
	return 0;
}