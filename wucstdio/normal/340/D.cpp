#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a[100005],f[100005],g[100005],ans=1;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	  scanf("%d",&a[i]);
	f[1]=1;
	memset(g,0x7f,sizeof(g));
	g[1]=a[1];
	g[0]=0;
	for(int i=2;i<=n;i++)
	{
		int l=0,r=i-1;
		while(l<=r)
		{
			int mid=l+r>>1;
			if(g[mid]<a[i])l=mid+1;
			else r=mid-1;
		}
		f[i]=r+1;
		g[f[i]]=min(g[f[i]],a[i]);
		ans=max(ans,f[i]);
	}
	printf("%d\n",ans);
	return 0;
}