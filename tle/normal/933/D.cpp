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
ll m;
#define N 4
const int MOD=1e9+7;
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
ll x[N],y[N],a[N];
void work()
{
	memset(a,0,sizeof a);
	for(int i=0;i<N;++i)
	{
		vector<int> g; g.pb(1); ll s=1;
		for(int j=0;j<N;++j) if(i!=j)
		{
			vector<int> h; h.resize(g.size()+1);
			for(unsigned _=0;_<g.size();++_)
				h[_+1]=(h[_+1]+g[_])%MOD;
			for(unsigned _=0;_<g.size();++_)
				h[_]=(h[_]-g[_]*(ll)x[j])%MOD;
			g=h; s=s*(x[i]-x[j])%MOD;
		}
		s=y[i]*qp(s,MOD-2)%MOD;
		for(unsigned _=0;_<g.size();++_)
			a[_]=(a[_]+g[_]*s)%MOD;
	}
}
ll test(ll x)
{
	ll s=0,g=1; x%=MOD;
	for(int i=0;i<N;++i)
		s=(s+g*a[i])%MOD,g=g*x%MOD;
	return s;
}
ll C[233][233],c[7][7];
ll su[2333333][7];
int main()
{
	cin>>m;
	for(ll t=m-N+1;t<=m;++t)
	{
		x[m-t]=t%MOD;
		for(ll w=t;w<=m;++w)
			for(ll g=t;g<=w;++g)
				y[m-t]=(y[m-t]+g)%MOD;
	}
	work();
	for(int i=0;i<=10;++i)
	{
		C[i][0]=1;
		for(int j=1;j<=i;++j)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
	}
	for(int i=0;i<=3;++i)
		for(int j=0;j<=i;++j)
			(c[j*2][(i-j)*2]+=C[i][j]*a[i])%=MOD;
	for(int i=0;i<=1000000;++i)
	{
		su[i][0]=(i>0)+1;
		for(int j=1;j<=6;++j)
			su[i][j]=su[i][j-1]*i%MOD;
		if(i)
		for(int j=0;j<=6;++j)
			(su[i][j]+=su[i-1][j])%=MOD;
	}
	ll j=0,ans=0;
	for(ll i=1000000;i>=0;--i)
	{
		if(i*i>m) continue;
		while(i*i+(j+1)*(j+1)<=m) ++j;
		ll p=(i>0)+1;
		for(int a=0;a<=6;++a)
		{
			for(int b=0;b<=6;++b)
				if(c[a][b])
					ans+=c[a][b]*p%MOD*su[j][b]%MOD;
			p=p*i%MOD;
		}
	}
	ans=(ans%MOD+MOD)%MOD;
	printf("%d\n",int(ans));
}