#include <algorithm>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <memory>
#include <limits>
#include <queue>
#include <deque>
#include <bitset>
#include <stack>
#include <numeric>
#include <cmath>
#include <complex>
#include <list>
#include <ctime>
#include <functional>

#define N 2010
#define INF 1000000000

const int hx[]={1,-1,0,0};
const int hy[]={0,0,1,-1};

int qb=0,qe=0,j,n,m,k,d[N][N],qx[N*N],qy[N*N],nx,ny;

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			d[i][j]=INF;
	for (int i=0;i<k;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		d[x][y]=0;
		qx[qe]=x;
		qy[qe++]=y;
	}
	while (qb<qe){
		int x=qx[qb],
		    y=qy[qb++];
		for (int i=0;i<4;i++){
			int cx=x+hx[i],
			    cy=y+hy[i];
			if (cx<1||cy<1||cx>n||cy>m)continue;
			if (d[cx][cy]<=d[x][y]+1)continue;
			d[cx][cy]=d[x][y]+1;
			qx[qe]=cx;qy[qe++]=cy;
		}
	}
	nx=1;ny=1;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (d[i][j]>d[nx][ny]){
				nx=i;ny=j;
			}
	printf("%d %d\n",nx,ny);
	return 0;
}