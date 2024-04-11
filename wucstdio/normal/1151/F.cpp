#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const ll MOD=1e9+7;
int n,num,a[105];
ll k,num1[105],num2[105];
struct Matrix
{
	ll a[105][105];
	Matrix(){memset(a,0,sizeof(a));}
	ll*operator[](int i){return a[i];}
	Matrix operator+(Matrix b)
	{
		Matrix ans;
		for(int i=0;i<=n;i++)
		  for(int j=0;j<=n;j++)
		    ans[i][j]=a[i][j]+b[i][j];
		return ans;
	}
	Matrix operator-(Matrix b)
	{
		Matrix ans;
		for(int i=0;i<=n;i++)
		  for(int j=0;j<=n;j++)
		    ans[i][j]=a[i][j]-b[i][j];
		return ans;
	}
	Matrix operator*(Matrix b)
	{
		Matrix ans;
		for(int k=0;k<=n;k++)
		  for(int i=0;i<=n;i++)
		    for(int j=0;j<=n;j++)
		      ans[i][j]=(ans[i][j]+a[i][k]*b[k][j])%MOD;
		return ans;
	}
}A;
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
Matrix quick_pow(Matrix x,ll a)
{
	Matrix ans;
	for(int i=0;i<=n;i++)ans[i][i]=1;
	while(a)
	{
		if(a&1)ans=ans*x;
		x=x*x;
		a>>=1;
	}
	return ans;
}
int calc()
{
	int ans=0;
	for(int i=1;i<=num;i++)
	  if(a[i]==1)ans++;
	return ans;
}
int main()
{
	scanf("%d%I64d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==0)num++;
	}
	if(num>n-num)
	{
		for(int i=1;i<=n;i++)
		  a[i]^=1;
		for(int i=1;i<=n/2;i++)
		  swap(a[i],a[n-i+1]);
	}
	num=min(num,n-num);
	ll inv=quick_pow(n*(n-1)/2,MOD-2);
	for(int i=0;i<=num;i++)
	{
		num1[i]=i*i;
		num2[i]=(n-num-i)*(num-i);
		if(i)A[i][i-1]=num1[i]*inv%MOD;
		if(i!=num)A[i][i+1]=num2[i]*inv%MOD;
		A[i][i]=(n*(n-1)/2-num1[i]-num2[i])*inv%MOD;
	}
	A=quick_pow(A,k);
	printf("%I64d\n",A[calc()][0]);
	return 0;
}