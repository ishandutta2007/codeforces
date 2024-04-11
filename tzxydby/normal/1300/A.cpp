#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int a[N],n,t;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int ans=0,sum=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if(!a[i])
				a[i]++,ans++;
			sum+=a[i];
		}
		if(!sum)
			ans++;
		printf("%d\n",ans);
	}
	return 0;
}