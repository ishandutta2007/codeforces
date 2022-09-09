#include <stdio.h>
#include <set>
#include <cmath>
using namespace std;
#define ll long long
const ll inf=2e9+7;
set<ll> sq;
set<ll>::iterator it;
int main()
{
	int i,t;
	for(i=2;(ll)i*i<inf;i++) sq.insert(i);
	sq.insert(i);
	scanf("%i",&t);
	while(t--)
	{
		ll x,n,m,y,tmp;
		scanf("%lld",&x);
		if(x==0){ printf("1 1\n");continue;}
		ll X=sqrt(x);
		bool ok=0;
		for(it=sq.upper_bound(X);it!=sq.end();it++)
		{
			n=*it;
			y=n*n-x;
			tmp=sqrt(y);
			//if(n<6) printf("%i %i %i\n",n,y,tmp);
			if(tmp*tmp==y)
			{
				m=n/tmp;
				if(x!=n*n-(n/m)*(n/m)) continue;
				printf("%lld %lld\n",n,n/tmp);
				ok=1;
				break;
			}
		}
		if(!ok) printf("-1\n");
	}
	return 0;
}