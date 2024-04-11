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
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
typedef double ld;
typedef vector<int> vi;
#define fi first
#define se second
#define fe first
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define Edg int M=0,fst[SZ],vb[SZ],nxt[SZ];void ad_de(int a,int b){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;}void adde(int a,int b){ad_de(a,b);ad_de(b,a);}
#define Edgc int M=0,fst[SZ],vb[SZ],nxt[SZ],vc[SZ];void ad_de(int a,int b,int c){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;vc[M]=c;}void adde(int a,int b,int c){ad_de(a,b,c);ad_de(b,a,c);}
#define es(x,e) (int e=fst[x];e;e=nxt[e])
#define esb(x,e,b) (int e=fst[x],b=vb[e];e;e=nxt[e],b=vb[e])
#define VIZ {printf("digraph G{\n"); for(int i=1;i<=n;i++) for es(i,e) printf("%d->%d;\n",i,vb[e]); puts("}");}
#define VIZ2 {printf("graph G{\n"); for(int i=1;i<=n;i++) for es(i,e) if(vb[e]>=i)printf("%d--%d;\n",i,vb[e]); puts("}");}
#define SZ 666666
int T,n,a[SZ],d[SZ],b[SZ];
int ds(int x)
{
	int g=0;
	while(x) ++g,x/=10;
	return g;
}
int bb(int x)
{
	int s=0,g=1;
	while(x)
	{
		if(g) s+=x%10;
		else s-=x%10;
		g^=1; x/=10;
	}
	s=(s%11+11)%11;
	return s;
}
const ll MOD=998244353;
ll fac[SZ],rfac[SZ];
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
int an=0;
int f[2345][2345][11];
void pack1(int r)
{
	++an;
	for(int i=0;i<=an;++i)
		for(int j=0;j<11;++j)
			(f[an][i+1][(j+r)%11]+=f[an-1][i][j])%=MOD,
			(f[an][i][(j+11-r)%11]+=f[an-1][i][j])%=MOD;
}
void pack2(int r)
{
	++an;
	for(int i=0;i<=an;++i)
		for(int j=0;j<11;++j)
			(f[an][i][(j+r)%11]+=f[an-1][i][j]*ll(an-i)%MOD)%=MOD,
			(f[an][i+1][(j+11-r)%11]+=f[an-1][i][j]*ll(i)%MOD)%=MOD;
}
void sol()
{
	scanf("%d",&n);
	an=0;
	for(int i=0;i<=n;++i)
		memset(f[i],0,sizeof f[i]);
	f[0][0][0]=1;
	bool o=0; int c[2]={0,0};
	for(int i=1;i<=n;++i)
	{
		scanf("%d",a+i),d[i]=ds(a[i]),b[i]=bb(a[i]);
		if(d[i]&1) o=1; ++c[d[i]&1];
	}
	if(!o)
	{
		int s=0; 
		for(int i=1;i<=n;++i) s+=b[i];
		s%=11;
		if(s) puts("0");
		else printf("%lld\n",fac[n]);
		return;
	}
	int g=(c[1]+1)/2;
	for(int i=1;i<=n;++i)
		if(d[i]&1) pack1(b[i]);
	for(int i=0;i<=an;++i)
		if(i!=g) memset(f[an][i],0,sizeof f[an][i]);
	for(int i=1;i<=n;++i)
		if(d[i]&1);else pack2(b[i]);
	ll ans=0;
	for(int i=0;i<=an;++i) ans+=f[an][i][0];
	ans%=MOD; ans=ans*fac[g]%MOD*fac[c[1]-g]%MOD;
	ans=(ans%MOD+MOD)%MOD;printf("%d\n",int(ans));
}
int main()
{
	fac[0]=1;
	for(int i=1;i<SZ;++i)
		fac[i]=fac[i-1]*i%MOD;
	rfac[SZ-1]=qp(fac[SZ-1],MOD-2);
	for(int i=SZ-1;i>=1;--i)
		rfac[i-1]=rfac[i]*i%MOD;
	scanf("%d",&T);
	while(T--) sol();
}