#include<bits/stdc++.h>
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;
const int N=2e5+5;
int a[N];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",a+i);
		long long ans=0;
		int now=a[1];
		for(int i=2;i<=n;i++)
		{
			if(1ll*a[i-1]*a[i]<0)
			{
				ans+=now;
				now=-15e8;
			}
			now=max(now,a[i]);
		}
		ans+=now;
		printf("%lld\n",ans);
	} 
	return 0;
}