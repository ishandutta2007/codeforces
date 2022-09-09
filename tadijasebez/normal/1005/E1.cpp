#include <stdio.h>
#define ll long long
const int N=200050;
const int M=2*N;
int cnt[M],a[N];
int main()
{
	int n,m,i,s;
	scanf("%i %i",&n,&m);
	for(i=1;i<=n;i++) scanf("%i",&a[i]),s=(a[i]==m?i:s);
	int sum=0;
	for(i=s;i;i--)
	{
		if(a[i]<m) sum--;
		if(a[i]>m) sum++;
		cnt[sum+N]++;
	}
	sum=0;
	ll ans=0;
	for(i=s;i<=n;i++)
	{
		if(a[i]<m) sum--;
		if(a[i]>m) sum++;
		ans+=cnt[N-sum];
		ans+=cnt[N-sum+1];
	}
	printf("%lld\n",ans);
	return 0;
}