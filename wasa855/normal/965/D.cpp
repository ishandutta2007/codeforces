#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[100005];
int main()
{
	ll m,n;
	cin>>m>>n;
	for(ll i=1;i<m;i++)
	{
		scanf("%d",&a[i]);
	}
	ll sum=0,maxn=0x7fffffff;
	for(ll i=1;i<=n;i++)
	{
		sum+=a[i];
	}
	maxn=min(maxn,sum);
	for(ll i=n+1;i<m;i++)
	{
		sum=sum-a[i-n]+a[i];
		maxn=min(maxn,sum);
	}
	cout<<maxn<<endl;
	return 0;
}