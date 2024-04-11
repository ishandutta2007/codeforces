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
typedef pair<int,int> pii;
typedef double ld;
typedef vector<int> vi;
#define fi first
#define se second
#define fe first
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define Edg int M=0,fst[SZ],vb[SZ],nxt[SZ];void ad_de(int a,int b){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;}void adde(int a,int b){ad_de(a,b);ad_de(b,a);}
#define Edgc int M=0,fst[SZ],vb[SZ],nxt[SZ],vc[SZ];void ad_de(int a,int b,int c){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;vc[M]=c;}void adde(int a,int b,int c){ad_de(a,b,c);ad_de(b,a,c);}
#define es(x,e) (int e=fst[x];e;e=nxt[e])
#define VIZ {printf("digraph G{\n"); for(int i=1;i<=n;i++) for es(i,e) printf("%d->%d;\n",i,vb[e]); puts("}");}
#ifdef LOCAL
#define TIMER cerr<<clock()<<"ms\n"
#else
#define TIMER
#endif
#define SZ 666666
int n,a[SZ],b[SZ],c[SZ];
pii ans=pii(-2333,0);
map<pii,pii> ms;
pii cf(pii a,int b,int c)
{
	return pii(min(a.fi+c,b),a.se);
}
void gm(pii& a,pii b)
{
	if(a<b) a=b;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	scanf("%d%d%d",a+i,b+i,c+i),
	ans=max(ans,pii(min(min(a[i],b[i]),c[i]),i));
	int c1=ans.se,c2=0;
	for(int i=1;i<=n;i++)
	{
		pii mx=cf(ms[pii(a[i],b[i])],min(a[i],b[i]),c[i]);
		mx=max(mx,cf(ms[pii(c[i],b[i])],min(c[i],b[i]),a[i]));
		mx=max(mx,cf(ms[pii(c[i],a[i])],min(a[i],c[i]),b[i]));
		//cout<<i<<":"<<mx.fi<<","<<mx.se<<"\n";
		//cout<<i<<":"<<mx.fi<<","<<mx.se<<"\n";
		if(mx>ans) ans=mx, c1=mx.se, c2=i;
		gm(ms[pii(a[i],b[i])],pii(c[i],i));
		gm(ms[pii(b[i],a[i])],pii(c[i],i));
		gm(ms[pii(a[i],c[i])],pii(b[i],i));
		gm(ms[pii(c[i],a[i])],pii(b[i],i));
		gm(ms[pii(b[i],c[i])],pii(a[i],i));
		gm(ms[pii(c[i],b[i])],pii(a[i],i));
	}
	if(!c2) printf("1\n%d\n",c1);
	else printf("2\n%d %d\n",c1,c2);
}