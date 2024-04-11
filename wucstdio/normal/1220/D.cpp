#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int n,ans,val=1000000000;
ll a[200005],b[200005];
bool flag[200005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)b[i]=a[i];
	int now=0;
	for(int o=0;o<=64;o++)
	{
		int res=0;
		for(int i=1;i<=n;i++)
		  if(flag[i]==0&&a[i]%2==0)
		    res++;
		if(val>now+res)
		  val=now+res,ans=o;
		for(int i=1;i<=n;i++)
		{
			if(flag[i])continue;
			if(a[i]&1)
			{
				now++;
				flag[i]=1;
			}
			a[i]/=2;
		}
	}
	printf("%d\n",val);
	for(int i=1;i<=n;i++)a[i]=b[i];
	memset(flag,0,sizeof(flag));
	for(int o=0;o<=ans;o++)
	{
		if(o==ans)
		{
			for(int i=1;i<=n;i++)
			  if(flag[i]==0&&a[i]%2==0)
			    flag[i]=1;
			break;
		}
		for(int i=1;i<=n;i++)
		{
			if(flag[i])continue;
			if(a[i]&1)flag[i]=1;
			a[i]/=2;
		}
	}
	for(int i=1;i<=n;i++)
	  if(flag[i])printf("%lld ",b[i]);
	printf("\n");
	return 0;
}