#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,a[200005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			ans=max(ans,a[i]);
		}
		int cnt=0;
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)
		  if(ans%a[i]!=0)cnt++;
		bool flag1=0,flag2=0,flag3=0;
		for(int i=1;i<n;i++)
		{
			if(a[i]*2==ans)flag1=1;
			if(a[i]*3==ans)flag2=1;
			if(a[i]*5==ans)flag3=1;
		}
		if(flag1&&flag2&&flag3)ans=ans/2+ans/3+ans/5;
		if(cnt==0)
		{
			printf("%d\n",ans);
			continue;
		}
		for(int i=1;i<=n;i++)
		  if(a[n]%a[i]!=0)ans=max(ans,a[n]+a[i]);
		int an=a[n];
		for(int i=1;i<=n;i++)
		  if(a[n]%a[i]==0)a[i]=2000000000;
		sort(a+1,a+n+1);
		while(a[n]==2000000000)n--;
		for(int i=1;i<=n;i++)
		  if(a[n]%a[i]!=0)ans=max(ans,an+a[n]+a[i]);
		ans=max(ans,a[n]+an);
		printf("%d\n",ans);
	}
	return 0;
}