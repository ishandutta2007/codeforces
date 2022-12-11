#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,z;
		scanf("%d%d",&n,&z);
		int ans=0;
		for(int i=1;i<=n;++i)
		{
			int a;
			scanf("%d",&a);
			ans=max(ans,a|z);
		}
		printf("%d\n",ans);
	}
	return 0;
}