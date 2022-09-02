#include<set>
#include<cstdio>
#include<vector>
#include<algorithm>
#define pb push_back
#define mp std::make_pair
#define fi first
#define se second
const int N=200005;
typedef std::pair<int,int> pii;
int n,b[N],c[N],d[N],deg[N],ans[N];bool vis[N];std::vector<pii>g[N];
void dfs(int u){
	while((int)g[u].size()>0){
		int i=(int)g[u].size()-1;
		if(!vis[g[u][i].se]){
			vis[g[u][i].se]=1;
			dfs(g[u][i].fi);
		}
		g[u].pop_back();
	}
	ans[++ans[0]]=d[u];
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;++i){
		scanf("%d",b+i);
		d[++*d]=b[i];
	}
	for(int i=1;i<n;++i){
		scanf("%d",c+i);
		d[++*d]=c[i];
		if(b[i]>c[i]){puts("-1");return 0;}
	}
	std::sort(d+1,d+1+*d);
	for(int i=1;i<n;++i){
		int u=std::lower_bound(d+1,d+1+*d,b[i])-d,v=std::lower_bound(d+1,d+1+*d,c[i])-d;
		g[u].pb(mp(v,i)),g[v].pb(mp(u,i));
		++deg[u],++deg[v];
	}
	int tot=0,pos=1;
	for(int i=1;i<=*d;++i){
		if(deg[i]&1){
			++tot;
			pos=i;
		}
	}
	if(tot>0&&tot!=2){
		puts("-1");
		return 0;
	}
	dfs(pos);
	if(ans[0]!=n){return puts("-1"),0;}
	for(int i=1;i<=ans[0];++i)printf("%d ",ans[i]);
	return 0;
}