#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

const int MN = 100000 + 10;

int N,M,par[21][MN],de[MN],n[MN],l[MN],r[MN],tt;

vector<int>g[MN],v[MN];

void dfs(int x,int d){
	n[x]=++tt;
	l[x]=tt;
	de[x]=d;
	for (int i=0;i<v[x].size();i++)dfs(v[x][i],d+1);
	r[x]=tt;
}

int main(){
//    freopen("input","r",stdin);
    scanf("%d",&N);
    int i,j,x,y;
	for (i=1;i<=N;i++){
		scanf("%d",&par[0][i]);
		v[par[0][i]].push_back(i);
	}
	dfs(0,0);
	for (i=1;i<20;i++)for(j=0;j<=N;j++){
	    if (!par[i-1][j]){
	        par[i][j]=0;
        }
        else{
            par[i][j]=par[i-1][par[i-1][j]];
        }
	}
	for (i=0;i<=N;i++)g[de[i]].push_back(n[i]);
	for (i=0;i<=N+1;i++)if (g[i].size())sort(g[i].begin(),g[i].end());
	scanf("%d",&M);
	for (i=0;i<M;i++){
        scanf("%d%d",&x,&y);
		if (de[x]<=y){
			printf("0 ");
			continue;
		}
		int p=x;
		for (j=19;j>=0;j--)if (y&(1<<j))p=par[j][p];
		int ans=upper_bound(g[de[x]].begin(),g[de[x]].end(),r[p])-lower_bound(g[de[x]].begin(),g[de[x]].end(),l[p]);
		printf("%d ",ans-1);
	}
	return 0;
}