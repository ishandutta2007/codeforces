#include <bits/stdc++.h>
using namespace std;
const int Maxn=200005;
int h[Maxn],n,now;
long long ans,k,tot;
int main()
{
	scanf("%d%lld",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&h[i]);
	sort(h+1,h+1+n);
	for(int i=h[n],now=n;i>=1;i--)
	{
		while(i<=h[now-1]) now--;
		if(now==1) break;
		tot+=n-now+1;
		if(tot>k) ans++,tot=n-now+1;
	}
	printf("%lld",ans+(tot!=0));
	return 0;
}