#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a[200005],cnt[200005],ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		cnt[a[i]]++;
		if(cnt[a[i]]>cnt[ans])ans=a[i];
	}
	printf("%d\n",n-cnt[ans]);
	a[0]=-1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=ans&&a[i-1]==ans)
		{
			if(a[i]<a[i-1])printf("1 %d %d\n",i,i-1);
			else printf("2 %d %d\n",i,i-1);
			a[i]=ans;
		}
	}
	a[n+1]=-1;
	for(int i=n;i>=1;i--)
	{
		if(a[i]!=ans&&a[i+1]==ans)
		{
			if(a[i]<a[i+1])printf("1 %d %d\n",i,i+1);
			else printf("2 %d %d\n",i,i+1);
			a[i]=ans;
		}
	}
	return 0;
}