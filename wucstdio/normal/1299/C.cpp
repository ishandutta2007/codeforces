#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int n,len[1000005],top;
ll a[1000005],sum[1000005],s2[1000005];
double st[1000005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		sum[i]=sum[i-1]+a[i];
	}
	st[0]=1e18;
	for(int i=n;i>=1;i--)
	{
		double v=a[i];
		ll s=a[i];
		int l=1;
		while(v>st[top])
		{
			s+=s2[top];
			l+=len[top];
			top--;
			v=s*1.0/l;
		}
		st[++top]=v;
		len[top]=l;
		s2[top]=s;
	}
	for(int i=1;i<=n;i++)
	{
		if(len[top]==0)top--;
		printf("%.12lf\n",st[top]);
		len[top]--;
	}
	return 0;
}