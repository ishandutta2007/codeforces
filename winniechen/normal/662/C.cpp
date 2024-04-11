#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 21
#define M 100005
#define MAXN 1<<20
#define ll long long
int a[M],n,m;ll f[MAXN],g[MAXN];
void FWT(ll *a,int len,int flag)
{
	for(int k=2;k<=len;k<<=1)
		for(int i=0,t=k>>1;i<len;i+=k)
			for(int j=i;j<i+t;j++)
			{
				ll tmp=a[j];a[j]=a[j]+a[j+t];a[j+t]=tmp-a[j+t];
				if(flag==-1)a[j]>>=1,a[j+t]>>=1;
			}
}
int main()
{
	scanf("%d%d\n",&n,&m);
	for(int i=1;i<=n;i++,getchar())
		for(int j=1;j<=m;j++)a[j]=(a[j]<<1)+(getchar()^48);
	for(int i=1;i<=m;i++)f[a[i]]++;
	int len=1<<n;
	for(int i=1;i<len;i++)g[i]=g[i>>1]+(i&1);
	for(int i=0;i<len;i++)g[i]=min(g[i],g[(len-1)^i]);
	FWT(f,len,1);FWT(g,len,1);for(int i=0;i<len;i++)f[i]=f[i]*g[i];FWT(f,len,-1);
	ll ans=1<<30;for(int i=0;i<len;i++)ans=min(ans,f[i]);printf("%lld\n",ans);
}