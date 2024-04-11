#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
ll m,a,b,minn[100005];
ll calc(ll x,ll m)
{
	m-=x;
	if(m<0)return 0;
	if(m==0)return 1;
	return (m+1)*(m/a+1)-a*(m/a)*(m/a+1)/2;
}
int main()
{
	scanf("%I64d%I64d%I64d",&m,&a,&b);
	minn[0]=0;
	for(int i=1;i<a;i++)minn[i]=-1;
	ll now=0,maxx=0;
	while(1)
	{
		maxx=max(maxx,now);
		if(now<b)
		{
			ll x=(b-now-1)/a+1;
			now+=x*a;
		}
		else
		{
			now-=b;
			if(minn[now]==-1)minn[now]=maxx;
			else break;
		}
	}
	ll ans=0;
	for(int i=0;i<a;i++)
	{
		if(minn[i]>m)continue;
		if(minn[i]==-1)continue;
		ans+=calc(i,m)-calc(i,minn[i]-1);
	}
	printf("%I64d\n",ans);
	return 0;
}