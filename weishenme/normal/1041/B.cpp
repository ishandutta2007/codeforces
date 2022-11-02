#include<bits/stdc++.h>
using namespace std;
#define int long long
int a,b,x,y;
signed main()
{
	cin>>a>>b>>x>>y;
	int p=__gcd(x,y);
	x/=p;y/=p;
	printf("%lld",min(a/x,b/y));
}