//CF1628D
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
const int N = 1111111;
const int MO = 1e9+7;
int n,f[N],g[N],p[N];
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
int C(int x,int y){
	return mul(mul(f[x],g[y]),g[x-y]);
}
int main()
{
	int T,n,m,i,s;
	n=1e6;
	f[0]=1;
	for(i=1;i<=n;i++)
		f[i]=mul(f[i-1],i);
	g[n]=fpow(f[n]);
	for(i=n;i>=1;i--)
		g[i-1]=mul(g[i],i);
	p[0]=1;
	for(i=1;i<=n;i++)
		p[i]=mul(p[i-1],(MO+1)/2);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		n-=m;
		s=0;
		for(i=1;i<=m;i++)
			if(n)
				ad(s,mul(C(n-1+m-i,m-i),mul(i,p[n+m-i])));
		if(n==0)
			s=m;
		scanf("%d",&n);
		printf("%d\n",mul(s,n));
	}
	return 0;
}