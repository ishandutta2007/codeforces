#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int t,n;
ll x,a[100005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%lld",&n,&x);
		for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
		sort(a+1,a+n+1);
		int ans=2;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==x)
			{
				ans=1;
				break;
			}
		}
		if(a[n]*2>=x)ans=min(ans,2);
		else ans=(int)(x-1)/(int)a[n]+1;
		printf("%d\n",ans);
	}
	return 0;
}