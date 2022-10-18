#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ll m,n,t;
	cin>>n>>m;
	ll last=m;
	for(ll i=1;i<=n;i++)
	{
		scanf("%lld",&t);
		if(last>t)
		{
			cout<<"0 ";
			last-=t;
		}
		else if(last==t)
		{
			cout<<"1 ";
			last=m;
		}
		else
		{
			t-=last;
			printf("%lld ",t/m+1);
			last=m-t%m;
		}
//		printf("****%d ",last);
	}
	return 0;
}