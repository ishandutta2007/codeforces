#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
ll n,a[300005],sum[300005],num[300005],ans;
bool judge(int l,int r,ll x)
{
	return 2*x<=sum[r]-sum[l-1];
}
void work(int l,int r)
{
//	printf("Enter:%d %d\n",l,r);
	if(l>=r)return;
	int maxx=l;
	int mid=l+r>>1;
	for(int i=l;i<=r;i++)
	{
		if(a[i]>a[maxx]||a[i]==a[maxx]&&abs(mid-i)<abs(mid-maxx))
		  maxx=i;
	}
	work(l,maxx-1);
	work(maxx+1,r);
	int now=maxx;
	for(int i=l;i<=maxx;i++)
	{
		while(!judge(i,now,a[maxx])&&now<=r)now++;
//		printf("%d %d\n",i,now);
		if(now==r&&!judge(i,now,a[maxx]))break;
		if(sum[i-1]&1)ans+=num[r]-num[now-1];
		else ans+=(r-num[r])-(now-1-num[now-1]);
//	printf("ans=%I64d\n",ans);
	}
//	printf("End:%d %d\n",l,r);
}
int Sum(ll s)
{
	int ans=0;
	while(s)
	{
		if(s&1)ans++;
		s>>=1;
	}
	return ans;
}
int main()
{
	scanf("%I64d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%I64d",&a[i]);
		a[i]=Sum(a[i]);
		sum[i]=sum[i-1]+a[i];
		num[i]=num[i-1];
		if(sum[i]&1)num[i]++;
	}
//	for(int i=1;i<=n;i++)
//	  printf("%I64d ",sum[i]);
//	printf("\n");
//	for(int i=1;i<=n;i++)
//	  printf("%I64d ",num[i]);
//	printf("\n");
	work(1,n);
	printf("%I64d\n",ans);
	return 0;
}