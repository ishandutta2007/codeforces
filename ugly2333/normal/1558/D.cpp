//CF1558D
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
const int N = 1<<19;
const int MO = 998244353;
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
int n,m,f[N],g[N],x[N],y[N],z[N],a[N],t[N];
void modify(int x,int k=1,int l=1,int r=n){
	t[k]++;
	if(l==r)
		return;
	int h=l+r>>1;
	if(x<=h)
		modify(x,k<<1,l,h);
	else
		modify(x,k<<1|1,h+1,r);
}
int query(int x,int k=1,int l=1,int r=n){
	if(l==r)
		return l;
	int h=l+r>>1;
	int o=h-l+1-t[k<<1];
	if(x<=o)
		return query(x,k<<1,l,h);
	return query(x-o,k<<1|1,h+1,r);
}
void clr(int k=1){
	if(k>=N||!t[k])
		return;
	t[k]=0;
	clr(k<<1);
	clr(k<<1|1);
}
int main()
{
	int T,i,o;
	n=N-1;
	f[0]=1;
	for(i=1;i<=n;i++)
		f[i]=mul(f[i-1],i);
	g[n]=fpow(f[n]);
	for(i=n;i>=1;i--)
		g[i-1]=mul(g[i],i);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(i=1;i<=m;i++)
			scanf("%d%d",x+i,y+i);
		for(i=m;i>=1;i--){
			z[i]=query(y[i]);
			a[z[i]]=x[i];
			modify(z[i]);
		}
		o=m;
		for(i=1;i<=m;i++)
			if(a[z[i]+1]>x[i])
				o--;
		o=n-1-o;
		printf("%d\n",mul(f[n+o],mul(g[n],g[o])));
		clr();
		for(i=1;i<=m;i++)
			a[z[i]]=0;
	}
	return 0;
}