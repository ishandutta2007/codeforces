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
int n,x[SZ],y[SZ],r[SZ],fa[SZ]; ll s[SZ];
bool in(int a,int b)
{
	if(r[a]>=r[b]) return 0;
	ll d2=(x[a]-x[b])*ll(x[a]-x[b])
	+(y[a]-y[b])*ll(y[a]-y[b]);
	return d2<=(r[b]-r[a])*ll(r[b]-r[a]);
}
vector<int> ch[SZ];
ll f[SZ][2][2];
void dp(int x)
{
	ll sf[2][2]={0,0,0,0};
	for(int c:ch[x])
	{
		dp(c);
		for(int j=0;j<2;j++)
			for(int k=0;k<2;k++)
				sf[j][k]+=f[c][j][k];
	}
	for(int j=0;j<2;j++)
		for(int k=0;k<2;k++)
			f[x][j][k]=max(f[x][j][k],(k?(-1):1)*s[x]+sf[j][k^1]),
			f[x][j][k]=max(f[x][j][k],(j?(-1):1)*s[x]+sf[j^1][k]);
}
int main()
{
	memset(f,-127/3,sizeof f);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d%d",x+i,y+i,r+i),
		s[i]=(ll)r[i]*r[i];
	for(int i=1;i<=n;i++)
	{
		pii mi(1e9,0);
		for(int j=1;j<=n;j++)
			if(in(i,j)) mi=min(mi,pii(r[j],j));
		fa[i]=mi.se;
		if(fa[i]) ch[fa[i]].pb(i);
	}
	ll ans=0;
	for(int i=1;i<=n;i++)
		if(!fa[i]) dp(i),ans+=f[i][0][0];
	printf("%.10lf\n",ans*ld(acos(-1)));
}