#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const double Pi=3.1415926535897932384626;
int n,d,m,a[200005];
int main()
{
	scanf("%d%d",&n,&d);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	int now=0;
	scanf("%d",&m);
	while(m--)
	{
		int x;
		scanf("%d",&x);
		while(now<n&&a[now+1]<x)now++;
		if(a[now]==x-1&&a[now+1]==x)
		{
			printf("%.11lf\n",Pi);
			continue;
		}
		else if(a[now]==x-1||a[now+1]==x)
		{
			printf("%.11lf\n",Pi/2);
			continue;
		}
		int pl=now;
		double ans=0;
		if(now!=n)ans=max(ans,atan2(1.0,a[now+1]-x));
		if(now!=0)ans=max(ans,atan2(1.0,x-a[now]-1));
		int d=min(a[now+1]-x,x-a[now]-1);
		int pr=now+1;
		while(pr<=n&&pl>=1&&a[pr]-a[pl]<=(d+5)*4)
		{
			int dis1=a[pr]-x,dis2=x-a[pl]-1;
			if(dis1==dis2+1||dis2==dis1+1||dis1==dis2)
			{
				ans=max(ans,atan2(1.0,max(dis1,dis2))*2);
				break;
			}
			if(dis1<dis2)pr++;
			else pl--;
		}
		printf("%.11lf\n",ans);
	}
	return 0;
}