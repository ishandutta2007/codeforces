#include <stdio.h>
#define ll long long
int n,i=0;
ll c1,c2,ca=0,cp=0;
char buf[233333];
int main()
{
	scanf("%d%lld%lld%s",&n,&c1,&c2,buf);
	for(i=0;buf[i];++i)
		cp+=buf[i]=='0',ca+=buf[i]=='1';
	ll ans=1e18;
	for(i=1;i<=ca;i++)
	{
		ll q=n/i,y=n%i;
		ll ca=(q-1)*(q-1)*c2*i+c1*i
		+(q*q-(q-1)*(q-1))*y*c2;
		(ca<ans)?(ans=ca):0;
	}
	printf("%lld\n",ans);
}