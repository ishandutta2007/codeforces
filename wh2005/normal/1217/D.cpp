#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <deque>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
using namespace std;
int n,m;
int a[5009],b[5009],g[5009][5009];
int tot,cnt,s[5009],vis[5009];
struct pp{int len,c[5009];}p[5009];
int col[5009];
void dfs(int u){
	vis[u]=1;
	for(int i=n;i>=1;i--)
		if(g[u][i]!=-1){
			if(col[g[u][i]]!=0) continue;
			if(vis[i]==0) dfs(i);
			col[g[u][i]]=1;
			if(vis[i]==1){
				cnt++;
				col[g[u][i]]=2;	
			}
		}
	vis[u]=-1;	
}
bool cmp(pp x,pp y){
	return x.len<y.len;
}
int main(){
	memset(col,0,sizeof(col));
	memset(vis,0,sizeof(vis));
	memset(g,-1,sizeof(g));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d%d",&a[i],&b[i]);g[a[i]][b[i]]=i;
	}
	tot=0,cnt=0;
	for(int i=1;i<=n;i++) if(!vis[i]) dfs(i);
	if(cnt==0){
		printf("1\n");for(int i=1;i<=m;i++) printf("1 ");
		printf("\n");return 0;
	}
	printf("2\n");
	for(int i=1;i<=m;i++){
		printf("%d ",col[i]);
	} 
	return 0;
}