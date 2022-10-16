#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n;
	cin>>n;
	vector<long long> a(n),b(n),c(n);
	for(long long i=0;i<n;i++) cin>>a[i];
	for(long long i=0;i<n;i++) 
	{
	cin>>b[i];
	c[i]=a[i]-b[i];
	}
	sort(c.begin(),c.end());
	long long ans=0;
	for(long long i=0;i<n;i++)
	{
		if(c[i]>0) 
		{
			long long p= lower_bound(c.begin(),c.end(),-c[i]+1)-c.begin();
			ans+=i-p;
		}
	}
	cout<<ans;
}