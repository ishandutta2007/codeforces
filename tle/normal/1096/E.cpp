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
int p,r,s;
const int MOD=998244353;
ll fac[SZ],rfac[SZ];
ll qp(ll a,ll b)
{
	ll x=1; a%=MOD;
	while(b)
	{
		if(b&1) x=x*a%MOD;
		a=a*a%MOD;b>>=1;
	}
	return x;
}
ll C(int a,int b)
{
	if(b>a||b<0) return 0;
	return fac[a]*rfac[a-b]%MOD*rfac[b]%MOD;
}
ll calc(int a,int b)
{
	if(b==0)
	{
		if(a>0) return 0;
		return 1;
	}
	return C(a+b-1,b-1);
}
int main()
{
	fac[0]=1;
	for(int i=1;i<SZ;++i)
		fac[i]=fac[i-1]*i%MOD;
	rfac[SZ-1]=qp(fac[SZ-1],MOD-2);
	for(int i=SZ-1;i;--i)
		rfac[i-1]=rfac[i]*i%MOD;
	cin>>p>>s>>r;
	ll tot=calc(s-r,p),aa=0;
	for(int g=r;g<=s;++g) //hasan
	for(int u=0;u<p&&g*(u+1)<=s;++u) //same scorer
	{
		ll cm=C(p-1,u),pw=0;
		//others <=g-1
		int tt=s-g*(u+1),uu=p-u-1;
		for(int x=0;x*g<=tt&&x<=uu;++x)
		{
			ll cur=C(uu,x)*calc(tt-x*g,uu);
			if(x&1) (pw-=cur)%=MOD;
			else (pw+=cur)%=MOD;
		}
		aa+=pw*cm%MOD*qp(u+1,MOD-2);
		aa%=MOD;
	}
	aa=aa*qp(tot,MOD-2)%MOD;
	aa=(aa%MOD+MOD)%MOD;
	cout<<aa<<"\n";
}