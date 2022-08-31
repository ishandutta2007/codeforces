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
typedef long double ld;
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
int n; pii p[SZ];
pair<ld,int> g[SZ];
const ld pi=acosl(-1);
ld pp(ld x)
{
	if(x<=0)x+=pi;
	return x;
}
pii operator - (pii a,pii b)
{return pii(a.fi-b.fi,a.se-b.se);}
ld ang(pii t)
{return pp(atan2l(t.se,t.fi));}
const ld eps=2e-10;
ll C2(ll x) {return x*(x-1)/2;}
int t[SZ];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d%d",&p[i].fi,&p[i].se);
	unsigned long long ans=0;
	for(int i=1;i<=n;++i)
	{
		int gn=0;
		for(int j=1;j<=n;++j) if(j!=i)
			g[++gn]=mp(ang(p[j]-p[i]),j);
		sort(g+1,g+1+gn);
		int c[2]={0,0};
		for(int j=1;j<=n;++j) if(j!=i)
		{
			if(p[j].se<p[i].se||(p[j].se==p[i].se&&p[j].fi>p[i].fi))
				++c[t[j]=0];
			else ++c[t[j]=1];
		}
		for(int j=1;j<=gn;++j)
		{
			int u=g[j].se;
			--c[t[u]];
			ans+=C2(c[0])*C2(c[1]);
			++c[t[u]^=1];
		}
	}
	cout<<ans/2<<"\n";
}