#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,a[300005],pre[300005],suf[300005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		pre[0]=-1;
		for(int i=1;i<=n;i++)
		{
			if(a[i]<=pre[i-1])pre[i]=2147483647;
			else pre[i]=pre[i-1]+1;
		}
		suf[n+1]=-1;
		for(int i=n;i>=1;i--)
		{
			if(a[i]<=suf[i+1])suf[i]=2147483647;
			else suf[i]=suf[i+1]+1;
		}
		bool f=0;
		for(int i=1;i<=n;i++)
		  if(pre[i-1]<a[i]&&suf[i+1]<a[i])
		    f=1;
		puts(f?"Yes":"No");
	}
	return 0;
}