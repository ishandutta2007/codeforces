#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int t,n,k,a[100005],pre[100005],suf[100005],m1[100005],m2[100005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]<k)a[i]=-1;
			else if(a[i]==k)a[i]=0;
			else a[i]=1;
		}
		bool flag=0;
		bool f2=0;
		a[0]=-1,a[n+1]=-1;
		for(int i=1;i<=n;i++)
		{
			if(a[i])continue;
			f2=1;
			if(a[i-1]>=0||a[i+1]>=0)flag=1;
		}
		if(!f2)
		{
			printf("no\n");
			continue;
		}
		if(n==1)
		{
			printf("yes\n");
			continue;
		}
		if(flag)
		{
			printf("yes\n");
			continue;
		}
		for(int i=1;i<=n-2;i++)
		{
			int cnt=0;
			cnt+=(a[i]>=0);
			cnt+=(a[i+1]>=0);
			cnt+=(a[i+2]>=0);
			if(cnt>=2)flag=1;
		}
		if(flag)
		{
			printf("yes\n");
			continue;
		}
		printf("no\n");
	}
	return 0;
}