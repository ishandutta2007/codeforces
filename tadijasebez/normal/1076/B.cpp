#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool tst=0;
int main()
{
	ll n,d,i;
	if(tst)
	{
		int Test=1000;
		srand(time(0));
		while(Test)
		{
			n=rand()%15+2;
			d=n;
			for(i=2;i*i<=n;i++) if(n%i==0){ d=i;break;}
			ll ans=n/d,sol=0;
			ll tmp=n;
			while(n>0)
			{
				for(i=2;i*i<=n;i++) if(n%i==0){ d=i;break;}
				n-=i;
				sol++;
			}
			if(sol!=ans) printf("%lld sol:%lld ans:%lld\n",tmp,sol,ans);
		}
		return 0;
	}
	scanf("%lld",&n);
	d=n;
	for(i=2;i*i<=n;i++) if(n%i==0){ d=i;break;}
	if(d!=2) printf("%lld\n",1+((n-d)/2));
	else printf("%lld\n",n/d);
	return 0;
}