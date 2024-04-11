#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll n;
	cin>>n;
	if(n<3)
	{
		cout<<"No\n";
		return 0;
	}
	cout<<"Yes\n";
	printf("1 %lld\n",n);
	printf("%lld ",n-1);
	for(int i=1;i<n;i++)
	{
		printf("%lld ",i);
	}
	return 0;
}