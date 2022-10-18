#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll t[2005][2005];
ll b[2005];
ll c[2005];
ll a[2005][2005];
ll sa[2005];
ll sb[2005];
ll ta[2005];
ll tb[2005];
int main()
{
	int n,m;
	cin>>n>>m;
	ll x;
	for(int i=1;i<=n;i++)
	{
		scanf("%I64d",&b[i]);
		sa[i]=sa[i-1]+b[i];
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%I64d",&c[i]);
		sb[i]=sb[i-1]+c[i];
	}
	cin>>x;
	for(int i=1;i<=n;i++)
	{
		ta[i]=sa[i];
		for(int j=1;j<=n;j++)
		{
			if(i+j>n)
			{
				break;
			}
			if(sa[j+i]-sa[j]<ta[i])
			{
				ta[i]=sa[j+i]-sa[j];
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		tb[i]=sb[i];
		for(int j=1;j<=m;j++)
		{
			if(i+j>m)
			{
				break;
			}
			if(sb[j+i]-sb[j]<tb[i])
			{
				tb[i]=sb[j+i]-sb[j];
			}
		}
	}
	ll maxn=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(ta[i]*tb[j]<=x)
			{
				if(i*j>maxn)
				{
					maxn=i*j;
				}
			}
		}
	}
	cout<<maxn<<endl;
	return 0;
}