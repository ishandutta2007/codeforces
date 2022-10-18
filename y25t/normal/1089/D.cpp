#include<bits/stdc++.h>
#define ll long long
#define N 100005

int n,m;

std::vector<int> E[N],T[N];

#define W 20
int dfn[N],_dfn,f[N][W],dep[N];
inline void dfs(int u){
	dfn[u]=++_dfn;
	for(int i=1;i<W;i++)
		f[u][i]=f[f[u][i-1]][i-1];
	dep[u]=dep[f[u][0]]+1;
	for(auto v:E[u]) if(!dfn[v]){
		f[v][0]=u;
		T[u].push_back(v);
		dfs(v);
	}
}
inline int lca(int u,int v){
	if(dep[u]<dep[v])
		std::swap(u,v);
	for(int i=W-1;~i;i--)
		if(dep[f[u][i]]>dep[v])
			u=f[u][i];
	if(dep[u]>dep[v])
		u=f[u][0];
	for(int i=W-1;~i;i--)
		if(f[u][i]!=f[v][i])
			u=f[u][i],v=f[v][i];
	return u==v?u:f[u][0];
}

std::vector<int> V;
int t,id[N],dis[44<<2][N];
inline void init(){
	V.push_back(1);
	auto cmp=[&](int u,int v)->bool{
		return dfn[u]<dfn[v];
	};
	std::sort(V.begin(),V.end(),cmp),V.erase(std::unique(V.begin(),V.end()),V.end());
	t=V.size();
	for(int i=1;i<t;i++)
		V.push_back(lca(V[i],V[i-1]));
	std::sort(V.begin(),V.end(),cmp),V.erase(std::unique(V.begin(),V.end()),V.end());
	t=V.size();
	for(int i=0;i<t;i++)
		id[V[i]]=i+1;
}

inline void bfs(int o,int s){
	std::queue<int> q;
	for(int i=1;i<=n;i++)
		dis[o][i]=N;
	dis[o][s]=0,q.push(s);
	while(q.size()){
		int u=q.front();
		q.pop();
		for(auto v:E[u])
			if(dis[o][v]>dis[o][u]+1)
				dis[o][v]=dis[o][u]+1,q.push(v);
	}
}

ll ans;

int F[N],G[N],sz[N];
std::vector<int> l[N],c[N];
std::vector<ll> s[N];
inline void Dfs1(int u){
	if(id[u]){
		G[u]=u;
		for(int v=f[u][0];v&&!id[v];v=f[v][0])
			l[u].push_back(v);
	}
	for(auto v:T[u]){
		Dfs1(v);
		if(!G[v])
			sz[u]+=sz[v];
		else if(!id[u])
			G[u]=G[v];
	}
	if(!G[u])
		sz[u]++;
}
inline void Dfs2(int u){
	for(auto v:T[u])
		F[v]=G[u]?u:F[u],Dfs2(v);
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		E[u].push_back(v),E[v].push_back(u);
	}
	dfs(1);
	for(int u=1;u<=n;u++)
		for(auto v:E[u])
			if(f[v][0]!=u&&f[u][0]!=v)
				V.push_back(u),V.push_back(v);
	init();
	Dfs1(1),Dfs2(1);
	for(int u=1;u<=n;u++) if(!G[u]){
		int v=F[u];
		ans+=1ll*(dep[u]-dep[v])*(n-sz[v])<<1;
		ans+=1ll*sz[u]*(sz[v]-sz[u])<<1;
	}
	for(int o=1;o<=t;o++){
		int v=V[o-1];
		bfs(o,v);
		for(int u=1;u<=n;u++) if(G[u])
			ans+=1ll*(sz[v]+1)*(sz[u]+1)*dis[o][u];
		if(!l[v].size())
			continue;
		int tmp=l[v].size();
		s[v].resize(tmp),c[v].resize(tmp);
		for(int i=0;i<tmp;i++){
			c[v][i]=(i?c[v][i-1]:0)+sz[l[v][i]]+1;
			s[v][i]=(i?s[v][i-1]:0)+1ll*i*(sz[l[v][i]]+1);
		}
		int x=tmp+1+dis[o][f[l[v].back()][0]];
		for(int i=1;i<tmp;i++){
			int j=std::max(0,i-(x>>1));
			ll ss=j?s[v][j-1]:0;
			int cc=j?c[v][j-1]:0;
			ans+=1ll*(sz[l[v][i]]+1)*(-(s[v][i]-ss)+1ll*i*(c[v][i]-cc)+ss+1ll*(x-i)*cc)<<1;
		}
	}
	for(int u=1;u<=n;u++) if(!id[u]&&G[u])
		for(int o=1;o<=t;o++){
			int v=V[o-1];
			ans+=1ll*(sz[v]+1)*(sz[u]+1)*dis[o][u];
			if(l[v].size()&&G[u]!=v){
				int x=dis[o][u],y=dis[id[f[l[v].back()][0]]][u];
				int tmp=l[v].size();
				int i=std::min(tmp-1,std::max(-1,(y+tmp-x-1)>>1));
				ll ss=~i?s[v][i]:0;
				int cc=~i?c[v][i]:0;
				ans+=1ll*(sz[u]+1)*(1ll*(x+1)*cc+ss+1ll*(y+tmp)*(c[v].back()-cc)-(s[v].back()-ss));
			}
		}
	printf("%lld\n",ans>>1);
}