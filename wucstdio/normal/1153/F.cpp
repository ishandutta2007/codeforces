#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const ll MOD=998244353;
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
ll f[5005],pow1[2005][5005],pow2[2005][5005],c[2005][2005];
int n,k,l;
int limit,L,r[10005];
ll omega[2][15][1<<14];
void pre()
{
	for(int mid=1,i=0;i<=14;mid<<=1,i++)
	{
		ll w1=quick_pow(3,(MOD-1)/(mid<<1));
		ll w2=quick_pow(3,MOD-1-(MOD-1)/(mid<<1));
		omega[0][i][0]=omega[1][i][0]=1;
		for(int k=1;k<mid;k++)
		{
			omega[1][i][k]=omega[1][i][k-1]*w1%MOD;
			omega[0][i][k]=omega[0][i][k-1]*w2%MOD;
		}
	}
}
void NTT(ll*A,int type) 
{
	for(int i=0;i<limit;i++)
	  if(i<r[i])swap(A[i],A[r[i]]);
	if(type==-1)type=0;
	for(int mid=1,i=0;mid<limit;mid<<=1,i++)
	{
		for(int R=mid<<1,j=0;j<limit;j+=R)
		{
			for(int k=0;k<mid;k++)
			{
				ll x=A[j+k]%MOD,y=omega[type][i][k]*A[j+mid+k]%MOD;
				A[j+k]=x+y;
				A[j+mid+k]=x-y;
			}
		}
	}
	for(int i=0;i<limit;i++)
	{
		A[i]%=MOD;
		if(A[i]<0)A[i]+=MOD;
	}
	if(type==0)
	{
		ll inv=quick_pow(limit,MOD-2);
		for(int i=0;i<limit;i++)A[i]=A[i]*inv%MOD;
	}
}
ll tmp1[10005],tmp2[10005];
int main()
{
	pre();
	scanf("%d%d%d",&n,&k,&l);
	limit=1,L=0;
	while(limit<=(2*n))limit<<=1,L++;
	for(int i=0;i<limit;i++)
	  r[i]=(r[i>>1]>>1)|((i&1)<<(L-1));
	c[0][0]=1;
	for(int i=0;i<=n;i++)
	for(int j=0;j<=n;j++)
	{
		if(c[i][j]>=MOD)c[i][j]-=MOD;
		c[i+1][j+1]+=c[i][j];
		c[i+1][j]+=c[i][j];
	}
	pow1[0][0]=1;
	pow1[1][1]=2,pow1[1][2]=-2;
	NTT(pow1[0],1);
	NTT(pow1[1],1);
	for(int i=2;i<=n;i++)
	  for(int x=0;x<limit;x++)
		pow1[i][x]=pow1[i-1][x]*pow1[1][x]%MOD;
	pow2[0][0]=1;
	pow2[1][0]=1,pow2[1][1]=-2,pow2[1][2]=2;
	NTT(pow2[0],1);
	NTT(pow2[1],1);
	for(int i=2;i<=n;i++)
	  for(int x=0;x<limit;x++)
		pow2[i][x]=pow2[i-1][x]*pow2[1][x]%MOD;
	for(int i=k;i<=n;i++)
	{
		for(int j=0;j<limit;j++)
		{
			tmp1[j]=pow1[i][j];
			tmp2[j]=pow2[n-i][j];
		}
		for(int j=0;j<limit;j++)
		  tmp1[j]=tmp1[j]*tmp2[j]%MOD;
		for(int j=0;j<limit;j++)
		  f[j]=(f[j]+tmp1[j]*c[n][i])%MOD;
	}
	NTT(f,-1);
	ll ans=0;
	for(int i=0;i<=2*n;i++)
	  ans+=quick_pow(i+1,MOD-2)*f[i]%MOD;
	ans%=MOD;
	if(ans<0)ans+=MOD;
	printf("%I64d\n",ans*l%MOD);
	return 0;
}