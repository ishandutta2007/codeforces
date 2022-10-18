#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[100005];
ll b[100005];
bool cmp(ll x,ll y)
{
	return x>y;
}
int main()
{
	ll n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&b[i]);
	}
	sort(a+1,a+n+1,cmp);
	sort(b+1,b+n+1,cmp);
	int ta=1,tb=1;
	ll aa=0,ab=0;
	for(int i=1;i<=n;i++)
	{
		if(ta<=n&&tb<=n)
		{
			if(a[ta]<b[tb])
			{
				tb++;
			}
			else
			{
				aa+=a[ta++];
			}
		}
		else if(ta==n+1)
		{
			tb++;
		}
		else
		{
			aa+=a[ta++];
		}
		if(ta<=n&&tb<=n)
		{
			if(a[ta]>b[tb])
			{
				ta++;
			}
			else
			{
				ab+=b[tb++];
			}
		}
		else if(ta==n+1)
		{
			ab+=b[tb++];
		}
		else
		{
			ta++;
		}
	}
	cout<<aa-ab<<endl;
	return 0;
}