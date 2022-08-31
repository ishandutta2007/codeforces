//CF 193A
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 55;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int n,m,a[N][N],b[N][N];
bool ok(int x,int y){
	return x&&y&&x<=n&&y<=m&&a[x][y];
}
int dfs(int x,int y){
	if(b[x][y])
		return 0;
	int i,r=1;
	b[x][y]=1;
	for(i=0;i<4;i=i+1){
		if(ok(x+dx[i],y+dy[i]))
			r+=dfs(x+dx[i],y+dy[i]);
	}
	return r;
}
int main()
{
	char ch[N];
	int i,j,s=0,x,y;
	cin>>n>>m;
	for(i=1;i<=n;i=i+1){
		cin>>ch;
		for(j=1;j<=m;j=j+1){
			if(ch[j-1]=='#')
				a[i][j]=1,s++,x=i,y=j;
		}
	}
	if(s<=2){
		cout<<-1;
		return 0;
	}
	for(i=1;i<=n;i=i+1)
		for(j=1;j<=m;j=j+1)
			if(a[i][j]){
				memset(b,0,sizeof(b));
				a[i][j]=0;
				if(dfs(x,y)!=s-1){
					cout<<1;
					return 0;
				}
				a[i][j]=1;
				x=i,y=j;
			}
	cout<<2;
	return 0;
}