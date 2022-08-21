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
int n,c[SZ],d[SZ];
pii divs[2];
pii unn(pii a,pii b)
{
	return pii(max(a.fi,b.fi),min(a.se,b.se));
}
int main()
{
	divs[2]=pii(-1e9,1899);
	divs[1]=pii(1900,1e9);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",c+i,d+i);
	int inf=1e9/2;
	pii qwq=pii(-1e9,1e9);
	int tot=0;
	for(int i=n;i>=1;i--)
	{
		tot+=c[i];
		//0+tot<=rs<=div+tot
		pii cur=divs[d[i]];
		cur.fi+=tot; cur.se+=tot;
		qwq=unn(qwq,cur);
	}
	if(qwq.fi>qwq.se) puts("Impossible");
	else if(qwq.se>inf) puts("Infinity");
	else printf("%d\n",qwq.se);
}