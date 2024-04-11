#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll inf = (ll)1e18;
int n;
ll L;
ll c[35];
int main()
{
	scanf("%d%I64d",&n,&L);
	for(int i=0;i<n;++i)scanf("%I64d",&c[i]);
	for(int i=1;i<n;++i)c[i]=min(c[i],c[i-1]*2);
	for(int i=n;i<=30;++i)c[i]=c[i-1]*2;
	for(int i=29;i>=0;--i)c[i]=min(c[i],c[i+1]);
	ll ans=inf,res=0;
	for(int i=30;i>=0;--i)
	{
		if(L>=(1<<i))
		{
			L-=(1<<i);
			res+=c[i];
		}
		else ans=min(ans,res+c[i]);
	}
	ans=min(ans,res);
	printf("%I64d\n",ans);
	return 0;
}