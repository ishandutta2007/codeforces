#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a[100005],sa[100005];
bool cmp(int x,int y)
{
	return a[x]>a[y];
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		sa[i]=i;
	}
	sort(sa+1,sa+n+1,cmp);
	int ans=0;
	for(int i=1;i<=n;i++)
	  ans+=(i-1)*a[sa[i]]+1;
	printf("%d\n",ans);
	for(int i=1;i<=n;i++)printf("%d ",sa[i]);
	printf("\n");
	return 0;
}