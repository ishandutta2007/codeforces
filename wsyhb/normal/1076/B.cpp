#include<bits/stdc++.h>
using namespace std;
long long _(long long x)
{
	for(long long i=2;i<=sqrt(x);i++)
		if(x%i==0) return i;
	return x;
}
int main()
{
	long long n,ans=0;
	cin>>n;
	if(n%2==1) n-=_(n),ans=1;
	ans+=n/2;
	cout<<ans;
	return 0;
}