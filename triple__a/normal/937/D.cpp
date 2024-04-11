#include "bits/stdc++.h"
using namespace std;

typedef long long LL;

const int maxn=100007;

struct edge{
	int c;
	int *p;
}e[maxn];

int vis[maxn][3];
int color[maxn];
bool rch[maxn];
bool is_DAG=1;

void dfs(int u,int st){
//	cout<<u<<" "<<st;
	for (int i=1;i<=e[u].c;i++){
		if (!vis[e[u].p[i]][(st+1)%2]){
			vis[e[u].p[i]][(st+1)%2]=u;
			dfs(e[u].p[i],st+1);
		}
	}
}

void find_rch(int u){
	rch[u]=1;
	for (int i=1;i<=e[u].c;++i){
		if (!rch[e[u].p[i]]){
			find_rch(e[u].p[i]);
		}
	}
}

void coloring(int u){
	color[u]=-1;
	for (int i=1;i<=e[u].c;++i){
		if (color[e[u].p[i]]==-1){
			is_DAG=false;
		}
		else{
			if (color[e[u].p[i]]==0)
			coloring(e[u].p[i]);
		}
	}
	color[u]=1;
}

int main(){
	memset(color,0,sizeof(color));
	memset(rch,0,sizeof(rch));
	memset(vis,0,sizeof(vis));
	int n,m,s;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i){
		int c;
		scanf("%d",&c);
		e[i].c=c;
		e[i].p=new int[c+1];
		for (int j=1;j<=c;++j){
			scanf("%d",&e[i].p[j]);
		}
	}
	scanf("%d",&s);
	vis[s][0]=-1;
	dfs(s,0);
	bool fg=false;
	for (int i=1;i<=n;++i){
		if (!e[i].c){
			fg=1;
			if (vis[i][1]){
				printf("Win\n");
				int u=i;
				int z=1,ans[maxn],cnt=0;
				while(u!=-1){
					ans[++cnt]=u;
					u=vis[u][z];
					z=1-z;
				}
				for (int i=cnt;i>0;--i){
					printf("%d ",ans[i]);
				}
				return 0;
			}
		}
	}
	if (fg){
		find_rch(s);
		for (int i=1;i<=n;++i){
			if (rch[i]&&!color[i]){
				coloring(i);
			}
		}
		if (!is_DAG){
			printf("Draw");
		} 
		else{
			printf("Lose");
		}
	}
	else{
		printf("Draw");
	}
	return 0;
}