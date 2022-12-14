#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define max_n 16
#define max_m 40000
#define INF 2147483647
using namespace std;
struct node{
	int v,nxt;
	node(){}
	node(int _v,int _nxt):v(_v),nxt(_nxt){}
};
struct graph{
	int cnt;
	int head[max_n];
	node edge[max_n*(max_n-1)];
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
graph g;
int a[max_n][max_m+1];
int l1[max_n][max_n];
int l2[max_n][max_n];
bool vis[1<<max_n][max_n][max_n];
template<typename T,typename Tv>void minify(T&x,Tv y){
	y<x&&(x=y);
}
template<typename T,typename Tv>void maxify(T&x,Tv y){
	y>x&&(x=y);
}
int dfs(int s,int u,int now,const int&k,const int&full){
//	printf("dfs %d %d %d\n",s,u,now);
	if(now==full)
		return l2[u][s]>=k;
	if(vis[now][s][u])
		return 0;
	vis[now][s][u]=1;
	for(int i=g.head[u],v=g.edge[i].v; ~i; v=g.edge[i=g.edge[i].nxt].v)
		if(!((1<<v)&now)&&dfs(s,v,now|(1<<v),k,full))
			return 1;
	return 0;
}
bool check(int n,int k){
//	printf("check %d\n",k);
	g.build(),memset(vis,0,sizeof(vis));
	for(int i=-1; ++i<n; )
		for(int j=i; ++j<n; l1[i][j]>=k&&(g.insert(i,j),0));
	for(int i=-1; ++i<n; )
		if(dfs(i,i,1<<i,k,(1<<n)-1))
			return 1;
	return 0;
}
int p[max_n+1];
int randoml(int n){
	int ret=0;
	for(int i=-1; ++i<n; p[i]=i);
	for(int t=10000,tmp; --t; random_shuffle(p,p+n)){
		tmp=l2[p[0]][p[n-1]];
		for(int i=0; ++i<n; minify(tmp,l1[p[i-1]][p[i]]));
		maxify(ret,tmp);
	}
	return ret;
}
int randomr(int n){
	int maxl1=0;
	for(int i=-1; ++i<n; )
		for(int j=i; ++j<n; maxify(maxl1,l1[i][j]));
	return maxl1;
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=-1; ++i<n; )
		for(int j=0; ++j<=m; scanf("%d",a[i]+j));
	if(n==1){
		int ans=INF;
		for(int i=0; ++i<m; minify(ans,abs(a[0][i+1]-a[0][i])));
		printf("%d\n",ans);
		return 0;
	}
	memset(l1,127,sizeof(l1)),
	memset(l2,127,sizeof(l2));
	for(int i=-1; ++i<n; ){
		for(int j=-1; ++j<=i; l1[i][j]=l1[j][i])
			for(int k=0; ++k<m; minify(l2[i][j],abs(a[i][k]-a[j][k+1])));
		for(int j=i; ++j<n; minify(l1[i][j],abs(a[i][m]-a[j][m])))
			for(int k=0; ++k<m; minify(l1[i][j],abs(a[i][k]-a[j][k])),minify(l2[i][j],abs(a[i][k]-a[j][k+1])));
	}
	int l=randoml(n),r=randomr(n)+1,mid;
	while(l+1<r)
		if(check(n,mid=l+r>>1))
			l=mid;
		else
			r=mid;
	printf("%d\n",l);
	return 0;
}
/*
input:
1 3
1 10 1
output:
9
*/