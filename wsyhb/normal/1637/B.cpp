#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int ans=n*(n+1)*(n+2)/6;
		for(int i=1;i<=n;++i)
		{
			int a;
			scanf("%d",&a);
			if(!a)
				ans+=i*(n-i+1);
		}
		printf("%d\n",ans);
	}
	return 0;
}