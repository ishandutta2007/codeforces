#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,dep[N],ans[N];
pair<int,int>ed[N];
vector<int>g[N];
int fa[N];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
void unnion(int x,int y){fa[y]=x;}
void init(int x){for(int i=0;i<=x;i++)fa[i]=i;}
void dfs(int x,int f){
	fa[x]=f,dep[x]=dep[f]+1;
	for(int i:g[x]){
		int v=ed[i].first^ed[i].second^x;
		if(v==f)continue;
		dfs(v,x);
	}
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		init(n);
		vector<int>vi;
		for(int i=1;i<=m;++i){
			int u,v;
			scanf("%d%d",&u,&v);
			ed[i]=make_pair(u,v);
			if(find(u)==find(v))vi.push_back(i),ans[i]=0;
			else g[u].push_back(i),g[v].push_back(i),fa[find(u)]=find(v),ans[i]=1;
		}
		if(vi.size()==3){
			int i=vi[0],j=vi[1],k=vi[2];
			vector<int>vec({ed[i].first,ed[i].second,ed[j].first,ed[j].second,ed[k].first,ed[k].second});
			sort(vec.begin(),vec.end());
			if(vec[0]==vec[1]&&vec[2]==vec[3]&&vec[4]==vec[5]){
				dfs(1,0);
				ans[i]=1;
				int x=ed[i].first,y=ed[i].second;
				if(dep[x]<dep[y])swap(x,y);
				y=fa[x];
				for(int p:g[x])if((ed[p].first^ed[p].second^x)==y){ans[p]=0;break;}
			}
		}
		for(int i=1;i<=m;++i)printf("%d",ans[i]);
		puts("");
		for(int i=1;i<=n;++i)g[i].resize(0);
	}
	return 0;
}