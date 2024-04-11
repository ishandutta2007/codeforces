//CF 
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
const int N = 333;
const int Q = 20;
const int inf = 1e9;
int n,m,d[N][N][Q],f[Q];
bool comb(int x,int y,int z){
	int i,j,k;
	for(i=1;i<=n;i=i+1){
		for(j=1;j<=n;j=j+1)
			d[i][j][x]=-inf;
		d[i][i][x]=0;
	}
	for(i=1;i<=n;i=i+1)
		for(j=1;j<=n;j=j+1)
			for(k=1;k<=n;k=k+1)
				if(d[i][k][x]<d[i][j][y]+d[j][k][z])
					d[i][k][x]=d[i][j][y]+d[j][k][z];
	for(i=1;i<=n;i=i+1)
		if(d[i][i][x]>0)
			return 0;
	f[x]=f[y]+f[z];
	return 1;
}
int main()
{
	int i,j,k,x,y;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i=i+1){
		for(j=1;j<=n;j=j+1)
			d[i][j][0]=-inf;
		d[i][i][0]=0;
	}
	while(m--){
		scanf("%d%d%d%d",&i,&j,&x,&y);
		d[i][j][0]=x,d[j][i][0]=y;
	}
	f[0]=1;
	for(i=0,j=0;f[i]<=n;i=i+1){
		while(j>=0&&!comb(i+1,i,j)){
			j--;
		}
		if(j<0){
			printf("%d",f[i]+1);
			return 0;
		}
		if(i==j)
			j++;
		else
			j--;
	}
	printf("0");
	return 0;
}