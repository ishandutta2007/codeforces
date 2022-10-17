#include<stdio.h>
#include<vector>
using namespace std;
const int maxn=200005;
int T,n,m;
int vis[maxn];
vector<int>v[maxn],c[2];
void dfs(int x,int k){
	vis[x]=1,c[k].push_back(x);
	for(int i=0;i<v[x].size();i++)
		if(vis[v[x][i]]==0)
			dfs(v[x][i],k^1);
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1,x,y;i<=m;i++)
			scanf("%d%d",&x,&y),v[x].push_back(y),v[y].push_back(x);
		dfs(1,0);
		if(c[0].size()>c[1].size())
			swap(c[0],c[1]);
		printf("%d\n",c[0].size());
		for(int i=0;i<c[0].size();i++)
			printf("%d%c",c[0][i],i==c[0].size()-1? '\n':' ');
		c[0].clear(),c[1].clear();
		for(int i=1;i<=n;i++)
			v[i].clear(),vis[i]=0;
	}
	return 0;
}