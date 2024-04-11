//CF 908B
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
const int N = 59;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int n,m,a[N][N],l;
int sx,sy,tx,ty;
char ch[N+N];
int q[N],w[N],b[N][N],ans=0;
bool chk(){
	int i,d,x=sx,y=sy,xx,yy;
	//for(i=0;i<4;i=i+1)
	//	cout<<q[i];
	//cout<<' ';
	for(i=0;i<l;i=i+1){
		d=q[ch[i]-48];
		xx=x+dx[d],yy=y+dy[d];
		if(xx<=0||xx>n||yy<=0||yy>m||a[xx][yy])
			return 0;
		x=xx,y=yy;
		//cout<<x<<y<<' ';
		if(x==tx&&y==ty)
			return 1;
	}
	return 0;
}
void dfs(int k){
	if(k==4){
		if(chk())
			ans++;
		//cout<<endl;
		return;
	}
	int i;
	for(i=0;i<4;i=i+1)
		if(!w[i]){
			q[k]=i;
			w[i]=1;
			dfs(k+1);
			w[i]=0;
			q[k]=0;
		}
}
int main()
{
	int i,j;
	cin>>n>>m;
	for(i=1;i<=n;i=i+1){
		cin>>ch;
		for(j=1;j<=m;j=j+1){
			if(ch[j-1]=='S')
				sx=i,sy=j;
			if(ch[j-1]=='E')
				tx=i,ty=j;
			if(ch[j-1]=='#')
				a[i][j]=1;
		}
	}
	cin>>ch;
	l=strlen(ch);
	dfs(0);
	cout<<ans<<endl;
	return 0;
}