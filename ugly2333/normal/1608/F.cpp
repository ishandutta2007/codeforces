//CF1608F
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
const int N = 4444;
const int M = 111;
const int MO = 998244353;
void ad(int&x,int y){
	x+=y;
	if(x>=MO)
		x-=MO;
}
int mul(int x,int y){
	return (LL)x*y%MO;
}
int fpow(int x,int y=MO-2){
	int z=1;
	while(y){
		if(y&1)
			z=mul(z,x);
		x=mul(x,x);
		y>>=1;
	}
	return z;
}
int fac(int o){
	int i,x=1;
	for(i=1;i<=o;i++)
		x=mul(x,i);
	return x;
}
int n,m,b[N],c[N][N],f[2][M][N];
bool ok(int x){
	return x>=0&&x<=m;
}
int main()
{
	int i,j,k,o,s,x;
	n=4022;
	for(i=0;i<=n;i++){
		c[i][0]=1;
		for(j=1;j<=i;j++)
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%MO;
	}
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",b+i),b[i]-=m;
	b[0]=0;
	m=m*2;
	f[0][0][0]=1;
	o=0;
	for(i=1;i<=n;i++){
		for(j=0;j<=m;j++){
			for(k=0;k<=i;k++){
				if(!f[o][j][k])
					continue;
				if(ok(j+b[i-1]-b[i]+1))
					ad(f[o^1][j+b[i-1]-b[i]+1][k],f[o][j][k]);
				else{
					if(j+b[i-1]-b[i]+1<0){
						x=j+b[i-1]-b[i]+1;
						if(k+x>=0)
							ad(f[o^1][j+b[i-1]-b[i]+1-x][k+x],f[o][j][k]);
					}
				}
			}
		}
		for(j=1;j<=m;j++){
			for(k=0;k<=i;k++){
				ad(f[o^1][j][k],f[o^1][j-1][k+1]);
			}
		}
		for(j=0;j<=m;j++){
			for(k=0;k<=i;k++){
				if(!f[o][j][k])
					continue;
				if(ok(j+b[i-1]-b[i])){
					ad(f[o^1][j+b[i-1]-b[i]][k],mul(f[o][j][k],j+b[i-1]+k));
					ad(f[o^1][j+b[i-1]-b[i]][k+1],mul(f[o][j][k],k+1));
				}
			}
		}
		for(j=0;j<M;j++)
			for(k=0;k<N;k++)
				f[o][j][k]=0;
		o^=1;
	}
	s=0;
	for(j=0;j<=m;j++)
		for(k=0;k<=n;k++)
			if(b[n]+j>=0&&b[n]+j<=n)
				ad(s,mul(f[o][j][k],c[n-(b[n]+j)][k]));
	printf("%d\n",s);
	return 0;
}