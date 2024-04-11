#include <bits/stdc++.h>
using namespace std;
int n,ans[200005];
int main()
{
	scanf("%d",&n);
	if(n&1)
	{
		printf("YES\n");
		for(int i=1;i<=n;i++)
			if(i&1) ans[i]=2*i-1,ans[n+i]=2*i;
			else ans[i]=2*i,ans[n+i]=2*i-1;
		for(int i=1;i<=2*n;i++)
			printf("%d ",ans[i]);
	}
	else printf("NO\n");
	return 0;
}