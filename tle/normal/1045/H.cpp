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
ll fac[SZ],rfac[SZ];
const int MOD=1e9+7;
int C(int a,int b)
{
	if(b>a) return 0;
	return fac[a]*rfac[a-b]%MOD*rfac[b]%MOD;
}
ll cr(int a,int b)
{
	if(!a)
	{
		if(!b) return 1;
		return 0;
	}
	return C(b+a-1,a-1);
}
int gans(int b,int l,int c00,int c11,int c01,int c10)
{
	if(c00<0||c11<0||c01<0||c10<0
	||l!=c00+c11+c01+c10) return 0;
	if(b) swap(c00,c11),swap(c01,c10);
	//0000011110000111
	int u=c01+c10+1,c0=(u+1)/2,c1=u/2;
	if((u-1)/2!=c10||u/2!=c01) return 0;
	//x1+x2+...+x[c0]=c00
	return cr(c0,c00)*cr(c1,c11)%MOD;
}
int c[2][2];
ll calc(int*a,int n)
{
	int z[2][2];
	for(int i=0;i<2;++i)
		for(int j=0;j<2;++j) z[i][j]=c[i][j];
	while(!a[n]) --n;
	ll ans=0;
	for(int i=1;i<n;++i)
		ans+=gans(1,i-1,z[0][0],
		z[1][1],z[0][1],z[1][0]);
	static int p[SZ]; int q=0;
	for(int i=n;i>=1;--i)
	{
		if(a[i]&&i!=n)
		{
			p[++q]=0;
			--z[p[q-1]][p[q]];
			ans+=gans(0,i-1,z[0][0],
			z[1][1],z[0][1],z[1][0]);
			++z[p[q-1]][p[q]];
			--q;
		}
		p[++q]=a[i];
		if(q>1) --z[p[q-1]][p[q]];
	}
	return ans%MOD;
}
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
char sa[SZ],sb[SZ];
int as[SZ],an=0,bs[SZ],bn=0;
int main()
{
	fac[0]=1;
	for(int i=1;i<SZ;++i) fac[i]=fac[i-1]*i%MOD;
	rfac[SZ-1]=qp(fac[SZ-1],MOD-2);
	for(int i=SZ-1;i;--i) rfac[i-1]=rfac[i]*i%MOD;
	scanf("%s%s%d%d%d%d",sb,sa,
	&c[0][0],&c[0][1],&c[1][0],&c[1][1]);
	for(int i=0;sa[i];++i) as[++an]=sa[i]-'0';
	for(int i=0;sb[i];++i) bs[++bn]=sb[i]-'0';
	reverse(as+1,as+1+an);
	reverse(bs+1,bs+1+bn);
	++an; ++as[1];
	for(int i=1;i<=an;++i)
		as[i+1]+=as[i]/2,
		as[i]%=2;
	ll ans=calc(as,an)-calc(bs,bn);
	ans=(ans%MOD+MOD)%MOD;
	cout<<ans<<"\n";
}