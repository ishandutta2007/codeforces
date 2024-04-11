#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	int T;
	cin>>T;
	ll a,b,c,d;
	for(int i=1;i<=T;i++)
	{
		scanf("%I64d %I64d %I64d %I64d",&a,&b,&c,&d);
		ll t=a/b;
		t-=d/b;
		t+=(c-1)/b;
		printf("%I64d\n",t);
	}
	return 0;
}