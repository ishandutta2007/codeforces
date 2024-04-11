#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 500005
#define ll long long
int a[N],n,d[N],pos[N];ll s[N];
int check(int x)
{
	int flg=0;d[n+1]=-1;
	for(int i=1,j=0;i<=n;i++)
	{
		if(flg||a[i]>=x)d[++j]=a[i];
		else flg=++j,d[j]=x,i--;
	}
	if(!flg)d[n+1]=x,flg=n+1;
	s[0]=0;
	for(int i=1;i<=n+1;i++)s[i]=d[i]+s[i-1];//,printf("%d ",d[i]);;puts("");
	for(int i=n+1,now=1;i;i--)
		while(now<=n+1&&d[i]>now)pos[now++]=i;
	for(int k=1;k<=n+1;k++)
	{
		ll tmp=s[k]-(ll)k*(k-1);
		tmp-=(ll)k*max(pos[k]-k,0);tmp-=s[n+1]-s[pos[k]];
		// printf("%d %d %d %lld\n",x,k,pos[k],tmp);
		if(tmp>0)return k<flg?-1:1;
	}return 0;
}
int main()
{
	scanf("%d",&n);int flg=0;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),flg^=(a[i]&1);
	sort(a+1,a+n+1);reverse(a+1,a+n+1);
	int l=0,r=(n>>1)+1;
	while(l<r)
	{
		int m=(l+r)>>1;
		if(check((m<<1)|flg)!=-1)r=m;
		else l=m+1;
	}
	if(check((l<<1)|flg))return puts("-1"),0;
	int ans=l;r=(n>>1)+1;
	while(l<r)
	{
		int m=(l+r)>>1;
		// printf("%d %d %d %d\n",l,m,r,check((m<<1)|flg));
		if(!check((m<<1)|flg))l=m+1;
		else r=m;
	}l--;
	ans=(ans<<1)|flg,l=(l<<1)|flg;
	for(int i=ans;i<=l;i+=2)printf("%d ",i);
}
///cccc