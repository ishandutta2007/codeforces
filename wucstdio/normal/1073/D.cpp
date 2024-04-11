#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define ll long long
using namespace std;
ll n,t,a[200005],sum,ans;
bool flag[200005];
int main()
{
	scanf("%I64d%I64d",&n,&t);
	for(int i=1;i<=n;i++)
	  scanf("%I64d",&a[i]);
	ll rest=n;
	while(rest)
	{
		sum=0;
		int num=0;
		for(int i=1;i<=n;i++)
		{
			if(flag[i])continue;
			if(sum+a[i]>t)
			{
				flag[i]=1;
				rest--;
			}
			else
			{
				sum+=a[i];
				num++;
			}
		}
		if(sum==0)break;
		ans+=t/sum*num;
		t%=sum;
	}
	printf("%I64d\n",ans);
	return 0;
}