//CF1528E
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
int i2=fpow(2),i6=fpow(6);
int c2(int x){
	return mul(mul(x,x-1),i2);
}
int c3(int x){
	return mul(mul(x,x-1),mul(x-2,i6));
}
int n,f[N],g[N],h[N],s,t;
int main()
{
	int i;
	cin>>n;
	f[0]=1;
	for(i=1;i<=n;i++)
		f[i]=c2(f[i-1]+2);
	for(i=1;i<=n;i++){
		g[i]=c2(f[i-1]+1);
		if(i>1)
			ad(g[i],MO-c2(f[i-2]+1));
	}
	for(i=1;i<=n;i++)
		h[i]=h[i-1],ad(h[i],g[i]);
	for(i=1;i<=n-2;i++)
		ad(s,mul(g[i],h[n-1-i]));
	for(i=1;i<=n;i++)
		ad(s,g[i]),ad(s,g[i]);
	ad(s,1);
	t=c3(f[n-1]+2);
	if(n>1)
		ad(t,MO-c3(f[n-2]+2));
	ad(s,mul(t,2));
	cout<<s;
	return 0;
}