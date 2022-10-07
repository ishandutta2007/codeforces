#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const ll MOD=998244353;
struct Data
{
	int v;
	bool lorr;
	int pos;
}a[105];
int n,v[105],l[105],r[105];
ll f[105][105][105],tmp[105],S[105][105],inv[105],inv2[105];
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
void ask(int k)
{
//	printf("ask(%d):\n",k);
	ll v[55];
	v[0]=0;
	for(int i=1;i<=k+1;i++)v[i]=(v[i-1]+quick_pow(i,k))%MOD;
	for(int i=0;i<=k+1;i++)
	{
//		printf("i=%d:",i);
		for(int j=0;j<=k+1;j++)tmp[j]=0;
		tmp[0]=1;
		int m=0;
		for(int j=0;j<=k+1;j++)
		{
			if(i==j)continue;
			for(int x=m;x>=0;x--)
			{
				tmp[x+1]=(tmp[x+1]+tmp[x]*(j<i?inv[i-j]:inv2[j-i]))%MOD;
				tmp[x]=tmp[x]*(j<i?inv[i-j]:inv2[j-i])%MOD*(MOD-j)%MOD;
			}
			m++;
		}
//		for(int j=0;j<=k+1;j++)printf("%lld ",tmp[j]);
//		printf("\n");
		for(int j=0;j<=k+1;j++)S[k][j]=(S[k][j]+tmp[j]*v[i])%MOD;
	}
}
void Add(ll*A,ll*B)
{
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=i+1;j++)
		  B[j]=(B[j]+A[i]*S[i][j])%MOD;
	}
}
ll calc(ll*A,ll x)
{
//	printf("calc (%lld) ",x);
//	for(int i=0;i<=n;i++)printf("%lld ",A[i]);
//	printf("\n");
	for(int i=0;i<=n;i++)tmp[i]=0;
	Add(A,tmp);
//	for(int i=0;i<=n;i++)printf("%lld ",tmp[i]*6%MOD);
//	printf("\n");
	ll ans=0;
	for(int i=n;i>=0;i--)ans=(ans*x+tmp[i])%MOD;
//	printf("%lld\n",ans);
	return ans;
}
bool cmp(Data a,Data b)
{
	return a.v<b.v;
}
int main()
{
	for(int i=0;i<55;i++)inv[i]=quick_pow(i,MOD-2);
	for(int i=0;i<55;i++)inv2[i]=quick_pow(MOD-i,MOD-2);
	for(int i=0;i<=50;i++)ask(i);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&l[n-i+1],&r[n-i+1]);
		a[2*i-1].v=l[n-i+1];
		a[2*i-1].lorr=0;
		a[2*i-1].pos=n-i+1;
		a[2*i].v=r[n-i+1]+1;
		a[2*i].lorr=1;
		a[2*i].pos=n-i+1;
	}
	sort(a+1,a+2*n+1,cmp);
	int now=0;
	v[0]=-1;
	for(int i=1;i<=2*n;i++)
	{
		if(a[i].v!=v[now])now++;
		v[now]=a[i].v;
		if(a[i].lorr)r[a[i].pos]=now-1;
		else l[a[i].pos]=now;
	}
	for(int i=l[1];i<=r[1];i++)f[1][i][0]=1;
	for(int i=2;i<=n;i++)
	{
		ll sum=0;
		for(int j=1;j<l[i];j++)sum+=calc(f[i-1][j],v[j+1]-v[j]);
		for(int j=l[i];j<=r[i];j++)
		{
			f[i][j][0]=sum;
			Add(f[i-1][j],f[i][j]);
			sum+=calc(f[i-1][j],v[j+1]-v[j]);
		}
	}
	ll ans=0;
	for(int i=l[n];i<=r[n];i++)ans=(ans+calc(f[n][i],v[i+1]-v[i]))%MOD;
	for(int i=1;i<=n;i++)
	{
		ans=ans*quick_pow(v[r[i]+1]-v[l[i]],MOD-2)%MOD;
	}
	printf("%lld\n",ans);
	return 0;
}