#include <math.h>
#include <limits.h>
#include <complex>
#include <string>
#include <functional>
#include <iterator>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <ctime>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <complex.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

#define mp make_pair
#define pb push_back
#define INF 1000000000

#define N 1111

using namespace std;

int f[2][2][N][N],q,x0,y00,x1,y11,v,n,T,X[N][N],Y[N][N];

void add(int vx,int vy,int x,int y,int v){
	for (int i=x;i<=n;i=(i|(i-1))+1)
		for (int j=y;j<=n;j=(j|(j-1))+1)f[vx][vy][i][j]^=v;
}

void modify(int x,int y,int vx,int vy,int v){
	if (x%2!=vx)x++;
	if (y%2!=vy)y++;
	if ((x>n)||(y>n))return;
	add(vx,vy,X[x][y],Y[x][y],v);
}

int findT(int x,int y){
	if (x<1)return 0;
	if (y<1)return 0;
	int vx=x%2,vy=y%2;
	int nx=X[x][y];
	int ny=Y[x][y];
	x=nx;y=ny;
	int res=0;
	for (int i=x;i>0;i&=(i-1))
		for (int j=y;j>0;j&=(j-1))res^=f[vx][vy][i][j];
	return res;
}

int find(int x,int y){
	if (x<1)return 0;
	if (y<1)return 0;
	return findT(x,y);
}

int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	scanf("%d%d",&n,&T);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++){
			if (i<3)X[i][j]=1;else X[i][j]=X[i-2][j]+1;
			if (j<3)Y[i][j]=1;else Y[i][j]=Y[i][j-2]+1;
		}
	while (T){
		--T;
		scanf("%d",&q);
		if (q==1){
				scanf("%d%d%d%d",&x0,&y00,&x1,&y11);
				printf("%d\n",find(x1,y11)^find(x0-1,y11)^find(x1,y00-1)^find(x0-1,y00-1));
				//printf("%d  %d\n",find(2,2),find(1,2));
		}else{
			scanf("%d%d%d%d%d",&x0,&y00,&x1,&y11,&v);
			int vx,vy;
			vx=x0%2;vy=y00%2;
					modify(x0,y00,vx,vy,v);
					modify(x1+1,y00,vx,vy,v);
					modify(x0,y11+1,vx,vy,v);
					modify(x1+1,y11+1,vx,vy,v);

			
			if ((x1-x0+1)%2==1){
				modify(x1+1,y00,0,vy,v);
				modify(x1+1,y11+1,0,vy,v);

				modify(x1+1,y00,1,vy,v);
				modify(x1+1,y11+1,1,vy,v);
			}
			
			if ((y11-y00+1)%2==1){
				modify(x0,y11+1,vx,0,v);
				modify(x1+1,y11+1,vx,0,v);
				
				modify(x0,y11+1,vx,1,v);
				modify(x1+1,y11+1,vx,1,v);
			}
			if ((x1-x0+1)*(y11-y00+1)%2==1){
				modify(x1+1,y11+1,0,0,v);
				modify(x1+1,y11+1,0,1,v);
				modify(x1+1,y11+1,1,0,v);
				modify(x1+1,y11+1,1,1,v);
			}
		}
	}
}