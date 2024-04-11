#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const ll MOD=998244353;
int n,k,a[1005];
ll f[1005][1005],res[100005],ans,s[1005][1005];
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	a[0]=-1000000000;
	for(int v=1;v*(k-1)<=a[n];v++)
	{
		f[0][0]=1;
		int now=0;
		s[0][0]=1;
		for(int i=1;i<=n;i++)
		{
			while(a[now]<=a[i]-v)now++;
			for(int j=0;j<=k;j++)
			{
				if(j)f[i][j]=s[now-1][j-1];
				s[i][j]=(s[i-1][j]+f[i][j])%MOD;
			}
			res[v]+=f[i][k];
		}
		ans+=res[v]%MOD;
	}
	printf("%I64d\n",ans%MOD);
	return 0;
}