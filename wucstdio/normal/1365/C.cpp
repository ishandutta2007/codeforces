#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a[200005],b[200005],p[200005],cnt[400005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	for(int i=1;i<=n;i++)p[a[i]]=i;
	for(int i=1;i<=n;i++)
	{
		b[i]=p[b[i]];
		cnt[(b[i]-i+n)%n]++;
	}
	int ans=0;
	for(int i=0;i<n;i++)ans=max(ans,cnt[i]);
	printf("%d\n",ans);
	return 0;
}