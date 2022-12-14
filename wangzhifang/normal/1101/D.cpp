#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstring>
#define INF 2147483647
#define max_n 200000
#define max_m 200000
using namespace std;
struct node{
	int v,nxt;
	node(){}
	node(int _v,int _nxt):v(_v),nxt(_nxt){}
};
struct tree{
	int cnt;
	int head[max_n+1];
	node edge[max_n-1<<1];
	void build(){
		memset(head,-1,sizeof(head)),cnt=-1;
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
int a[max_n+1],dep[max_n+1];
bool vis[max_n+1];
int dfs1(int u,int k,int p=0){
	dep[u]=dep[p]+1,vis[u]=1;
	while(!(a[u]%k))
		a[u]/=k;
	int ret=u;
	for(int i=g.head[u],v=g.edge[i].v,tmp; ~i; v=g.edge[i=g.edge[i].nxt].v)
		!vis[v]&&!(a[v]%k)&&dep[tmp=dfs1(v,k,u)]>dep[ret]&&(ret=tmp);
	return ret;
}
int dfs2(int u){
	vis[u]=0;
	int ret=0;
	for(int i=g.head[u],v=g.edge[i].v,tmp; ~i; v=g.edge[i=g.edge[i].nxt].v)
		vis[v]&&(tmp=dfs2(v))>ret&&(ret=tmp);
	return ret+1;
}
template<typename T>void read(T&x){
	char ch;
	while(!isdigit(ch=getchar()));
	x=ch^'0';
	while(isdigit(ch=getchar()))
		x=x*10+(ch^'0');
}
int prime[max_m],prm[max_m+1],cnt;
bool chkp[max_m+1];
int main(){
	g.build(),dep[0]=0;
	int len,n,m;
	read(n),len=0,m=0,memset(vis,0,sizeof(vis)),memset(chkp,1,sizeof(chkp)),cnt=0,prime[0]=INF;
	for(int i=0; ++i<=n; a[i]>m&&(m=a[i]))
		read(a[i]);
	for(int i=n,u,v; --i; g.insert(u,v))
		read(u),read(v);
	for(int i=1; ++i<=m; ){
		chkp[i]&&(prime[++cnt]=i,prm[i]=i);
		for(int j=0; i%prime[j]&&++j<=cnt&&prime[j]*i<=m; chkp[prime[j]*i]=0,prm[prime[j]*i]=prime[j]);
	}
	for(int i=0,tmp; ++i<=n; )
		for(; a[i]>1; (tmp=dfs2(dfs1(i,prm[a[i]])))>len&&(len=tmp));
	printf("%d\n",len);
	return 0;
}