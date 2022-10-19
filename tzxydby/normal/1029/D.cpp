#include<bits/stdc++.h>
using namespace std;
const int N=200005;
long long a[N];
long long sum[20][N],w[N];
int main()
{	
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%I64d",&a[i]);
		for(int j=1;j<=18;j++)
		{
			long long x=j,y=a[i];
			while(x--)
				y=(y*10)%k;
			sum[j][i]=y;
		}
		long long y=a[i];
		while(y)
		{
			w[i]++;
			y/=10;
		}
	}
	for(int i=1;i<=18;i++)
		sort(sum[i]+1,sum[i]+n+1);
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		long long x=(k-a[i]%k)%k,y=w[i];
		ans+=upper_bound(sum[y]+1,sum[y]+n+1,x)-lower_bound(sum[y]+1,sum[y]+n+1,x);
		//printf("%d %d %d\n",x,y,ans);
	}
	for(int i=1;i<=n;i++)
	{
		long long y=a[i];
		while(w[i]--)
			y=(y*10)%k;
		y=(a[i]+y)%k;
		if(y%k==0)
			ans--;
	}
	printf("%I64d\n",ans);
	return 0;
}//