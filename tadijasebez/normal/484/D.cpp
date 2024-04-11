#include <stdio.h>
#define ll long long
const int N=1000050;
ll max(ll a, ll b){ return a>b?a:b;}
ll tmp,Best1,Best2,x[N],ans;
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%lld",&x[i]);
	Best1=-x[1];
	Best2=x[1];
	for(i=1;i<=n;i++)
	{
		tmp=max(Best1+x[i],Best2-x[i]);
		ans=max(ans,tmp);
		Best1=max(Best1,tmp-x[i+1]);
		Best2=max(Best2,tmp+x[i+1]);
	}
	printf("%lld\n",ans);
	return 0;
}