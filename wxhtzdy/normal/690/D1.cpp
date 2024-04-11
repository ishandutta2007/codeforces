#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,m,a[N][N],sz=0,was[N][N];
char b[N][N];
int dx[4]={1,0,0,-1};
int dy[4]={0,1,-1,0};
void dfs(int i,int j){
	if(i<0||i>=n||j<0||j>=m||was[i][j]||!a[i][j])return;
	was[i][j]=1;
	for(int dd=0;dd<4;dd++)dfs(i+dx[dd],j+dy[dd]);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>b[i][j];
			was[i][j]=0;
			if(b[i][j]=='.')a[i][j]=0;
			else a[i][j]=1;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i][j]&&!was[i][j])dfs(i,j),sz++;
		}
	}
	cout<<sz;
	return 0;	
}