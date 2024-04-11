#include<bits/stdc++.h>
#define N 100005

int n;

inline int query(int x){
	printf("? %d\n",x);
	fflush(stdout);
	int res;
	scanf("%d",&res);
	return res;
}

std::vector<int> E[N];

int f[N],g[N],fa[N];
std::vector<int> V[N];
inline void dfs(int u){
	f[u]=g[u]=0;
	V[u].clear();
	for(auto v:E[u]) if(v!=fa[u]){
		fa[v]=u;
		dfs(v);
		V[u].push_back(v);
	}
	std::sort(V[u].begin(),V[u].end(),[&](int i,int j){
		return f[i]>f[j];
	});
	for(int i=0;i<(int)V[u].size();i++)
		f[u]=std::max(f[u],f[V[u][i]]+i);
	f[u]=std::max(f[u],(int)V[u].size());
	g[u]=V[u].size()?g[V[u][0]]:u;
}

int F[N],ans;
inline void dfs2(int u){
	auto U=V[u];
	if(fa[u]){
		U.push_back(fa[u]);
		for(int i=0;i<(int)V[u].size();i++)
			if(f[V[u][i]]<F[u]){
				for(int j=(int)U.size()-1;j>i;j--)
					U[j]=U[j-1];
				U[i]=fa[u];
				break;
			}
	}
	std::vector<int> mx;
	for(int i=0;i<(int)U.size();i++)
		mx.push_back(i+(U[i]==fa[u]?F[u]:f[U[i]]));
	mx.push_back(U.size());
	for(int i=mx.size()-2;i>=0;i--)
		mx[i]=std::max(mx[i],mx[i+1]);
	int tmp=0;
	for(int i=0;i<(int)U.size();i++){
		int v=U[i];
		if(v!=fa[u]){
			F[v]=std::max(tmp,mx[i+1]-1);
			dfs2(v);
		}
		tmp=std::max(tmp,i+(v==fa[u]?F[u]:f[v]));
	}
	int a=0,b=0;
	for(auto v:U){
		int val=v==fa[u]?F[u]:f[v];
		b=std::max(b,a+val);
		a=std::max(a+1,val);
	}
	ans=std::max(ans,std::max(a,b));
}

bool vis[N];
inline int qry(int u,int x){
	while(x!=u)
		vis[x]=1,x=fa[x];
	for(auto v:V[u]) if(!vis[v]){
		int xx=query(g[v]);
		if(xx!=u)
			return qry(xx,g[v]);
	}
	return u;
}

inline void sol(int u){
	memset(vis,0,sizeof(vis));
	fa[u]=0,dfs(u);
	std::vector<int> res;
	for(auto v:V[u]){
		int x=query(g[v]);
		if(x!=u){
			res.push_back(qry(x,g[v]));
			if(res.size()==2)
				break;
		}
	}
	while(res.size()<2)
		res.push_back(u);
	printf("! %d %d\n",res[0],res[1]);
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		E[u].push_back(v),E[v].push_back(u);
	}
	dfs(1),dfs2(1);
	printf("%d\n",ans);
	fflush(stdout);
	int x;
	scanf("%d",&x);
	sol(x);
}