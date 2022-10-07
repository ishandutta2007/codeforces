#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
struct Node
{
	ll a,b;
}a[7005];
int n;
ll f[7005];
bool flag[7005];
bool cmp(Node a,Node b)
{
	return a.a>b.a;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i].a);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i].b);
	sort(a+1,a+n+1,cmp);
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<i;j++)
		{
			if(flag[j]&&(a[j].a&a[i].a)==a[i].a)
			{
				flag[i]=1;
				break;
			}
			if(a[j].a==a[i].a)
			{
				flag[i]=1;
				break;
			}
		}
		if(i!=n&&a[i+1].a==a[i].a)flag[i]=1;
		if(flag[i])ans+=a[i].b;
	}
	printf("%lld\n",ans);
	return 0;
}