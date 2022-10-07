#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,a[100005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		int ans=0;
		for(int i=1;i<n;i++)
		  if(a[i]!=-1&&a[i+1]!=-1)
		    ans=max(ans,abs(a[i]-a[i+1]));
		int minv=2147483647,maxv=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==-1)
			{
				if(i!=1&&a[i-1]!=-1)minv=min(minv,a[i-1]),maxv=max(maxv,a[i-1]);
				if(i!=n&&a[i+1]!=-1)minv=min(minv,a[i+1]),maxv=max(maxv,a[i+1]);
			}
		}
		if(minv!=2147483647)printf("%d %d\n",max(ans,(maxv-minv+1)/2),(maxv+minv)/2);
		else printf("%d %d\n",ans,0);
	}
	return 0;
}