#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <stack>
#include <iomanip>
using namespace std;
const int MOD=1e9+7;
#define pb push_back
typedef long long ll;
ll qp(ll a,ll b)
{
	ll x=1;
	while(b)
	{
		if(b&1) x=x*a%MOD;
		a=a*a%MOD; b>>=1;
	}
	return x;
}
//O(n^2) 
namespace Newton
{
ll y[23333],g[23333]; int N;
//y[i]=f(i) (1...n)
//y
void work()
{
	ll ii=1;
	for(int i=1;i<=N;++i) y[i]=(y[i]%MOD+MOD)%MOD;
	for(int i=1;i<=N;++i)
	{ 
		g[i]=y[1]*ii%MOD;
		ii=ii*qp(i,MOD-2)%MOD;
		for(int j=1;j<=N-i;++j)
		{
			y[j]=y[j+1]-y[j];
			if(y[j]<0) y[j]+=MOD;
		}
		y[N-i+1]=0;
	}
}
ll calc(int x)
{
	ll w=1,a=0;
	for(int i=1;i<=N;++i)
		a=(a+w*g[i])%MOD,w=w*(x-i)%MOD;
	return a;
}
}
int n,k,C[2][233333];
ll mmp[23333];
int main()
{
	cin>>n>>k;
	int g=k+5;
	for(int i=0;i<=g;++i) mmp[i]=qp(i,k);
	for(int i=0;i<=g;++i)
	{
		C[i&1][0]=1;
		for(int j=1;j<=i;++j)
			C[i&1][j]=(C[!(i&1)][j-1]+C[!(i&1)][j])%MOD;
		ll pp=0;
		for(int j=0;j<=i;++j)
			pp+=C[i&1][j]*mmp[j]%MOD;
		pp%=MOD;
		int c=k-i;
		if(c<0) c+=MOD-1;
		pp=pp*qp(2,c)%MOD;
		Newton::y[++Newton::N]=pp;
	}
	Newton::work();
	ll ans=Newton::calc(n+1);
	int c=(n-k)%(MOD-1); if(c<0) c+=MOD-1;
	ans*=qp(2,c); ans=(ans%MOD+MOD)%MOD;
	printf("%d\n",int(ans));
}