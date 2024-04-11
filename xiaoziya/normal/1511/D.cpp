#include<stdio.h>
#include<vector>
using namespace std;
const int maxn=50005,maxm=50005;
int n,k,e;
int start[maxn],then[maxm],to[maxm],vis[30][30],deg[maxn];
vector< pair<int,int> >ans;
inline void add(int x,int y){
	deg[y]++,then[++e]=start[x],start[x]=e,to[e]=y;
}
void dfs(int x){
	while(start[x]){
		int i=start[x];
		start[x]=then[i];
		if(vis[x][to[i]]==0)
			vis[x][to[i]]=1,ans.push_back(make_pair(x,to[i])),dfs(to[i]);
	}
}
int main(){
	e=1;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++)
		for(int j=1;j<=k;j++)
			add(i,j);
	dfs(1);
	for(int i=1;i<=n;i++)
		printf("%c",ans[(i-1)%ans.size()].first+96);
	puts("");
	return 0;
}