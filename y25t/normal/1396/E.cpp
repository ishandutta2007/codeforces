#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#define pii std::pair<int,int>
#define mp std::make_pair
#define fir first
#define sec second
#define ll long long
#define N 100005

int n;
ll k;

int hd[N],_hd;
struct edge{
	int v,nxt;
}e[N<<1];
inline void addedge(int u,int v){
	e[++_hd]=(edge){v,hd[u]};
	hd[u]=_hd;
}

int sz[N],rt,mx;
inline void fndrt(int u,int fa){
	sz[u]=1;
	int tmp=0;
	for(int i=hd[u];i;i=e[i].nxt){
		int v=e[i].v;
		if(v==fa)
			continue;
		fndrt(v,u);
		sz[u]+=sz[v];
		tmp=std::max(tmp,sz[v]);
	}
	tmp=std::max(tmp,n-sz[u]);
	if(tmp<mx){
		rt=u;
		mx=tmp;
	}
}

std::priority_queue<pii> h;

int fa[N],dep[N];
bool vis[N];
std::vector<int> son[N];
std::set<std::pair<pii,int> > s[N];
inline void dfs(int u,int id){
	dep[u]=dep[fa[u]]+1;
	for(int i=hd[u];i;i=e[i].nxt){
		int v=e[i].v;
		if(v==fa[u])
			continue;
		fa[v]=u;
		son[u].push_back(v);
		dfs(v,id);
	}
	sz[u]=son[u].size();
	s[id].insert(mp(mp(dep[u],sz[u]),u));
}

std::vector<pii> ans;

int main(){
	scanf("%d%lld",&n,&k);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		addedge(u,v);
		addedge(v,u);
	}
	mx=n;
	fndrt(1,0);
	sz[rt]=0;
	for(int i=hd[rt];i;i=e[i].nxt){
		int u=e[i].v;
		fa[u]=rt;
		dfs(u,u);
		h.push(mp(s[u].size(),u));
	}
	ll sum=0;
	for(int i=1;i<=n;i++)
		sum+=dep[i];
	k=sum-k;
	if(k<0||k%2==1){
		puts("NO");
		return 0;
	}
	k/=2;
	int tmp=0;
	while(h.size()&&k){
		int t=h.top().sec;
		tmp++;
		h.pop();
		int d=dep[s[t].rbegin()->sec];
		if(k>=d-1){
			auto it=s[t].lower_bound(mp(mp(d-1,1),0));
			int u=it->sec;
			s[t].erase(it);
			if(sz[u]==1){
				int v=son[u].back();
				son[u].pop_back();
				while(vis[v]){
					v=son[u].back();
					son[u].pop_back();
				}
				if(fa[u]!=rt){
					s[t].erase(mp(mp(dep[fa[u]],sz[fa[u]]),fa[u]));
					sz[fa[u]]--;
					s[t].insert(mp(mp(dep[fa[u]],sz[fa[u]]),fa[u]));
				}
				sz[u]--;
				vis[u]=vis[v]=1;
				s[t].erase(mp(mp(dep[v],sz[v]),v));
				ans.push_back(mp(u,v));
			}
			else{
				int v=son[u].back();
				son[u].pop_back();
				while(vis[v]){
					v=son[u].back();
					son[u].pop_back();
				}
				int w=son[u].back();
				son[u].pop_back();
				while(vis[w]){
					w=son[u].back();
					son[u].pop_back();
				}
				sz[u]-=2;
				vis[v]=vis[w]=1;
				s[t].erase(mp(mp(dep[v],sz[v]),v));
				s[t].erase(mp(mp(dep[w],sz[w]),w));
				s[t].insert(mp(mp(dep[u],sz[u]),u));
				ans.push_back(mp(v,w));
			}
			k-=d-1;
		}
		else{
			auto it=s[t].lower_bound(mp(mp(k,1),0));
			int u=it->sec;
			s[t].erase(it);
			int v=son[u].back();
			son[u].pop_back();
			while(vis[v]){
				v=son[u].back();
				son[u].pop_back();
			}
			if(fa[u]!=rt){
				s[t].erase(mp(mp(dep[fa[u]],sz[fa[u]]),fa[u]));
				sz[fa[u]]--;
				s[t].insert(mp(mp(dep[fa[u]],sz[fa[u]]),fa[u]));
			}
			sz[u]--;
			vis[u]=vis[v]=1;
			s[t].erase(mp(mp(dep[v],sz[v]),v));
			ans.push_back(mp(u,v));
			k=0;
		}
		if(s[t].size())
			h.push(mp(s[t].size(),t));
	}
	while(h.size()>1){
		int u=h.top().sec;
		h.pop();
		int v=h.top().sec;
		h.pop();
		auto it1=s[u].begin(),it2=s[v].begin();
		ans.push_back(mp(it1->sec,it2->sec));
		s[u].erase(it1);
		s[v].erase(it2);
		if(s[u].size())
			h.push(mp(s[u].size(),u));
		if(s[v].size())
			h.push(mp(s[v].size(),v));
	}
	ans.push_back(mp(s[h.top().sec].begin()->sec,rt));
	puts("YES");
	for(auto it=ans.rbegin();it!=ans.rend();it++)
		printf("%d %d\n",it->fir,it->sec);
}