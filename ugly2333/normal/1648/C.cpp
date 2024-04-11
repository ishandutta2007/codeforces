//CF1648C
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
const int N = 222222;
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
int n,m,w,a[N],d[N],t[N],dd;
int f[N],g[N];
void modify(int x,int y){
	while(x<=w){
		ad(t[x],y);
		x+=x&-x;
	}
}
int query(int x){
	int y=0;
	while(x){
		ad(y,t[x]);
		x-=x&-x;
	}
	return y;
}
int main()
{
	int i,x,y,z,ans;
	scanf("%d%d",&n,&m);
	w=200005;
	f[0]=1;
	for(i=1;i<=w;i++)
		f[i]=mul(f[i-1],i);
	g[w]=fpow(f[w]);
	for(i=w;i>=1;i--)
		g[i-1]=mul(g[i],i);
	for(i=1;i<=n;i++)
		scanf("%d",&x),a[x]++;
	z=1;
	for(i=1;i<=w;i++)
		z=mul(z,g[a[i]]);
	for(i=1;i<=w;i++)
		modify(i,a[i]);
	ans=0;
	for(i=1;i<=n&&i<=m;i++){
		scanf("%d",&x);
		ad(ans,mul(mul(f[n-i],z),query(x-1)));
		z=mul(z,a[x]);
		if(a[x])
			a[x]--,modify(x,-1);
	}
	if(n<m)
		ad(ans,z);
	printf("%d\n",ans);
	return 0;
}