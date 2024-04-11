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
#define SZ 666666
const int MOD=998244353;
int n,a[2005][2005];
ll T[2005][2005];
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
#define D(x) (T[x][x])
#define F(x) (T[x][0])
struct BS
{
int b[SZ];
void edt(int x,int y)
{
	for(;x<=n;x+=x&-x) b[x]+=y;
}
int qs(int x)
{
	int s=0;
	for(;x>=1;x-=x&-x) s+=b[x];
	return s;
}
void clr()
{
	for(int i=1;i<=n;++i) b[i]=0;
}
}A,B,C;
bool va[SZ],vb[SZ];
int main()
{
	scanf("%d",&n);
	T[0][0]=1;
	for(int i=1;i<=n;++i)
	{
		T[i][0]=T[i-1][0]*i%MOD;
		for(int j=1;j<=i;++j)
			T[i][j]=(T[i][j-1]-T[i-1][j-1])%MOD;
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			scanf("%d",&a[i][j]);
	ll aa=0;
	{
		for(int j=1;j<=n;++j) A.edt(j,1);
		ll ans=0;
		for(int j=1;j<=n;++j)
			//<a[i][j]
			ans+=A.qs(a[1][j]-1)*F(n-j),ans%=MOD,
			A.edt(a[1][j],-1);
		aa+=ans*qp(D(n),n-1);aa%=MOD;
	}
	for(int i=2;i<=n;++i)
	{
		A.clr(); B.clr();
		//A: BA
		//B: BA 
		//a1bb
		//a0bb
		for(int j=1;j<=n;++j)
			B.edt(j,1),va[j]=vb[j]=0;
		int a1=0,a0=0; ll ans=0;
		for(int j=1;j<=n;++j)
		{
			#define eda(x,y) \
			if(va[x]) {if(vb[x]) a1+=y; else a0+=y;}
			#define edb(x,y) \
			if(!vb[x]) {if(va[x]) A.edt(x,y); else B.edt(x,y);}
			edb(a[i-1][j],-1);
			eda(a[i-1][j],-1);
			va[a[i-1][j]]=1;
			eda(a[i-1][j],1);
			{
			int x1=a1+1,x0=a0-1;
			ll f=A.qs(a[i][j]-1);
			if(f)
			ans+=T[n-x0-x1][n-x0-x1-x0]*f; ans%=MOD;
			}
			{
			int x1=a1,x0=a0;
			ll f=B.qs(a[i][j]-1);
			if(f)
			ans+=T[n-x0-x1][n-x0-x1-x0]*f; ans%=MOD;
			}
			edb(a[i-1][j],1);
			#define ed(x,y) \
			if(va[x]) {if(vb[x]) a1+=y; else a0+=y;}\
			if(!vb[x]) {if(va[x]) A.edt(x,y); else B.edt(x,y);}
			ed(a[i][j],-1);
			vb[a[i][j]]=1;
			ed(a[i][j],1);
		}
		aa+=ans*qp(D(n),n-i);aa%=MOD;
	}
	aa=(aa%MOD+MOD)%MOD;
	cout<<aa<<"\n";
}