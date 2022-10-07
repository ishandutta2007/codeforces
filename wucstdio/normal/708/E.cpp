#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const ll MOD=1e9+7;
int n,m,k;
ll p,pw1[100005],pw2[100005],fact[100005],inv[100005];
ll s1[1505][1505],s2[1505][1505],A[1505][1505],B[1505][1505],S[1505];
ll sp[1505],spa[1505][1505],spb[1505][1505];
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
ll C(int n,int m)
{
	if(m>n)return 0;
	return fact[n]*inv[m]%MOD*inv[n-m]%MOD;
}
int main()
{
	scanf("%d%d",&n,&m);
	ll a,b;
	scanf("%lld%lld",&a,&b);
	p=a*quick_pow(b,MOD-2)%MOD;
	scanf("%d",&k);
	fact[0]=1;
	for(int i=1;i<=k;i++)fact[i]=fact[i-1]*i%MOD;
	inv[k]=quick_pow(fact[k],MOD-2);
	for(int i=k;i>=1;i--)inv[i-1]=inv[i]*i%MOD;
	pw1[0]=1;
	for(int i=1;i<=k;i++)pw1[i]=pw1[i-1]*p%MOD;
	pw2[0]=1;
	for(int i=1;i<=k;i++)pw2[i]=pw2[i-1]*(1-p+MOD)%MOD;
	sp[0]=pw2[k];
	for(int i=1;i<=m;i++)
	{
		if(i<=k)sp[i]=(sp[i-1]+C(k,i)*pw1[i]%MOD*pw2[k-i])%MOD;
		else sp[i]=sp[i-1];
	}
	s1[0][0]=s2[0][0]=1;
	A[0][0]=B[0][0]=1;
	S[0]=1;
	if(m<=k)
	{
		spa[0][m]=C(k,m)*pw1[m]%MOD*pw2[k-m]%MOD;
		spb[0][m]=C(k,m)*pw1[m]%MOD*pw2[k-m]%MOD;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=min(m-1,k);j++)
		{
			s1[i][j]=C(k,j)*pw1[j]%MOD*pw2[k-j]%MOD*((S[i-1]-B[i-1][m-j]+MOD)*sp[m-j-1]%MOD-spa[i-1][m-j-1]+MOD)%MOD;
			s2[i][j]=C(k,j)*pw1[j]%MOD*pw2[k-j]%MOD*((S[i-1]-A[i-1][m-j]+MOD)*sp[m-j-1]%MOD-spb[i-1][m-j-1]+MOD)%MOD;
		}
		A[i][m]=s1[i][m];
		for(int j=m-1;j>=0;j--)A[i][j]=(A[i][j+1]+s1[i][j])%MOD;
		B[i][m]=s2[i][m];
		for(int j=m-1;j>=0;j--)B[i][j]=(B[i][j+1]+s2[i][j])%MOD;
		S[i]=A[i][0];
		spa[i][0]=A[i][m]*pw2[k]%MOD;
		spb[i][0]=B[i][m]*pw2[k]%MOD;
		for(int j=1;j<=m;j++)
		{
			if(j<=k)
			{
				spa[i][j]=(spa[i][j-1]+A[i][m-j]*C(k,j)%MOD*pw1[j]%MOD*pw2[k-j])%MOD;
				spb[i][j]=(spb[i][j-1]+B[i][m-j]*C(k,j)%MOD*pw1[j]%MOD*pw2[k-j])%MOD;
			}
			else
			{
				spa[i][j]=spa[i][j-1];
				spb[i][j]=spb[i][j-1];
			}
		}
	}
	printf("%lld\n",S[n]);
	return 0;
}