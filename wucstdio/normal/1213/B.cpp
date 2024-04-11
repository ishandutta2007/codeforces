#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,a[1000005],minv;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		minv=1000000000;
		int ans=0;
		for(int i=n;i>=1;i--)
		{
			if(minv<a[i])ans++;
			minv=min(minv,a[i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}