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
#include <unordered_map> //C++11
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
#define xn xxn
#define yn yyn
const int MOD=1e9+7;
int n,k,x[233],y[233],v[233],ans=0,
xs[233],ys[233],xn=0,yn=0,r1[233333],r2[233333];
ll fac[233333];
vector<pii> ss[2333];
ll hz[2333];
unordered_map<ll,ll> f[66][66];
int main()
{
	cin>>n>>k; fac[0]=1;
	srand(n^(k+2333333)^19260817);
	for(int i=1;i<=n;++i)
		r1[i]=r2[i]=i,fac[i]=fac[i-1]*i%MOD;
	random_shuffle(r1+1,r1+1+n);
	random_shuffle(r2+1,r2+1+n);
	for(int i=0;i<k;++i)
	{
		cin>>x[i]>>y[i]>>v[i],--v[i];
		x[i]=r1[x[i]]; y[i]=r2[y[i]]; // 
		xs[++xn]=x[i]; ys[++yn]=y[i];
	}
	sort(xs+1,xs+1+xn); xn=unique(xs+1,xs+1+xn)-xs-1;
	sort(ys+1,ys+1+yn); yn=unique(ys+1,ys+1+yn)-ys-1;
	for(int i=0;i<k;++i)
	{
		x[i]=lower_bound(xs+1,xs+1+xn,x[i])-xs;
		y[i]=lower_bound(ys+1,ys+1+yn,y[i])-ys;
		ss[x[i]].pb(pii(y[i],v[i]));
	}
	for(int i=xn;i>=1;--i)
	{
		hz[i]=hz[i+1];
		for(auto g:ss[i])
			hz[i]|=1LL<<g.fi;
	}
	f[0][0][0]=1;
	for(int i=1;i<=xn;++i)
		for(int j=0;j<i;++j)
		{
			auto&c=f[i][j],&a=f[i][j+1];
			for(auto p:f[i-1][j])
			{
				(c[p.fi&hz[i+1]]+=p.se)%=MOD;
				for(auto g:ss[i])
					if(p.fi&(1LL<<g.fi));
					else (a[(p.fi|(1LL<<g.fi))&hz[i+1]]+=p.se*g.se)%=MOD;
			}
			f[i-1][j].clear();
		}
	ll ans=0;
	for(int j=0;j<=xn&&j<=n;++j)
		for(auto p:f[xn][j])
			ans+=p.se*fac[n-j],ans%=MOD;
	ans=(ans%MOD+MOD)%MOD;
	printf("%d\n",int(ans));
}