#include <stdio.h>
const int L=18;
#define ll long long
ll pow(ll x, int k){ ll ret=1;for(;k;k>>=1,x*=x) if(k&1) ret*=x;return ret;}
ll cnt(ll l, ll r){ return r-l+1;}
ll max(ll a, ll b){ return a>b?a:b;}
ll min(ll a, ll b){ return a>b?b:a;}
bool check(int x){ return x/10==x%10 || x<10;}
int main()
{
	ll l,r;
	scanf("%lld %lld",&l,&r);
	ll sol=0,i,j;
	ll d=1;
	for(i=1;i<=L;i++) d*=10;
	for(j=L;j>1;j--)
	{
		for(i=max(1,l/d);i<=min(9,r/d);i++)
		{
			if(i!=r/d && i!=l/d) sol+=d/10;
			else if(i!=l/d) sol+=cnt(0,(r%d)/10);
			else if(i!=r/d) sol+=cnt((l%d)/10,d/10-1);
			else sol+=cnt((l%d)/10,(r%d)/10);
			if(i==l/d && i<l%10) sol--;
			if(i==r/d && i>r%10) sol--;
		}
		d/=10;
	}
	for(i=1;i<100;i++) if(l<=i && r>=i && check(i)) sol++;
	printf("%lld\n",sol);
	return 0;
}