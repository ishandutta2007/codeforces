#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	int n,m,t;
	scanf("%i",&t);
	while(t--)
	{
		scanf("%i %i",&n,&m);
		ll x=round(cbrt((ll)n*m));
		if(x*x*x==(ll)n*m && n%x==0 && m%x==0) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}