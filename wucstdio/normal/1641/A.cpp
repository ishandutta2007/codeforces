#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int t,n;
bool flag[1000005];
ll a[200005],x;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%lld",&n,&x);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			flag[i]=0;
		}
		sort(a+1,a+n+1);
		a[n+1]=-1;
		int ans=0;
		for(int i=1,j=1;i<=n;i++)
		{
			if(flag[i])continue;
			while(j<=n&&a[j]<a[i]*x)j++;
			if(a[j]==a[i]*x)flag[j]=1,j++;
			else ans++;
			flag[i]=1;
		}
		printf("%d\n",ans);
	}
	return 0;
}