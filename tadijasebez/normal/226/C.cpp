#include <stdio.h>
#include <vector>
using namespace std;
#define ll long long
#define pb push_back
int mod;
struct Matrix
{
	int a[2][2];
	Matrix(){ a[0][0]=a[0][1]=a[1][0]=a[1][1]=0;}
	void fib(){ a[0][0]=a[0][1]=a[1][0]=1;a[1][1]=0;}
	void id(){ a[0][0]=a[1][1]=1;a[1][0]=0;a[0][1]=0;}
	Matrix operator * (Matrix b) const
	{
		Matrix c;
		for(int i=0;i<2;i++) for(int j=0;j<2;j++) for(int k=0;k<2;k++) c.a[i][j]+=(ll)a[i][k]*b.a[k][j]%mod,c.a[i][j]%=mod;
		return c;
	}
};
Matrix pow(Matrix x, ll k)
{
	Matrix ret;ret.id();
	for(;k;k>>=1,x=x*x) if(k&1) ret=ret*x;
	return ret;
}
ll ans;
ll max(ll a, ll b){ return a>b?a:b;}
vector<ll> x;
int main()
{
	ll l,r,k,i;
	scanf("%i %lld %lld %lld",&mod,&l,&r,&k);
	for(i=1;i*i<=r;i++) x.pb(i),x.pb(r/i);
	for(i=1;i*i<=l;i++) x.pb(l%i==0?l/i:l/(i-1));
	for(i=0;i<x.size();i++)
	{
		ll L=l/x[i]+(l%x[i]!=0);
		ll R=r/x[i];
		if(R-L+1>=k) ans=max(ans,x[i]);
	}
	Matrix sol;sol.fib();
	sol=pow(sol,ans);
	printf("%i\n",sol.a[1][0]);
	return 0;
}