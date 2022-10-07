#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,a[300005],sa[300005],pre[300005],suf[300005];
bool cmp(int x,int y)
{
	return a[x]<a[y]||(a[x]==a[y]&&x<y);
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			sa[i]=i;
		}
		sort(sa+1,sa+n+1,cmp);
		for(int i=1;i<=n;i++)
		{
			if(a[sa[i]]==a[sa[i-1]])pre[i]=pre[i-1];
			else pre[i]=pre[i-1]+1;
		}
		for(int i=n;i>=1;i--)
		{
			if(i==n)suf[i]=1;
			else
			{
				if(a[sa[i]]==a[sa[i+1]])suf[i]=suf[i+1];
				else suf[i]=suf[i+1]+1;
			}
		}
		int ans=n;
		for(int i=1;i<=n;)
		{
			int j=i+1;
			while(j<=n&&sa[j]>sa[j-1])j++;
			ans=min(ans,pre[i-1]+suf[j]);
			i=j;
		}
		printf("%d\n",ans);
		for(int i=1;i<=n;i++)a[i]=pre[i]=suf[i]=sa[i]=0;
	}
	return 0;
}