#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a[300005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int ans=0;
	for(int i=2;i<=n;i++)
	{
		if(a[i]!=a[1])ans=max(ans,i-1);
		if(a[i]!=a[n])ans=max(ans,n-i);
	}
	printf("%d\n",ans);
	return 0;
}