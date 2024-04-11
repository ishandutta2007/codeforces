#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,a[100005],sum[100005],ans;
int main()
{
	scanf("%d%d",&n,&m);
	n+=2;
	for(int i=2;i<n;i++)
	  scanf("%d",&a[i]);
	a[n]=m;
	for(int i=2;i<=n;i+=2)
	{
		ans+=a[i]-a[i-1];
		sum[i]=sum[i-1]+a[i]-a[i-1];
		sum[i+1]=sum[i];
	}
	for(int i=2;i<=n;i+=2)
	  if(a[i]-a[i-1]>1||a[i+1]-a[i]>1)
		ans=max(ans,a[n]-a[i]-sum[n]+sum[i]+sum[i]-1);
	printf("%d\n",ans);
	return 0;
}