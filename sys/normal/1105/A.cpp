#include <bits/stdc++.h>
using namespace std;
int n,a[1005],ans=0x3f3f3f3f,t,now;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=101;i++)
	{
		now=0;
		for(int j=1;j<=n;j++)
			now+=min(abs(a[j]-i),min(abs(a[j]-(i-1)),abs(a[j]-(i+1))));
		if(now<ans)
		{
			ans=now;
			t=i;
		}
	}
	printf("%d %d",t,ans);
	return 0;
}