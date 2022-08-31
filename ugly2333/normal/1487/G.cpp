//CF1487G
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
const int N = 444;
const int M = 33;
const int MO = 998244353;
int ad(int&x,int y){
	x+=y;
	if(x>=MO)
		x-=MO;
}
int mul(int x,int y){
	return (LL)x*y%MO;
}
int n,m=26,a[M],f[2][N][N][3],s[N][N];
int main()
{
	int i,j,k,x,y,o;
	scanf("%d",&n);
	for(i=1;i<=m;i=i+1)
		scanf("%d",a+i);
	f[0][0][0][2]=1;
	for(i=0;i<n;i=i+1)
		for(j=0;j<=i;j=j+1)
			for(k=0;j+k<=i;k=k+1)
				for(x=0;x<3;x=x+1){
					for(y=0;y<3;y=y+1)
						if(x!=y||x==2||i==n/2){
							if(y<2)
								o=1;
							else{
								if(i==0||i==n/2||x<2)
									o=24;
								else
									o=23;
							}
							ad(f[i&1^1][j+(y==0)][k+(y==1)][y],mul(f[i&1][j][k][x],o));
						}
					f[i&1][j][k][x]=0;
				}
	for(i=0;i<=n;i=i+1)
		for(j=0;j<=n;j=j+1)
			for(k=0;k<3;k=k+1)
				ad(s[i][j],f[n&1][i][j][k]);
	for(i=0;i<=n;i=i+1)
		for(j=n;j>0;j=j-1)
			ad(s[i][j-1],s[i][j]);
	for(i=n;i>0;i=i-1)
		for(j=0;j<=n;j=j+1)
			ad(s[i-1][j],s[i][j]);
	x=s[0][0];
	for(i=1;i<=m;i=i+1)
		ad(x,MO-s[a[i]+1][0]);
	for(i=1;i<=m;i=i+1)
		for(j=i+1;j<=m;j=j+1)
			ad(x,s[a[i]+1][a[j]+1]);
	printf("%d",x);
	return 0;
}