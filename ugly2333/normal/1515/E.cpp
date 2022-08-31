//CF1515E
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
int n,p;
void ad(int&x,int y){
	x+=y;
	if(x>=p)
		x-=p;
}
int mul(int x,int y){
	return (LL)x*y%p;
}
int fpow(int x,int y=p-2){
	int z=1;
	while(y){
		if(y&1)
			z=mul(z,x);
		x=mul(x,x);
		y>>=1;
	}
	return z;
}
int p2[N],fac[N],ifac[N],e[N],f[N][N];
int main()
{
	int i,j,k,x;
	cin>>n>>p;
	p2[0]=1,fac[0]=1,ifac[0]=1;
	for(i=1;i<=n;i=i+1){
		p2[i]=mul(p2[i-1],2);
		fac[i]=mul(fac[i-1],i);
		ifac[i]=fpow(fac[i]);
	}
	for(i=1;i<=n;i=i+1)
		e[i]=mul(p2[i-1],ifac[i]);
	f[0][0]=1;
	for(i=1;i<=n+1;i=i+1){
		for(j=0;j<=i-2;j=j+1){
			for(k=1;k<=i;k=k+1)
				ad(f[i][k],mul(f[j][k-1],e[i-j-1]));
		}
	}
	x=0;
	for(i=1;i<=n;i=i+1)
		ad(x,mul(f[n+1][i],fac[n+1-i]));
	cout<<x;
	return 0;
}