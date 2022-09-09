#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=300050;
ll p[N],x[N];
int main()
{
	int n,m,i;
	scanf("%i %i",&n,&m);
	for(i=1;i<=n;i++) scanf("%lld",&x[i]);
	ll g=0;
	for(i=2;i<=n;i++) g=__gcd(g,x[i]-x[i-1]);
	bool ok=0;
	int id;
	for(i=1;i<=m;i++)
	{
		scanf("%lld",&p[i]);
		if(g%p[i]==0)
		{
			ok=1;
			id=i;
		}
	}
	if(!ok) printf("NO\n");
	else printf("YES\n%lld %i\n",x[1],id);
	return 0;
}