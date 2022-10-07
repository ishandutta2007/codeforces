#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int t,n;
ll a[505],b[505],tmp[505];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
		for(int i=1;i<=n;i++)scanf("%lld",&b[i]);
		if(n&1)
		{
			if(a[n/2+1]!=b[n/2+1])
			{
				printf("No\n");
				continue;
			}
		}
		int top=0;
		for(int i=1;i<=n/2;i++)a[++top]=min(a[i],a[n-i+1])*1000000001+max(a[i],a[n-i+1]);
		top=0;
		for(int i=1;i<=n/2;i++)b[++top]=min(b[i],b[n-i+1])*1000000001+max(b[i],b[n-i+1]);
		sort(a+1,a+top+1);
		sort(b+1,b+top+1);
		bool f=1;
		for(int i=1;i<=top;i++)
		  if(a[i]!=b[i])f=0;
		if(f)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}