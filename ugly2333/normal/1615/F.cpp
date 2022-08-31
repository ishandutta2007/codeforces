//CF1615F
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
const int N = 2222;
const int MO = 1e9+7;
void ad(int&x,int y){
	x+=y;
	if(x>=MO)
		x-=MO;
}
int mul(int x,int y){
	return (LL)x*y%MO;
}
int n,f[N][N*2],g[N][N*2];
char a[N],b[N];
int main()
{
	int T,i,j,x,y,z;
	scanf("%d",&T);
	while(T--){
		scanf("%d%s%s",&n,a+1,b+1);
		f[0][N]=1;
		g[0][N]=0;
		for(i=1;i<=n;i++){
			for(x=0;x<2;x++)
				for(y=0;y<2;y++){
					if(x==a[i]-'0'||y==b[i]-'0')
						continue;
					z=(x==1)-(y==1);
					if(i&1)
						z=-z;
					for(j=N-i;j<=N+i;j++){
						ad(f[i][j+z],f[i-1][j]);
						ad(g[i][j+z],(g[i-1][j]+mul(f[i-1][j],abs(j-N)))%MO);
					}
				}
		}
		printf("%d\n",g[n][N]);
		n+=10;
		for(i=0;i<=n;i++)
			for(j=N-n;j<=N+n;j++)
				f[i][j]=0,g[i][j]=0;
	}
	return 0;
}