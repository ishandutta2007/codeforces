#pragma GCC optimize("-O3","-funroll-all-loops")
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
int k;
#define SZ 233333
ll fac[SZ],rfac[SZ];
const int MOD=998244353;
ll kk[SZ];
struct Tree
{
int n; Edg
void inpe()
{
	for(int i=1,a,b;i<n;++i)
		scanf("%d%d",&a,&b),adde(a,b);
}
ll cd[4005][88],cu[4005][88];
int fa[4005];
void d1(int x,int f=0)
{
	fa[x]=f;
	for esb(x,e,b) if(b!=f) d1(b,x);
	for(int i=0;i<=k;++i) kk[i]=0;
	for esb(x,e,b) if(b!=f)
		for(int i=0;i<=k;++i)
			(kk[i]+=cd[b][i])%=MOD;
	cd[x][0]=1;
	for(int i=0;i<=k;++i)
		for(int j=0;j<=i-2;++j)
			(cd[x][i]+=cd[x][i-j-2]*kk[j])%=MOD;
}
void d2(int x,int f=0)
{
	for(int i=0;i<=k;++i) kk[i]=cu[x][i];
	for esb(x,e,b) if(b!=f)
		for(int i=0;i<=k;++i)
			(kk[i]+=cd[b][i])%=MOD;
	for esb(x,e,b) if(b!=f)
	{
		for(int i=0;i<=k;++i)
			(kk[i]-=cd[b][i])%=MOD;
		cu[b][0]=1;
		for(int i=0;i<=k;++i)
			for(int j=0;j<=i-2;++j)
				(cu[b][i]+=cu[b][i-j-2]*kk[j])%=MOD;
		for(int i=0;i<=k;++i)
			(kk[i]+=cd[b][i])%=MOD;
	}
	for esb(x,e,b) if(b!=f) d2(b,x);
}
ll cyc[4005][88];
void gencyc()
{
	d1(1); d2(1);
	for(int x=1;x<=n;++x)
	{
		for(int i=0;i<=k;++i) kk[i]=cu[x][i];
		for esb(x,e,b) if(b!=fa[x])
			for(int i=0;i<=k;++i)
				(kk[i]+=cd[b][i])%=MOD;
		cyc[x][0]=1;
		for(int i=0;i<=k;++i)
			for(int j=0;j<=i-2;++j)
				(cyc[x][i]+=cyc[x][i-j-2]*kk[j])%=MOD;
	}
}
}T1,T2;
ll qp(ll a,ll b)
{
	ll x=1; a%=MOD;
	while(b)
	{
		if(b&1) x=x*a%MOD;
		a=a*a%MOD; b>>=1;
	}
	return x;
}
ll s1[88],s2[88];
int main()
{
	fac[0]=1;
	for(int i=1;i<SZ;++i) fac[i]=fac[i-1]*i%MOD;
	rfac[SZ-1]=qp(fac[SZ-1],MOD-2);
	for(int i=SZ-1;i;--i) rfac[i-1]=rfac[i]*i%MOD;
	scanf("%d%d%d",&T1.n,&T2.n,&k);
	if(k&1)
	{
		puts("0");
		return 0;
	}
	T1.inpe(); T2.inpe(); T1.gencyc(); T2.gencyc();
	ll ans=0;
	for(int i=1;i<=T1.n;++i)
		for(int t=0;t<=k;++t)
			(s1[t]+=T1.cyc[i][t])%=MOD;
	for(int i=1;i<=T2.n;++i)
		for(int t=0;t<=k;++t)
			(s2[t]+=T2.cyc[i][t])%=MOD;
	for(int t=0;t<=k;++t)
		ans+=s1[t]*s2[k-t]%MOD
		*rfac[t]%MOD*rfac[k-t]%MOD,ans%=MOD; 
	ans=ans*fac[k]%MOD;
	ans=(ans%MOD+MOD)%MOD;
	cout<<ans<<"\n";
}