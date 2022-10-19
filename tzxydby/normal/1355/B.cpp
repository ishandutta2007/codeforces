#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int t,n,a[N];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		int ans=0,las=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)
		{
			if(i-las>=a[i])
			{
				las=i;
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}