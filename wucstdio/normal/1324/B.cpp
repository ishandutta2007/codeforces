#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,pre[5005][5005],suf[5005][5005],a[5005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)pre[i][j]=pre[i-1][j];
			pre[i][a[i]]=1;
		}
		for(int i=1;i<=n;i++)suf[n+1][i]=0;
		for(int i=n;i>=1;i--)
		{
			for(int j=1;j<=n;j++)suf[i][j]=suf[i+1][j];
			suf[i][a[i]]=1;
		}
		bool flag=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(pre[i-1][j]&&suf[i+1][j])
				{
					flag=1;
					break;
				}
			}
		}
		if(flag)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}