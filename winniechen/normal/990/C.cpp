#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#include <queue>
#include <cstring>
using namespace std;
#define N 300005
char s[N];
int a[N],b[N<<1];
int main()
{
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		int len=strlen(s+1),now=0,vis=0;
		for(int j=1;j<=len;j++)
		{
			now+=(s[j]=='('?1:-1);
			if(now<0)break;
		}
		if(now>=0)
		{
			a[i]=now;
			vis=1;
		}
		if(!vis)
		{
			now=0;
			for(int j=len;j>=1;j--)
			{
				now-=(s[j]=='('?1:-1);
				if(now<0)break;
			}
			if(now>=0)
			{
				a[i]=-now;
				vis=1;
			}
		}
		if(vis)b[a[i]+N]++;
	}
	long long ans=0;
	for(int i=0;i<N;i++)
	{
		//printf("%d\n",a[i]);
		ans+=1ll*b[i+N]*b[N-i];
	}
	printf("%lld\n",ans);
	return 0;
}