#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const ll MOD=1e6+3;
ll a[305][305];
ll quick_pow(ll x,ll a)
{
	ll ans=1;
	while(a)
	{
		if(a&1)ans=ans*x%MOD;
		x=x*x%MOD;
		a>>=1;
	}
	return ans;
}
int main()
{
	for(int i=0;i<=10;i++)
	{
		printf("? %d\n",i);
		fflush(stdout);
		int v;
		scanf("%d",&v);
		a[i][0]=1;
		for(int j=1;j<=10;j++)
		  a[i][j]=a[i][j-1]*i%MOD;
		a[i][11]=v;
	}
	for(int i=0;i<=10;i++)
	{
		int now=i;
		for(int j=i;j<=10;j++)
		{
			if(a[j][i])
			{
				now=j;
				break;
			}
		}
		for(int j=i;j<=11;j++)
		  swap(a[now][j],a[i][j]);
		for(int j=i+1;j<=10;j++)
		{
			ll v=quick_pow(a[i][i],MOD-2)*a[j][i]%MOD;
			for(int k=i;k<=11;k++)
			  a[j][k]=(a[j][k]+MOD-a[i][k]*v%MOD)%MOD;
		}
	}
	for(int i=10;i>=0;i--)
	{
		ll v=quick_pow(a[i][i],MOD-2);
		a[i][11]=a[i][11]*v;
		a[i][i]=1;
		for(int j=i-1;j>=0;j--)
		  a[j][11]=(a[j][11]+MOD-a[i][11]*a[j][i]%MOD)%MOD;
	}
	for(int v=0;v<=1000002;v++)
	{
		ll ans=0,pow=1;
		for(int j=0;j<=10;j++)
		{
			ans+=a[j][11]*pow%MOD;
			pow=pow*v%MOD;
		}
		ans%=MOD;
		if(ans==0)
		{
			printf("! %d\n",v);
			return 0;
		}
	}
	printf("! -1\n");
	return 0;
}