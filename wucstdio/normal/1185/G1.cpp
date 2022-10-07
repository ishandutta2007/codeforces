#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const ll MOD=1e9+7;
int n,T,t[25],g[25];
ll f[25][1<<15];
int calc(int s)
{
	int ans=0;
	for(int i=0;i<n;i++)
	  if((1<<i)&s)
	    ans+=t[i];
	return ans;
}
int main()
{
	scanf("%d%d",&n,&T);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&t[i],&g[i]);
		f[i][1<<i]=1;
	}
	for(int i=0;i<(1<<n);i++)
	{
		for(int now=0;now<n;now++)
		{
			if(!f[now][i])continue;
			f[now][i]%=MOD;
			for(int nxt=0;nxt<n;nxt++)
			{
				if((1<<nxt)&i)continue;
				if(g[nxt]==g[now])continue;
				f[nxt][i|(1<<nxt)]+=f[now][i];
			}
		}
	}
	ll ans=0;
	for(int i=0;i<(1<<n);i++)
	{
		if(calc(i)==T)
		{
			for(int j=0;j<n;j++)
			  ans+=f[j][i];
		}
	}
	printf("%I64d\n",ans%MOD);
	return 0;
}