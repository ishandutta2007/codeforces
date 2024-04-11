#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	ll p,q,b;
	int n;
	scanf("%i",&n);
	while(n--)
	{
		scanf("%lld %lld %lld",&p,&q,&b);
		q/=__gcd(p,q);
		while(q>1)
		{
			ll g=__gcd(q,b);
			if(g==1) break;
			q/=g;
			b=g;
		}
		if(q==1) cout << "Finite\n";//printf("Finite\n");
		else cout << "Infinite\n";//printf("Infinite\n");
	}
	return 0;
}