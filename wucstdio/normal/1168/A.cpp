#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,a[300005];
bool check(int x)
{
	int now=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]+x<m)
		{
			if(a[i]+x<now)return 0;
			else now=max(now,a[i]);
		}
		else
		{
			if((a[i]+x)%m<now)
			  now=max(now,a[i]);
		}
	}
	return 1;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	int l=0,r=m;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",l);
	return 0;
}