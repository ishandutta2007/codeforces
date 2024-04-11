#include<cstdio>
#include<vector>
#define pii std::pair<int,int>
#define sec second
#define fir first
#define mpii std::make_pair
#define N 500005
#define M 1000005

int T;

int n,m;

int hd[N],_hd;
struct edge{
	int v,nxt;
}e[M<<1];
inline void addedge(int u,int v){
	e[++_hd]=(edge){v,hd[u]};
	hd[u]=_hd;
}

int fa[N],dep[N];
std::vector<int> a[N];
inline void dfs(int u){
	dep[u]=dep[fa[u]]+1;
	a[dep[u]].push_back(u);
	for(int i=hd[u];i;i=e[i].nxt){
		int v=e[i].v;
		if(dep[v])
			continue;
		fa[v]=u;
		dfs(v);
	}
}

std::vector<pii> ans;

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			hd[i]=0;
		_hd=0;
		for(int i=1;i<=m;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			addedge(u,v);
			addedge(v,u);
		}
		for(int i=1;i<=n;i++){
			fa[i]=dep[i]=0;
			a[i].clear();
		}
		dfs(1);
		bool flg=0;
		for(int i=1;i<=n;i++)
			if(dep[i]>=(n-1)/2+1){
				flg=1;
				puts("PATH");
				printf("%d\n",dep[i]);
				for(int u=i;u;u=fa[u])
					printf("%d ",u);
				puts("");
				break;
			}
		ans.clear();
		if(!flg){
			puts("PAIRING");
			for(int i=1;i<=n;i++)
				for(int j=0;j+1<a[i].size();j+=2)
					ans.push_back(mpii(a[i][j],a[i][j+1]));
			printf("%d\n",ans.size());
			for(std::vector<pii>::iterator it=ans.begin();it!=ans.end();it++)
				printf("%d %d\n",it->fir,it->sec);
		}
	}
}