#include<bits/stdc++.h>
#define N 100005
 
int n,m[2];
 
int hd[N],_hd;
struct edge{
	int v,w,nxt;
}e[N<<2];
inline void addedge(int u,int v,int w){
	e[++_hd]=(edge){v,w,hd[u]};
	hd[u]=_hd;
}
 
bool vis[N];
std::vector<int> q;
inline void dfs(int u,int tp){
	if(vis[u])
		return;
	vis[u]=1;
	q.push_back(u);
	for(int i=hd[u];i;i=e[i].nxt){
		int v=e[i].v,w=e[i].w;
		if(w!=tp)
			continue;
		dfs(v,tp);
	}
}
 
std::vector<int> s[N],t[N];
 
int col[N],b[N];
bool flg[N];
 
std::vector<int> p,a;
 
std::vector<std::pair<int,int>> ans;
 
int main(){
	scanf("%d%d%d",&n,&m[0],&m[1]);
	for(int o=0;o<2;o++)
		for(int i=1;i<=m[o];i++){
			int u,v;
			scanf("%d%d",&u,&v);
			addedge(u,v,o);
			addedge(v,u,o);
		}
	int x=0,y=0;
	for(int i=1;i<=n;i++)
		if(!vis[i]){
			q.clear();
			dfs(i,0);
			s[++x]=q;
		}
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)
		if(!vis[i]){
			q.clear();
			dfs(i,1);
			t[++y]=q;
		}
	if(x>y){
		std::swap(x,y);
		std::swap(s,t);
	}
	for(int i=1;i<=y;i++)
		for(auto u:t[i])
			col[u]=i;
	for(int i=1;i<=x;i++){
		for(auto u:s[i])
			if(!b[col[u]]){
				flg[i]=1;
				b[col[u]]=u;
				p.push_back(u);
				break;
			}
	}
	for(int i=1;i<=x;i++)
		for(auto u:s[i])
			if(!b[col[u]]){
				b[col[u]]=u;
				a.push_back(u);
			}
	for(int i=1;i<=x;i++)
		if(!flg[i]){
			ans.push_back({s[i][0],a.back()});
			a.pop_back();
		}
	for(int i=0;i<p.size()-1;i++)
		ans.push_back({p[i],p[i+1]});
	printf("%d\n",ans.size());
	for(auto [u,v]:ans)
		printf("%d %d\n",u,v);
}