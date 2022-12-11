#include<bits/stdc++.h>
#define ll long long
using namespace std;
int q;
ll query(ll n)
{
	if(n%2==0)return n/2;
	else return (n-1)/2-n;
}
int main()
{
	scanf("%d",&q);
	while(q--)
	{
		ll l,r;
		scanf("%I64d%I64d",&l,&r);
		ll ans=query(r)-query(l-1);
		printf("%I64d\n",ans);
	}
	return 0;
}