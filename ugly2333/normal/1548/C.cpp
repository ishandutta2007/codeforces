//CF1548
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
const int N = 3e6+36;
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
int n,q,m,f[N],g[N],a[N],b[N];
int main()
{
	int i;
	scanf("%d%d",&n,&q);
	m=(n+1)*3;
	f[0]=1;
	for(i=1;i<=m;i++)
		f[i]=mul(f[i-1],i);
	g[m]=fpow(f[m]);
	for(i=m;i>=1;i--)
		g[i-1]=mul(g[i],i);
	for(i=1;i<=m;i++)
		a[i-1]=mul(mul(f[m],g[i]),g[m-i]);
	for(i=m-1;i>=2;i--){
		b[i-2]=a[i];
		a[i]=0;
		ad(a[i-1],MO-mul(b[i-2],3));
		ad(a[i-2],MO-mul(b[i-2],3));
	}
	while(q--){
		scanf("%d",&i);
		printf("%d\n",b[i]);
	}
	return 0;
}