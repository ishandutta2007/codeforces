#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int n,a[100005],b[100005],sa[100005];
bool cmp(int x,int y)
{
	return a[x]-b[x]>a[y]-b[y];
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
		sa[i]=i;
	}
	sort(sa+1,sa+n+1,cmp);
	ll ans=0;
	for(int i=1;i<=n;i++)
	  ans+=1ll*a[sa[i]]*(i-1)+1ll*b[sa[i]]*(n-i);
	printf("%I64d\n",ans);
	return 0;
}