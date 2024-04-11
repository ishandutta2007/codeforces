#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const ll MOD=1e9+6;
struct Matrix
{
	ll a[5][5];
	Matrix(){memset(a,0,sizeof(a));}
	ll*operator[](int i){return a[i];}
	Matrix operator*(Matrix b)
	{
		Matrix ans;
		for(int k=0;k<5;k++)
		  for(int i=0;i<5;i++)
		    for(int j=0;j<5;j++)
		      ans[i][j]=(ans[i][j]+a[i][k]*b[k][j])%MOD;
		return ans;
	}
}A;
Matrix quick_pow(Matrix x,ll a)
{
	Matrix ans;
	for(int i=0;i<5;i++)ans[i][i]=1;
	while(a)
	{
		if(a&1)ans=ans*x;
		x=x*x;
		a>>=1;
	}
	return ans;
}
ll quick_pow(ll x,ll a)
{
	ll ans=1;
	while(a)
	{
		if(a&1)ans=ans*x%(MOD+1);
		x=x*x%(MOD+1);
		a>>=1;
	}
	return ans;
}
ll n,c,f1,f2,f3,ans;
int main()
{
	scanf("%I64d%I64d%I64d%I64d%I64d",&n,&f1,&f2,&f3,&c);
	A[0][0]=A[0][1]=A[0][2]=A[0][3]=A[1][0]=A[2][1]=A[3][3]=A[4][4]=1;
	A[3][4]=2;
	A=quick_pow(A,n-3);
	ans=quick_pow(c,2*A[0][3]+A[0][4])*quick_pow(f3,A[0][0])%(MOD+1)*quick_pow(f2,A[0][1])%(MOD+1)*quick_pow(f1,A[0][2])%(MOD+1);
	printf("%I64d\n",ans);
	return 0;
}