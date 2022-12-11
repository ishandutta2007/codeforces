#include <bits/stdc++.h>
#define Maxn 100007
using namespace std;
int n,k;
int a[Maxn];
int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<n;i++)
	{
		scanf("%d",&a[i]);
		a[i]+=a[i-1];
	}
	int ans=a[n-1];
	for (int i=k;i<n;i++)
		ans=min(ans,a[i]-a[i-k]);
	printf("%d\n",ans);
	return 0;
}