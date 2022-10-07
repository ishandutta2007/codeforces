#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const ll MOD=998244353,inv2=499122177;
int limit,l,r[400005];
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
ll omega[2][20][1<<19];
void pre()
{
	for(int mid=1,i=0;i<=19;mid<<=1,i++)
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
ll tmp1[400005],tmp2[400005];
void Inv(ll*a,ll*b,int n)
{
	if(n==1)
	{
		b[0]=quick_pow(a[0],MOD-2);
		return;
	}
	Inv(a,b,(n+1)>>1);
	limit=1,l=0;
	while(limit<(n<<1))limit<<=1,l++;
	for(int i=0;i<limit;i++)
	  r[i]=(r[i>>1]>>1)|((i&1)<<(l-1));
	for(int i=0;i<limit;i++)tmp1[i]=i<n?a[i]:0;
	for(int i=(n+1)>>1;i<limit;i++)b[i]=0;
	NTT(tmp1,1);
	NTT(b,1);
	for(int i=0;i<limit;i++)
	  b[i]=b[i]*(2+MOD-tmp1[i]*b[i]%MOD)%MOD;
	NTT(b,-1);
	for(int i=n;i<limit;i++)b[i]=0;
}
void Sqrt(ll*a,ll*b,int n)
{
	if(n==1)
	{
		b[0]=1;
		return;
	}
	Sqrt(a,b,(n+1)>>1);
	Inv(b,tmp2,n);
	limit=1,l=0;
	while(limit<(n<<1))limit<<=1,l++;
	for(int i=0;i<limit;i++)
	  r[i]=(r[i>>1]>>1)|((i&1)<<(l-1));
	for(int i=0;i<limit;i++)
	  tmp1[i]=i<n?a[i]:0;
	NTT(tmp2,1);
	NTT(tmp1,1);
	for(int i=0;i<limit;i++)tmp1[i]=tmp1[i]*tmp2[i]%MOD;
	NTT(tmp1,-1);
	for(int i=0;i<limit;i++)b[i]=(b[i]+tmp1[i])*inv2%MOD;
	for(int i=n;i<limit;i++)b[i]=0;
}
int n,m;
ll a[400005],b[400005];
int main()
{
	pre();
	scanf("%d%d",&m,&n);
	n++;
	for(int i=1;i<=m;i++)
	{
		int x;
		scanf("%d",&x);
		if(x<n)a[x]=MOD-4;
	}
	a[0]++;
	Sqrt(a,b,n);
	b[0]++;
	Inv(b,a,n);
	for(int i=1;i<n;i++)printf("%lld\n",a[i]*2%MOD);
	return 0;
}