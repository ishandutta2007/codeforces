//CF1556F
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
const int N = 14;
const int M = 1<<N;
const int MO = 1e9+7;
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
int n,m,a[N],e[N][N],p[N][M],f[M];
int main()
{
	int i,j,k,x,y,s;
	scanf("%d",&n);
	m=1<<n;
	for(i=0;i<n;i++)
		scanf("%d",a+i);
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			e[i][j]=mul(a[i],fpow(a[i]+a[j]));
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			p[i][j]=1;
			for(k=0;k<n;k++)
				if(j&(1<<k))
					p[i][j]=mul(p[i][j],e[i][k]);
		}
	}
	for(i=0;i<n;i++)
		f[1<<i]=1;
	for(i=1;i<m;i++){
		if(f[i])
			continue;
		f[i]=1;
		for(j=(i-1)&i;j;j=(j-1)&i){
			x=f[j];
			for(k=0;k<n;k++)
				if(j&(1<<k))
					x=mul(x,p[k][i^j]);
			ad(f[i],MO-x);
		}
	}
	s=0;
	for(i=1;i<m;i++){
		x=f[i];
		y=0;
		for(k=0;k<n;k++)
			if(i&(1<<k))
				x=mul(x,p[k][(m-1)^i]),y++;
		ad(s,mul(x,y));
	}
	printf("%d\n",s);
	return 0;
}