#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,k,a[N];
long long p[N],ans;
void sol()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	ans=0;
	if(k>n)
	{
		for(int i=1;i<=n;i++)
			a[i]+=k-n;
		k=n;
	}
	for(int i=1;i<=n;i++)
		p[i]=p[i-1]+a[i];
	for(int i=1;i<=n;i++)
		ans=max(ans,p[i]-p[max(0,i-k)]);
	ans+=1ll*k*(k-1)/2;
	printf("%lld\n",ans);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}