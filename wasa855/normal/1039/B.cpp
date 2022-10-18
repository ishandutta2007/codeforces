#include<bits/stdc++.h>
using namespace std;
#define ll long long
char a[10];
#define max iujaohfdsnc
#define min aiwskdngcir
ll max(ll x,ll y)
{
	return x>y?x:y;
}
ll min(ll x,ll y)
{
	return x<y?x:y;
}
bool query(ll x,ll y)
{
	printf("%lld %lld\n\n",x,y);
	fflush(stdout);
	scanf("%s",a);
	if(a[0]=='Y')
	{
		return true;
	}
	return false;
}
int main()
{
	srand(time(NULL));
	ll n,k;
	cin>>n>>k;
	ll l=1,r=n;
	while(1)
	{
		while(r-l>40)
		{
			ll mid=(l+r+1)/2;
			if(query(l,mid)==true)
			{
				r=mid;
			}
			else
			{
				l=mid+1;
			}
			l=max(1,l-k);
			r=min(n,r+k);
		}
		ll t=rand()%(r-l+1)+l;
		if(query(t,t)==true)
		{
			return 0;
		}
		l=max(1,l-k);
		r=min(n,r+k);
	}
	return 0;
}