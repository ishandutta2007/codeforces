//By zzq
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
ll n,a,b,T,sl[2333333],sr[2333333];
char w[233333];
int main()
{
	scanf("%I64d%I64d%I64d%I64d",&n,&a,&b,&T);
	scanf("%s",w+1);
	int ans=0;
	{
	ll ct=0;
	for(int i=1;i<=n;i++)
	{
		char cp=w[i]; ll tm=1+a;
		if(cp=='w') tm+=b;
		ct+=tm; sl[i]=ct;
		if(ct-a<=T) ans=max(ans,i);
	}
	}
	{
	ll ct=0;
	for(int i=n;i>=1;i--)
	{
		char cp=w[i]; ll tm=1+a;
		if(cp=='w') tm+=b;
		ct+=tm; sr[i]=ct;
	}
	}
	for(int i=1;i<=n;i++)
	{
		ll zbt=sl[i]+(i-2)*a;
		if(zbt>T) continue;
		int l=i+1,r=n+1;
		while(l<r)
		{
			int mid=(l+r)>>1;
			ll ct=zbt+sr[mid];
			if(ct<=T) r=mid; else l=mid+1;
		}
		if(r==n+1) continue;
		ans=max(ans,int(n-l+1+i));
	}
	for(int i=1;i<=n;i++)
	{
		ll zbt=sr[i]+(n-i)*a;
		if(zbt>T) continue;
		int l=0,r=i-1;
		while(l<r)
		{
			int mid=(l+r+1)>>1;
			ll ct=zbt+sl[mid];
			if(ct<=T) l=mid; else r=mid-1;
		}
		if(r==0) continue;
		ans=max(ans,int(n-i+1+l));
	}
	printf("%d\n",ans);
}