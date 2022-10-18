#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	int n;
	cin>>n;
	ll s,a,b,c;
	for(int i=1;i<=n;i++)
	{
		scanf("%I64d %I64d %I64d %I64d",&s,&a,&b,&c);
		ll t=s/c;
		ll sum=t/a*b;
		printf("%I64d\n",sum+t);
	}
	return 0;
}