#include <cstdio>
#include <cstring>
#include <algorithm>
#define sizofint(x) ((x)<<2)
#define il __inline__ __attribute__((always_inline))
#define cs const
using namespace std;
template<typename T>void maxify(T&x,cs T&y){
	y>x&&(x=y);
}
typedef cs int& ci;
#define max_n 300000
#define max_lim1 20
//#define max_lim2 8
#define lim1 20
struct node{
	int v,nxt;
	il node(){}
	il node(ci _v,ci _nxt):v(_v),nxt(_nxt){}
};
struct graph{
	int head[max_n+1],cnt;
	node edge[max_n<<1];
	il void build(){
		memset(head,0,sizeof(head)),cnt=0;
	}
	il void insert(ci u,ci v){
		push(u,v);
		push(v,u);
	}
	il void push(ci u,ci v){
		edge[++cnt]=node(v,head[u]);
		head[u]=cnt;
	}
};
graph g;
int dp1[max_n+1][max_lim1+1],dp2[max_n+1][max_lim1+1],
	dp3[max_n+1]/*[max_lim2+1],dp4[max_n+1][max_lim2+1]*/;
int son[max_n+1],tmp[max_n+1];
int n;
long long ans=0;
void dfs(ci u,ci p=0){
	int x=0;
	for(int i=g.head[u],v; i; i=g.edge[i].nxt)
		if((v=g.edge[i].v)!=p){
			dfs(v,u);
			maxify(x,dp3[v]);
		}
	ans+=dp3[u]=x+1;
	int*cnt=son;
	for(int i=g.head[u],v; i; i=g.edge[i].nxt)
		if((v=g.edge[i].v)!=p)
			*++cnt=v;
	dp1[u][1]=dp2[u][1]=n;
	if(cnt==son){
		ans+=n-1;
		memset(dp1[0]+1,0,sizofint(lim1-1));
		memset(dp2[0]+1,0,sizofint(lim1-1));
		return;
	}
//	printf("^%d\n",cnt-son);
	for(int k=1,*i,*tp,kk=1; k<lim1; k=kk,maxify(dp2[u][kk],dp1[u][kk]=tp-i)){
		tp=tmp,++kk;
		for(int*i=son,&t=dp2[u][kk]; ++i<=cnt; *++tp=dp1[*i][k],maxify(t,dp2[*i][kk]));
		sort(tmp+1,tp+1),i=tp;
//		for(int*i=tmp; ++i<=tp; printf("&%d:%d\n",i-tmp,*i));
		for(int*x=tp+1; i>tmp&&x-i<=*i; --i);
	}
	for(int k=1; k<lim1; ++k){
		int x=dp2[u][k],y=dp2[u][k+1];
//		printf("dp %d %d: %d %d\n",u,k,dp1[u][k],dp2[u][k]);
		if(!y)
			y=1;
		ans+=k*(long long)(x-y);
		if(y==1)
			break;
	}
//	printf("*%lld\n",ans);
}
int main(){
	scanf("%d",&n),g.build();
	for(int i=n,u,v; --i; g.insert(u,v))
		scanf("%d%d",&u,&v);
	dfs(1);
	printf("%lld\n",ans);
	return 0;
}