#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[200005];
int main()
{
	long long m;
	cin>>m;
	long long total=0;
	long long ans=0;
	for(long long i=1;i<=m;i++)
	{
		scanf("%lld",&a[i]);
		total+=a[i];
	}
	if(total%2==1)
	{
		total++;
	}
	for(long long i=1;i<=m;i++)
	{
		ans+=a[i];
		if(ans>=total/2)
		{
			cout<<i<<endl;
			return 0;
		}
	}
}