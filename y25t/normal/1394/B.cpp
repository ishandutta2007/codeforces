#include<cstdio>
#include<algorithm>
#include<vector>
#define N 200005
#define K 10

int n,m,k;

std::vector<std::pair<int,int> > e[N];

int flg[N];
bool b[K*K][K*K];
inline int num(int x,int y){
	return x*(x-1)/2+y;
}

std::vector<int> ban[N];

int ans,p[K];
inline void dfs(int x){
	if(x>k){
		for(int i=1;i<=k;i++)
			for(int j=i;j<=k;j++)
				if(b[num(i,p[i])][num(j,p[j])])
					return;
		ans++;
		return;
	}
	for(int i=1;i<=x;i++){
		p[x]=i;
		dfs(x+1);
	}
}

int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		e[u].push_back(std::make_pair(w,v));
	}
	for(int i=1;i<=n;i++){
		std::sort(e[i].begin(),e[i].end());
		int sz=e[i].size();
		for(int j=0;j<sz;j++){
			int v=e[i][j].second;
			ban[v].push_back(num(sz,j+1));
		}
	}
	for(int i=1;i<=n;i++){
		std::sort(ban[i].begin(),ban[i].end());
		int sz=ban[i].size();
		for(int x=1;x<sz;x++)
			if(ban[i][x-1]==ban[i][x])
				b[ban[i][x]][ban[i][x]]=1;
		sz=std::unique(ban[i].begin(),ban[i].end())-ban[i].begin();
		for(int x=0;x<sz;x++)
			for(int y=x+1;y<sz;y++){
				int u=ban[i][x],v=ban[i][y];
				b[u][v]=b[v][u]=1;
			}
	}
	dfs(1);
	printf("%d\n",ans);
}