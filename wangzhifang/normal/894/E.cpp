#include <cmath>
#include <cstdio>
#include <cstring>
#define max_n 1000000
#define max_m 1000000
using namespace std;
typedef const int& ci;
typedef const long long& cll;
struct node{
	int v,w,nxt;
	node(){}
	node(ci _v,ci _w,ci _nxt):v(_v),w(_w),nxt(_nxt){}
};
struct graph{
	int head[max_n+1];
	int cnt;
	node edge[max_m];
	void build(){
		memset(head,-1,sizeof(head)),cnt=-1;
	}
	void push(ci u,ci v,ci w){
		edge[++cnt]=node(v,w,head[u]);
		head[u]=cnt;
	}
};
struct node_{
	int v,nxt;
	long long w;
	node_(){}
	node_(ci _v,cll _w,ci _nxt):v(_v),nxt(_nxt),w(_w){}
};
struct graph_{
	int head[max_n+1];
	int cnt;
	node edge[max_m];
	void build(){
		memset(head,-1,sizeof(head)),cnt=-1;
	}
	void push(ci u,ci v,cll w){
		edge[++cnt]=node(v,w,head[u]);
		head[u]=cnt;
	}
};
graph g1;
graph_ g2;
int gr[max_n+1],gcnt;
int vis[max_n+1];
int stk[max_n+1],top;
int dfn;
int tarjan(ci u){
	if(vis[u])
		return vis[u];
	stk[++top]=u;
	int now=++dfn,&mnn=(vis[u]=now),stp=top;
	for(int i=g1.head[u],v,tmp; ~i; i=g1.edge[i].nxt)
		!gr[v=g1.edge[i].v]&&(tmp=tarjan(v))<mnn&&(mnn=tmp);
	if(mnn==now){
		++gcnt;
		for(++top; --top>=stp; gr[stk[top]]=gcnt);
	}
	return mnn;
}
long long wei[max_n+1];
long long weigh(ci x){
	int u=x<<1,r=sqrt(u);
	r*(r+1)>=u&&(--r);
	return (long long)(r+1)*x-r*(long long)(r+1)*(r+2)/6;
}
bool vss[max_n+1];
long long dfs(ci u){
	if(vss[u])
		return wei[u];
	vss[u]=1;
	long long mxw=0,tmp;
	for(int i=g2.head[u]; ~i; i=g2.edge[i].nxt)
		(tmp=dfs(g2.edge[i].v)+g2.edge[i].w)>mxw&&(mxw=tmp);
	return wei[u]+=mxw;
}
int main(){
	int n,m,s;
	scanf("%d%d",&n,&m),g1.build(),g2.build(),
	memset(gr,0,sizeof(gr)),memset(vis,0,sizeof(vis)),memset(vss,0,sizeof(vss)),top=dfn=gcnt=0;
	for(int i=m+1,u,v,w; --i; g1.push(u,v,w))
		scanf("%d%d%d",&u,&v,&w);
	scanf("%d",&s);
	tarjan(s);
	for(int i=0,v; ++i<=n; )
		if(gr[i])
			for(int j=g1.head[i]; ~j; j=g1.edge[j].nxt)
				gr[v=g1.edge[j].v]&&(gr[i]==gr[v]?wei[gr[i]]+=weigh(g1.edge[j].w):(g2.push(gr[i],gr[v],g1.edge[j].w),1));
	printf("%lld\n",dfs(gr[s]));
	return 0;
}