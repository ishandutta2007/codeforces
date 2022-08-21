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
int n,k,a[SZ];
ll f[25][100005];
pair<pii,pii> qs[SZ];
int cnt[SZ]; ll ans=0;
inline void add(int p)
{
	ans+=cnt[a[p]]++;
}
inline void del(int p)
{
	ans-=--cnt[a[p]];
}
void calc(int d)
{
	int h=0,t=0;
	f[d][0]=0;
	qs[t++]=make_pair(pii(1,n),pii(0,n));
	int cl=1,cr=0; ans=0;
	for(int i=1;i<=n;++i) cnt[i]=0;
	while(h!=t)
	{
		pair<pii,pii> g=qs[h++];
		int m=(g.fi.fi+g.fi.se)>>1;
		int R=min(g.se.se,m);
		while(cr<m) add(++cr);
		while(cl>R+1) add(--cl);
		while(cr>m) del(cr--);
		while(cl<R+1) del(cl++);
		int rr=0; ll FF=1e18;
		for(int j=R;j>=g.se.fi;--j)
		{
			ll F=f[d-1][j]+ans;
			if(F<FF) FF=F,rr=j;
			if(j!=g.se.fi) add(--cl);
		}
		f[d][m]=FF;
		if(g.fi.fi<m)
			qs[t++]=make_pair(pii(g.fi.fi,m-1),pii(g.se.fi,rr));
		if(m<g.fi.se)
			qs[t++]=make_pair(pii(m+1,g.fi.se),pii(rr,g.se.se));
	}
}
int main()
{
	memset(f,127/3,sizeof f); f[0][0]=0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i) scanf("%d",a+i);
	for(int i=1;i<=k;++i) calc(i);
	printf("%lld\n",f[k][n]);
}