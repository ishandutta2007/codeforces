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
ll phi(ll g)
{
	ll r=g;
	for(ll i=2;i*i<=g;++i) if(g%i==0)
	{
		r=r/i*(i-1); while(g%i==0) g/=i;
	}
	if(g>1) r=r/g*(g-1);
	return r;
}
int m,pp=0,ms[2333];
struct num
{
double v; ll rv; bool e;
}ns[300000],hz[300000];
ll mmp[300000],x[300000];
ll qp(ll a,ll b)
{
	ll x=1;
	while(b)
	{
		if(b&1) x=x*a;
		a=a*a; b>>=1;
	}
	return x;
}
ll qp(ll a,ll b,ll g)
{
	ll x=1; a%=g;
	while(b)
	{
		if(b&1) x=x*a%g;
		a=a*a%g; b>>=1;
	}
	return x;
}
num operator + (num a,num b)
{
	if(a.e) return b;
	if(b.e) return a;
	num nx; nx.v=pow(a.v,b.v); nx.e=0;
	if(nx.v<1e15) nx.rv=qp(a.rv,b.rv);
	else nx.rv=1e15; return nx;
}
int n;
int main()
{
	scanf("%d%d",&n,&m);
	for(int j=m;;j=phi(j))
	{
		ms[++pp]=j;
		if(j==1) break;
	}
	for(int i=1;i<=n;++i)
	{
		int v;
		scanf("%d",&v);
		x[i]=v; num&p=ns[i];
		p.v=p.rv=v; p.e=0;
	}
	int q; scanf("%d",&q);
	while(q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		r=min(r,l+pp+9); mmp[r+1]=1;
		hz[r+1].e=1; hz[r+1].rv=0;
		for(int i=r;i>=l;--i)
		{
			hz[i]=ns[i]+hz[i+1];
			int m=ms[min(i-l+1,pp)],phi=ms[min(i-l+2,pp)];
			if(m==1) mmp[i]=0;
			else
			{
				ll p=mmp[i+1];
				if(hz[i+1].rv>=phi) p+=phi;
				mmp[i]=qp(x[i],p,m);
			}
		}
		ll ans=mmp[l]; ans=(ans%m+m)%m;
		printf("%d\n",int(ans));
	}
}