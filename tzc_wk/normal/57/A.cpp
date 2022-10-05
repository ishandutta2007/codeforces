#include <bits/stdc++.h>
using namespace std;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};
int n,x,y,xx,yy;
bool vis[1001][1001];
bool on(int x,int y){
	return(x==0||y==0||x==n||y==n);
}
int ans=INT_MAX;
void dfs(int cx,int cy,int g){
	if(cx<0||cx>n||cy<0||cy>n)	return;
	if(vis[cx][cy])	return;
	if(cx==xx&&cy==yy){
		ans=min(ans,g);
		return;
	}
	vis[cx][cy]=true;
	for(int i=0;i<4;i++){
		if(on(cx+dx[i],cy+dy[i]))	dfs(cx+dx[i],cy+dy[i],g+1);
	}
}
int main(){
	cin>>n>>x>>y>>xx>>yy;
	dfs(x,y,0);
	cout<<ans<<endl;
}