#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a[400005],sum[40000005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	int ans=0;
	for(int d=24;d>=0;d--)
	{
		for(int i=0;i<(1<<(d+1));i++)sum[i]=0;
		for(int i=1;i<=n;i++)sum[a[i]]++;
		for(int i=1;i<(1<<(d+1));i++)sum[i]+=sum[i-1];
		long long cnt=0;
		for(int i=1;i<=n;i++)
		{
			if((1<<d)&a[i])
			{
				cnt+=sum[(1<<d)-((1<<d)^a[i])-1];
				cnt+=sum[(1<<(d+1))-1]-sum[(1<<d)|((1<<d)-((1<<d)^a[i])-1)];
			}
			else
			{
				cnt+=sum[(1<<d)+(1<<d)-a[i]-1]-sum[(1<<d)-a[i]-1];
			}
		}
		for(int i=1;i<=n;i++)
		  if((a[i]<<1)&(1<<d))
		    cnt--;
		cnt>>=1;
		if(cnt&1)ans+=1<<d;
		for(int i=1;i<=n;i++)
		  if(a[i]&(1<<d))a[i]^=1<<d;
	}
	printf("%d\n",ans);
	return 0;
}