#include<cstdio>
#include<algorithm>
#include<stack>
#define ll long long
#define N 200005

inline ll gcd(ll x,ll y){
	return y?gcd(y,x%y):x;
}

int n,m,q;

int hd[N],_hd;
struct edge{
	int v,w,nxt;
}e[N];
inline void addedge(int u,int v,int w){
	e[++_hd]=(edge){v,w,hd[u]};
	hd[u]=_hd;
}

int dfn[N],low[N],_dfn,col[N];
std::stack<int> st;
bool vis[N];
inline void dfs1(int u){
	low[u]=dfn[u]=++_dfn;
	vis[u]=1;
	st.push(u);
	for(int i=hd[u];i;i=e[i].nxt){
		int v=e[i].v;
		if(!dfn[v]){
			dfs1(v);
			low[u]=std::min(low[u],low[v]);
		}
		else if(vis[v])
			low[u]=std::min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u])
		while(st.size()){
			int v=st.top();
			st.pop();
			col[v]=u;
			vis[v]=0;
			if(v==u)
				break;
		}
}

ll val[N],sum[N];
inline void dfs2(int u){
	vis[u]=1;
	for(int i=hd[u];i;i=e[i].nxt){
		int v=e[i].v,w=e[i].w;
		if(col[u]!=col[v])
			continue;
		if(vis[v])
			val[col[u]]=gcd(val[col[u]],sum[u]-sum[v]+w);
		else{
			sum[v]=sum[u]+w;
			dfs2(v);
		}
	}
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		addedge(u,v,w);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			dfs1(i);
	for(int i=1;i<=n;i++)
		if(!vis[i])
			dfs2(i);
	scanf("%d",&q);
	while(q--){
		int u,s,t;
		scanf("%d%d%d",&u,&s,&t);
		puts(!s||gcd(t,t-s)%gcd(val[col[u]],t)==0?"YES":"NO");
	}
}