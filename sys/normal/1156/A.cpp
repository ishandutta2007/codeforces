#include <bits/stdc++.h>
using namespace std;
int n,ans,las,a[105];
int main()
{
	scanf("%d",&n);
	scanf("%d",&a[1]);
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(((a[i]!=1)^(a[i-1]!=1))==0)
		{
			printf("Infinite\n");
			return 0;
		}
		if(a[i]==1)
			ans+=a[i-1]+1;
		if(a[i-1]==1)
		{
			ans+=a[i]+1;
			if(a[i]==2&&a[i-2]==3) ans--;
		}
	}
	printf("Finite\n%d",ans);
	return 0;
}