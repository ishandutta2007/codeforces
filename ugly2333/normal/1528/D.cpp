//CF1528D
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
const int N = 666;
const int inf = 2e9;
int n,m,a[N][N],d[N],c[N];
void cmin(int&x,int y){
	if(x>y)
		x=y;
}
void solve(int s){
	int i,j,x,y;
	for(i=0;i<n;i++)
		d[i]=inf,c[i]=1;
	for(i=0;i<n;i++)
		if(a[s][i])
			d[i]=a[s][i];
	for(j=0;j<n;j++){
		y=inf;
		for(i=0;i<n;i++)
			if(c[i]&&d[i]<y)
				x=i,y=d[i];
		c[x]=0;
		cmin(d[(x+1)%n],d[x]+1);
		for(i=0;i<n;i++)
			if(a[x][i]){
				y=(i+d[x])%n;
				cmin(d[y],d[x]+a[x][i]);
			}
	}
	d[s]=0;
	for(i=0;i<n;i++)
		printf("%d ",d[i]);
	printf("\n");
}
int main()
{
	int i,x,y,z;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		a[x][y]=z;
	}
	for(i=0;i<n;i++)
		solve(i);
	return 0;
}