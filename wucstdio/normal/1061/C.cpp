#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const ll MOD=1e9+7;
ll n,f[100005],ans;
int p[100005],top;
int main()
{
	scanf("%I64d",&n);
	f[0]=1;
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		top=0;
		for(int j=1;j*j<=x;j++)
		{
			if(x%j==0)
			{
				p[++top]=j;
				if(x!=j*j&&x/j<=n)p[++top]=x/j;
			}
		}
		sort(p+1,p+top+1);
		for(int j=top;j>=1;j--)
		{
			f[p[j]]+=f[p[j]-1];
			if(f[p[j]]>MOD)f[p[j]]-=MOD;
		}
	}
	for(int i=1;i<=n;i++)
	  ans+=f[i];
	printf("%I64d\n",ans%MOD);
	return 0;
}