//CF 1025E
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 55;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int n,m,a[N][N],b[N][N],c[N][N],d[N];
queue<int> q;
void bfs(int x,int y){
	int i,j,k;
	for(i=1;i<=n;i=i+1)
		for(j=1;j<=n;j=j+1)
			b[i][j]=-1;
	q.push(x*N+y);
	while(!q.empty()){
		k=q.front();
		q.pop();
		x=k/N,y=k%N;
		for(k=0;k<4;k=k+1){
			i=x+dx[k],j=y+dy[k];
			if(i>0&&i<=n&&j>0&&j<=n&&!a[i][j]&&b[i][j]<0){
				b[i][j]=k;
				q.push(i*N+j);
			}
		}
	}
}
vector<int> v[4],t;
void mv(int sx,int sy,int tx,int ty){
	int i,j;
	bfs(sx,sy);
	/*cout<<sx<<sy<<tx<<ty<<endl;
	if(b[tx][ty]==-1){
		for(i=1;i<=n;i=i+1){
			for(j=1;j<=n;j=j+1)
				cout<<b[i][j];
			cout<<endl;
		}
	}*/
	t.clear();
	while(tx!=sx||ty!=sy){
		i=b[tx][ty];
		t.push_back(i);
		tx-=dx[i],ty-=dy[i];
	}
	tx=sx,ty=sy;
	for(j=t.size();j--;){
		i=t[j];
		tx+=dx[i],ty+=dy[i];
		v[0].push_back(sx),v[1].push_back(sy),v[2].push_back(tx),v[3].push_back(ty);
		a[tx][ty]=a[sx][sy];
		a[sx][sy]=0;
		sx=tx,sy=ty;
	}
}
int xx[N],yy[N];
pair<int,int> p[N];
int main()
{
	int i,j,k,x,y;
	cin>>n>>m;
	for(i=1;i<=m;i=i+1){
		cin>>x>>y;
		a[x][y]=i;
	}
	for(i=1;i<=m;i=i+1){
		cin>>x>>y;
		c[x][y]=i;
	}
	k=0;
	for(i=1;i<=n;i=i+1)
		if(a[1][i])
			++k,mv(1,i,1,k);
	for(i=2;i<=n;i=i+1)
		for(j=n;j;j=j-1)
			if(a[i][j])
				++k,mv(i,j,1,k);
	k=0;
	for(i=1;i<=n;i=i+1)
		if(c[i][1])
			d[c[i][1]]=++k;
	for(i=2;i<=n;i=i+1)
		for(j=n;j;j=j-1)
			if(c[j][i])
				d[c[j][i]]=++k;
	for(i=1;i<=m;i=i+1)
		mv(1,i,d[a[1][i]],i);
	for(i=1;i<=n;i=i+1)
		for(j=1;j<=n;j=j+1)
			if(a[i][j])
				mv(i,j,i,1);
	k=m;
	for(i=n;i>=2;i=i-1)
		for(j=1;j<=n;j=j+1)
			if(c[j][i])
				mv(k,1,j,i),k--;
	for(i=n;i;i=i-1)
		if(c[i][1])
			mv(k,1,i,1),k--;
	k=v[0].size();
	cout<<k<<endl;
	for(i=0;i<k;i=i+1){
		for(j=0;j<4;j=j+1)
			cout<<v[j][i]<<' ';
		cout<<endl;
	}
	return 0;
}