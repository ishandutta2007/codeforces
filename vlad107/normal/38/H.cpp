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

#define INF 1000000000
#define N 66

using namespace std;

int n,m,a[N][N],x,y,minA[N],maxA[N],g1,g2,s1,s2;
bool canGold[N],canSilver[N],canBronze[N];
long long f[N][N],ans;

int main(){
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			if (i==j)a[i][j]=0;else a[i][j]=INF;
	for (int i=0;i<m;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		--x;--y;
		a[x][y]=min(a[x][y],z);
		a[y][x]=min(a[y][x],z);
	}
	scanf("%d%d%d%d",&g1,&g2,&s1,&s2);
	for (int k=0;k<n;k++)
		for (int i=0;i<n;i++)
			for (int j=0;j<n;j++)
				a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			if (i!=j)a[i][j]=a[i][j]*n+i;
	for (int i=0;i<n;i++){
		minA[i]=INF;maxA[i]=-INF;
		for (int j=0;j<n;j++)
			if (i!=j){
				minA[i]=min(minA[i],a[i][j]);
				maxA[i]=max(maxA[i],a[i][j]);
			}
	}
	for (int x=0;x<n;x++)
		for (int y=0;y<n;y++)
			if ((x!=y)&&(maxA[y]>minA[x])){
				for (int i=0;i<n;i++){
					canGold[i]=minA[i]<=minA[x];
					canBronze[i]=maxA[i]>=maxA[y];
					canSilver[i]=false;
					for (int j=0;j<n;j++)
						if ((i!=j)&&(a[i][j]>minA[x])&&(a[i][j]<maxA[y])){
							canSilver[i]=true;
							break;
						}
					if (i==x){
						canSilver[i]=false;
						canBronze[i]=false;
					}
					if (i==y){
						canGold[i]=false;
						canSilver[i]=false;
					}
				}
				memset(f,0,sizeof(f));
				f[0][0]=1;
				for (int i=0;i<n;i++){
					for (int u=n;u>=0;u--)
						for (int v=n-u;v>=0;v--){
							if (f[u][v]==0)continue;
							if (canGold[i])f[u+1][v]+=f[u][v];
							if (canSilver[i])f[u][v+1]+=f[u][v];
							if (!canBronze[i])f[u][v]=0;
						}
				}
				for (int i=g1;i<=g2;i++)
					for (int j=s1;j<=s2;j++)
						ans+=f[i][j];
			}
	printf("%I64d\n",ans);
}