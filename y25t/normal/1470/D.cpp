#include<cstdio>
#include<algorithm>
#include<vector>
#define N 300005

int T;

int n,m;

int hd[N],_hd;
struct edge{
	int v,nxt;
}e[N<<1];
inline void addedge(int u,int v){
	e[++_hd]=(edge){v,hd[u]};
	hd[u]=_hd;
}

bool vis[N],col[N];
inline void dfs(int u){
	vis[u]=col[u]=1;
	for(int i=hd[u];i;i=e[i].nxt)
		if(vis[e[i].v]&&col[e[i].v])
			col[u]=0;
	for(int i=hd[u];i;i=e[i].nxt)
		if(!vis[e[i].v])
			dfs(e[i].v);
}

std::vector<int> ans;

int main(){
	scanf("%d",&T);
	while(T--){
		for(int i=1;i<=n;i++)
			hd[i]=0;
		_hd=0;
		for(int i=1;i<=n;i++)
			vis[i]=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			addedge(u,v);
			addedge(v,u);
		}
		dfs(1);
		bool flg=1;
		ans.clear();
		for(int i=1;i<=n;i++){
			if(!vis[i])
				flg=0;
			if(col[i])
				ans.push_back(i);
		}
		if(!flg)
			puts("NO");
		else{
			puts("YES");
			printf("%d\n",ans.size());
			for(auto i:ans)
				printf("%d ",i);
			puts("");
		}
	}
}