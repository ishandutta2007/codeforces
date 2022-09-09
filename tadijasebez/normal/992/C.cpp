#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
int min(int a, int b){ return a>b?b:a;}
int max(int a, int b){ return a>b?a:b;}
ll min(ll a, ll b){ return a>b?b:a;}
ll max(ll a, ll b){ return a>b?a:b;}
const int mod=1e9+7;
ll pow(ll x, ll k)
{
	ll ret=1;
	for(;k;k>>=1,x=x*x%mod) if(k&1) ret=ret*x%mod;
	return ret;
}
int main()
{
	ll x,k,sol;
	scanf("%lld %lld",&x,&k);
	if(x==0) return printf("0\n"),0;
	x%=mod;
	sol=x*pow(2,k+1)%mod;
	sol++;sol%=mod;
	sol-=pow(2,k);
	if(sol<0) sol+=mod;
	printf("%lld\n",sol);
	return 0;
}