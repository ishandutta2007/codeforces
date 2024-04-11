#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int q;
ll a,b,m,r[55];
void solve()
{
	if(a==b)
	{
		printf("1 %I64d\n",a);
		return;
	}
	for(int k=2;k<=50;k++)
	{
		ll minn=(a+1)*(1ll<<(k-2));
		ll maxx=(a+m)*(1ll<<(k-2));
		if(minn>b)
		{
			printf("-1\n");
			return;
		}
		if(maxx<b)continue;
		printf("%d ",k);
		ll rest=maxx-b;
		for(int i=2;i<k;i++)
		{
			r[i]=rest/(1ll<<(k-i-1));
			if(r[i]>=m)r[i]=m-1;
			rest-=r[i]*(1ll<<(k-i-1));
		}
		r[k]=rest;
		printf("%I64d ",a);
		ll s=a;
		for(int i=2;i<=k;i++)
		{
			r[i]=m-r[i];
			printf("%I64d ",s+r[i]);
			s=s+s+r[i];
		}
		printf("\n");
		return;
	}
}
int main()
{
	scanf("%d",&q);
	while(q--)
	{
		scanf("%I64d%I64d%I64d",&a,&b,&m);
		solve();
	}
	return 0;
}