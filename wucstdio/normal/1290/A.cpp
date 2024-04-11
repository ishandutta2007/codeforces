#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,m,k,a[3505];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		k=min(k,m-1);
		int ans=0;
		for(int l=0;l<=k;l++)
		{
			int r=k-l;
			int v=2147483647;
			for(int i=0;i+k<=m-1;i++)
			{
				int j=m-1-i-k;
				v=min(v,max(a[l+i+1],a[n-r-j]));
			}
			ans=max(ans,v);
		}
		printf("%d\n",ans);
	}
	return 0;
}