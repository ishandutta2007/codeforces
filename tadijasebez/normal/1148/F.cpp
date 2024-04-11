#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=300050;
ll msk[N],val[N];
int main()
{
	int n;
	scanf("%i",&n);
	ll all=0;
	for(int i=1;i<=n;i++) scanf("%lld %lld",&val[i],&msk[i]),all+=val[i];
	if(all>0) for(int i=1;i<=n;i++) val[i]=-val[i];
	ll ans=0;
	for(ll i=(ll)1<<61;i>0;i>>=1)
	{
		ll tmp=0;
		for(int j=1;j<=n;j++) if((msk[j]&-msk[j])==i) tmp+=val[j];
		if(tmp<0)
		{
			ans+=i;
			for(int j=1;j<=n;j++) if(msk[j]&i) val[j]=-val[j];
		}
	}
	printf("%lld\n",ans);
	return 0;
}