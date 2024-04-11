//CF 877D
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
const int N = 1005;
int a[N][N],d[N][N];
char ch[N];
queue<pair<int,int> > Q;
int main()
{
	int n,m,k,i,j,bx,by,ex,ey,x,y,z;
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=n;i=i+1){
		scanf("%s",ch+1);
		for(j=1;j<=m;j=j+1){
			d[i][j]=1e9;
			if(ch[j]=='#')
				a[i][j]=1;
		}
	}
	scanf("%d%d%d%d",&ex,&ey,&bx,&by);
	d[bx][by]=0;
	Q.push(make_pair(bx,by));
	while(d[ex][ey]>=1e9&&!Q.empty()){
		x=Q.front().first;
		y=Q.front().second;
		z=d[x][y];
		//cout<<x<<y<<z<<endl;
		Q.pop();
		i=x,j=y-1;
		while(j>=1&&j>=y-k&&!a[i][j]&&d[i][j]>z){
			if(d[i][j]>=1e9)
				Q.push(make_pair(i,j));
			d[i][j]=z+1;
			j--;
		}
		i=x,j=y+1;
		while(j<=m&&j<=y+k&&!a[i][j]&&d[i][j]>z){
			if(d[i][j]>=1e9)
				Q.push(make_pair(i,j));
			d[i][j]=z+1;
			j++;
		}
		i=x-1,j=y;
		while(i>=1&&i>=x-k&&!a[i][j]&&d[i][j]>z){
			if(d[i][j]>=1e9)
				Q.push(make_pair(i,j));
			d[i][j]=z+1;
			i--;
		}
		i=x+1,j=y;
		while(i<=n&&i<=x+k&&!a[i][j]&&d[i][j]>z){
			if(d[i][j]>=1e9)
				Q.push(make_pair(i,j));
			d[i][j]=z+1;
			i++;
		}
	}
	if(d[ex][ey]>=1e9)
		d[ex][ey]=-1;
	cout<<d[ex][ey]<<endl;
	return 0;
}