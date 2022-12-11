#include<bits/stdc++.h>
using namespace std;
int _(long long x)
{
	int ans=0;
	while(x)
	{
		ans+=x%10;
		x/=10;
	}
	return ans;
}
int main()
{
	long long n,x=9,y;
	cin>>n;
	if(x>=n)
	{
		cout<<n;
		return 0;
	}
	while(x<n) x=x*10+9;
	if(x!=n) x=(x-9)/10;
	y=n-x;
	cout<<_(x)+_(y);
	return 0;
}