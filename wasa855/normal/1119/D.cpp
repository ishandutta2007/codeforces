#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100005];
int dat[100005];
int sum[100005];
signed main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%I64d",&a[i]);
	}
	sort(a+1,a+n+1);
	int maxd=0;
	for(int i=2;i<=n;i++)
	{
		dat[i]=a[i]-a[i-1]-1;
		maxd=max(maxd,dat[i]+1);
	}
	sort(dat+2,dat+n+1);
	for(int i=2;i<=n;i++)
	{
		sum[i]=sum[i-1]+dat[i];
	}
	int m;
	cin>>m;
	int l,r;
	for(int i=1;i<=m;i++)
	{
		scanf("%I64d %I64d",&l,&r);
		int ans=a[n]-a[1]+r-l+1;
		if(maxd<r-l+1)
		{
			printf("%I64d ",ans);
		}
		else
		{
			int mi=lower_bound(dat+2,dat+n+1,r-l+1)-dat;
			ans-=sum[n]-sum[mi-1]-(r-l)*(n-mi+1);
			printf("%I64d ",ans);
		}
	}
	return 0;
}
// REjudge