#include<cstdio>
#include<algorithm>
#include<vector>
#define N 100005

int n,m,ans[N];

int hd[N],_hd;
struct edge{
	int v,nxt;
}e[N<<1];
inline void addedge(int u,int v){
	e[++_hd]=(edge){v,hd[u]};
	hd[u]=_hd;
}

inline void YES(){
	puts("YES");
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	puts("");
}

int deg[N];

inline bool dfs1(int u,int fa,int t){
	if(u==t)
		return 1;
	for(int i=hd[u];i;i=e[i].nxt){
		int v=e[i].v;
		if(v==fa)
			continue;
		if(dfs1(v,u,t)){
			ans[v]=2;
			return 1;
		}
	}
	return 0;
}

std::vector<int> ver[N];
inline void dfs2(int u,int fa,int s){
	if(fa)
		ver[s].push_back(u);
	for(int i=hd[u];i;i=e[i].nxt)
		if(e[i].v!=fa)
			dfs2(e[i].v,u,s);
}
inline bool cmp(int x,int y){
	return ver[x].size()<ver[y].size();
}

namespace SOL{

int n,m;
std::vector<int> V;

inline bool sol(){
	if(m>=n){
		for(auto u:V)
			ans[u]=1;
		YES();
		return 1;
	}
	int x=0,y=0;
	for(auto u:V)
		if(deg[u]>=4){
			ans[u]=2;
			for(int i=hd[u];i;i=e[i].nxt)
				ans[e[i].v]=1;
			YES();
			return 1;
		}
		else if(deg[u]==3){
			y=x;
			x=u;
		}
	if(y){
		for(int i=hd[x];i;i=e[i].nxt)
			ans[e[i].v]=1;
		for(int i=hd[y];i;i=e[i].nxt)
			ans[e[i].v]=1;
		dfs1(x,0,y);
		ans[x]=ans[y]=2;
			YES();
		return 1;
	}
	if(x){
		int p[3],tot=0;
		for(int i=hd[x];i;i=e[i].nxt){
			int v=e[i].v;
			dfs2(v,x,v);
			p[tot++]=v;
		}
		std::sort(p,p+tot,cmp);
		if(ver[p[0]].size()>=2){
			ans[x]=3;
			for(int i=0;i<tot;i++){
				ans[ver[p[i]][0]]=2;
				ans[ver[p[i]][1]]=1;
			}
			YES();
			return 1;
		}
		else if(ver[p[1]].size()>=3){
			ans[x]=4;
			ans[ver[p[0]][0]]=2;
			for(int i=1;i<tot;i++)
				for(int j=0;j<3;j++)
					ans[ver[p[i]][j]]=3-j;
			YES();
			return 1;
		}
		else if(ver[p[1]].size()>=2&&ver[p[2]].size()>=5){
			ans[x]=6;
			ans[ver[p[0]][0]]=3;
			ans[ver[p[1]][0]]=4;
			ans[ver[p[1]][1]]=2;
			for(int i=0;i<5;i++)
				ans[ver[p[2]][i]]=5-i;
			YES();
			return 1;
		}
	}
	return 0;
}

inline void cl(){
	n=m=0;
	V.clear();
}

}

bool vis[N];
inline void dfs(int u){
	vis[u]=1;
	SOL::n++;
	SOL::V.push_back(u);
	for(int i=hd[u];i;i=e[i].nxt){
		int v=e[i].v;
		if(vis[v]){
			SOL::m++;
			continue;
		}
		dfs(v);
	}
}

inline void main_(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		addedge(u,v);
		addedge(v,u);
		deg[u]++;
		deg[v]++;
	}
	bool flg=0;
	for(int i=1;i<=n;i++)
		if(!vis[i]){
			SOL::cl();
			dfs(i);
			if(SOL::sol()){
				flg=1;
				break;
			}
		}
	if(!flg)
		puts("NO");
	_hd=0;
	for(int i=1;i<=n;i++){
		hd[i]=vis[i]=deg[i]=ans[i]=0;
		ver[i].clear();
	}
}

int T;

int main(){
	scanf("%d",&T);
	while(T--)
		main_();
}