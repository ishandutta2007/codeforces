#include <stdio.h>
#include <map>
using namespace std;
#define ll long long
const int mod=998244353;
const ll inf=9e18;
ll min(ll a, ll b){ return a>b?b:a;}
int pow(int x, int k)
{
	int ret=1;
	for(;k;k>>=1,x=(ll)x*x%mod) if(k&1) ret=(ll)ret*x%mod;
	return ret;
}
int rev(int x)
{
	int y=0;
	while(x) y*=10,y+=x%10,x/=10;
	return y;
}
map<int,int> cnt[2];
const int N=100050;
int val[N],inv[N];
int main()
{
	int n,m,w,i,j,x,y;
	ll sol=inf;
	scanf("%i %i %i",&n,&m,&w);
	for(i=1;i<N;i++) val[i]=(ll)i*pow(rev(i),mod-2)%mod,inv[i]=pow(val[i],mod-2);
	for(i=1;i<=m;i++) cnt[1][val[i]]++;
	j=m;
	ll sum=0;
	for(i=1;i<=n;i++)
	{
		sum+=cnt[1][inv[i]];
		cnt[0][val[i]]++;
		while(j && sum-cnt[0][inv[j]]>=w) cnt[1][val[j]]--,sum-=cnt[0][inv[j]],j--;
		//printf("%lld %i %i\n",sum,i,j);
		if(sum>=w)
		{
			sol=min(sol,(ll)i*j);
			if(sol==(ll)i*j)
			{
				x=i;
				y=j;
			}
		}
	}
	if(sol==inf) printf("-1\n");
	else printf("%i %i\n",x,y);
	return 0;
}