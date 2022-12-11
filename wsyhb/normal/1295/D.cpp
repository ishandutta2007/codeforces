#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans,l,r;
ll p[60];
int cnt;
void work(int x,int tot,ll s)
{
	if(x>cnt)
	{
		if(tot)
		{
			if(tot&1) ans-=r/s-l/s;
			else ans+=r/s-l/s;
		}
		return;
	}
	work(x+1,tot+1,s*p[x]);
	work(x+1,tot,s);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll a,m;
		scanf("%lld%lld",&a,&m);
		ll q=__gcd(a,m);
		if(a%q==0) l=a;
		else l=a-a%q+q;
		if((a+m-1)%q==0) r=a+m-1;
		else r=a+m-1-(a+m-1)%q;
		l/=q,r/=q,m/=q;
		ans=r-l+1;
		cnt=0;
		for(ll i=2;i*i<=m;i++)
			if(m%i==0)
			{
				p[++cnt]=i;
				while(m%i==0) m/=i;
			}
		if(m!=1) p[++cnt]=m;
		work(1,0,1);
		printf("%lld\n",ans);
	}
	return 0;
}