#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[200005];
int main()
{
	ll n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%I64d",&a[i]);
	}
	ll lsum=0;
	ll rsum=0;
	ll maxn=0;
	int l=1,r=n;
	while(l<=r)
	{
		if(lsum>rsum)
		{
			rsum+=a[r--];
		}
		else
		{
			lsum+=a[l++];
		}
		if(lsum==rsum)
		{
			maxn=lsum;
		}
	}
	cout<<maxn<<endl;
	return 0;
}