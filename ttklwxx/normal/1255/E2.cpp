#include<iostream>
#include<cstdio>
#define int long long
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
int a[1000001],n;
int check(int k)
{
	int sum=0,ans=0;
	for(int i=1;i<=n;i++)
	{
		sum=(sum+a[i])%k;
		ans+=min(sum,k-sum);
	}
	return ans;
}
signed main()
{
    int sum=0,ans=1000000000000000000LL;
    n=read();
    for(int i=1;i<=n;i++)
    {
    	a[i]=read();
    	sum+=a[i];
	}
	if(sum<=1)
	{
		printf("-1\n");
		return 0;
	}
	for(int i=2;i*i<=sum;i++)
	{
		if(sum%i!=0)continue;
		while(sum%i==0)sum/=i;
		ans=min(ans,check(i));
	}
	if(sum>1)ans=min(ans,check(sum));
	printf("%I64d\n",ans);
    return 0;
}