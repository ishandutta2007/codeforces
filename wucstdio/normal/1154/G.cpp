#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int n,c[10000005],a[1000005],min1[10000005],min2[10000005];
ll ans=1000000000000000000;
int x,y;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		c[a[i]]++;
		if(!min1[a[i]])min1[a[i]]=i;
		else min2[a[i]]=i;
	}
	for(int i=1;i<=10000000;i++)
	{
		for(int j=2*i;j<=10000000;j+=i)
		{
			c[i]+=c[j];
			if(min1[j])
			{
				if(!min1[i])min1[i]=min1[j];
				else if(!min2[i])min2[i]=min1[j];
			}
			if(min2[j])
			{
				if(!min1[i])min1[i]=min2[j];
				else if(!min2[i])min2[i]=min2[j];
			}
		}
	}
	for(int i=1;i<=10000000;i++)
	{
		if(min1[i]&&min2[i])
		{
			ll now=1ll*a[min1[i]]*a[min2[i]]/i;
			if(now<ans)ans=now,x=min1[i],y=min2[i];
		}
	}
	if(x>y)swap(x,y);
	printf("%d %d\n",x,y);
	return 0;
}