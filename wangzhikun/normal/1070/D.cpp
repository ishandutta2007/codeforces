#include<cstdio>
using namespace std;
typedef long long ll;
ll n,i,x,ans=0,pre=0,k,sum;
int main()
{
	scanf("%I64d%I64d",&n,&k);
	for(i=1;i<=n;i++)
	{
		scanf("%I64d",&x);
		if(pre)
		{
			sum=pre+x;
			if(sum>=k)
			{
				ans+=sum/k;
				pre=sum%k;
			}
			else 
			{
				ans++;
				pre=0;
			}
		}
		else
		{
			sum=x;
			ans+=sum/k;
			pre=sum%k;
		}
	}
	if(pre)ans++;
	printf("%I64d\n",ans);
	return 0;
}