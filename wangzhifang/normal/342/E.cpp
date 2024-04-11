#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <utility>
#include <algorithm>
#include <functional>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
typedef cs int& ci;
#define INF 2147483647
#define max_n 100000
vector<int>g[max_n+1];
int dep[max_n+1],euler[max_n<<1],cnt,rid[max_n+1];
void dfs(ci u,ci p=0){
	dep[u]=dep[p]+1,rid[u]=cnt+1;
	for(int v:g[u])
		if(v!=p){
			euler[++cnt]=u;
			dfs(v,u);
		}
	euler[++cnt]=u;
}
int mn[max_n<<1][20];
il int dis(ci u,ci v){
	int l=rid[u],r=rid[v];
	if(l>r)
		swap(l,r);
	int k=31-__builtin_clz(r-l+1);
	l=mn[l][k],r=mn[r-(1<<k)+1][k];
	int lca=dep[l]<=dep[r]?l:r;
	return dep[u]+dep[v]-2*dep[lca];
}
struct heap{
	priority_queue<int,vector<int>,greater<int> >que1,que2;
	il void flush(){
		while(!que1.empty()&&!que2.empty()&&que1.top()==que2.top())
			que1.pop(),que2.pop();
	}
	il bool empty(){
		flush();
		return que1.empty();
	}
	il void push(ci val){
		que1.push(val);
	}
	il void erase(ci val){
		que2.push(val);
	}
	il int top(){
		flush();
		return que1.top();
	}
	il void pop(){
		flush();
		que1.pop();
	}
};
heap hp[max_n+1];
int siz[max_n+1],all,root,par[max_n+1];
bool vis[max_n+1];
void findrt(ci u,ci p=0){
//	printf("dfs %d %d\n",u,p);
	siz[u]=1;
	int hsu=0;
	for(int v:g[u])
		if(!vis[v]&&v!=p){
			findrt(v,u);
			siz[u]+=siz[v],siz[v]>hsu&&(hsu=siz[v]);
		}
	hsu=max(hsu,all-siz[u]);
//	printf("%d: %d %d\n",u,siz[u],hsu);
	if(hsu<=all/2)
		root=u;
}
void divide(int u){
//	printf("divide %d\n",u);
	vis[u]=1;
	int totsiz=all;
	for(int v:g[u])
		if(!vis[v]){
//			printf("(%d,%d)\n",u,v);
			all=siz[v]>siz[u]?totsiz-siz[u]:siz[v];
//			printf(" (%d,%d)\n",u,all);
			findrt(v);
//			printf("(%d,%d)\n",u,root);
			par[root]=u;
			divide(root);
		}
}
bool flg[max_n+1];
il int query(ci u){
	int ans=INF;
	for(int v=u; v; v=par[v])
		if(!hp[v].empty())
			ans=min(ans,dis(u,v)+hp[v].top());
	return ans;
}
int main(){
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1; i<=n; ++i)
		g[i].clear();
	for(int i=n,u,v; --i; g[u].push_back(v),g[v].push_back(u))
		scanf("%d%d",&u,&v);
	dep[0]=1,cnt=0;
	dfs(1,0);
	for(int i=1; i<=cnt; ++i)
		mn[i][0]=euler[i];
	for(int j=1,d=2; d<=cnt; ++j,d<<=1)
		for(int i=1; i+d-1<=cnt; ++i)
			mn[i][j]=dep[mn[i][j-1]]<dep[mn[i+(d>>1)][j-1]]?mn[i][j-1]:mn[i+(d>>1)][j-1];
	all=n;
	memset(vis,0,sizeof(vis));
	findrt(1);
	par[root]=0;
	divide(root);
//	for(int i=1; i<=n; ++i)
//		printf("%d: %d\n",i,father[i]);
	for(int v=1; v; v=par[v])
		hp[v].push(dis(1,v));
	for(int op,u; q; --q){
		scanf("%d%d",&op,&u);
		if(op==2)
			printf("%d\n",query(u));
		else{
			for(int v=u; v; v=par[v])
				hp[v].push(dis(u,v));
		}
	}
	return 0;
}