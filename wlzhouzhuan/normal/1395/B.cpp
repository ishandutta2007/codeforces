#include<bits/stdc++.h>
using namespace std;
int n,m,sx,sy;
bool vis[101][101];
inline bool judge(int x,int y){  // vis 
	return x>=1&&x<=n&&y>=1&&y<=m&&!vis[x][y];
}
void dfs(int x,int y){
	vis[x][y]=1;  
	printf("%d %d\n",x,y); 
	for(int i=1;i<=n;i++)
		if(judge(i,y)) dfs(i,y);
	for(int i=1;i<=m;i++)
		if(judge(x,i)) dfs(x,i);
}
int main(){
	cin>>n>>m>>sx>>sy;
	dfs(sx,sy);
	return 0;
}