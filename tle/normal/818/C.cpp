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
#define x1 x1_
#define x2 x2_
#define y1 y1_
#define y2 y2_
int d,n,m,x1[SZ],x2[SZ],y1[SZ],y2[SZ];
int sx1[SZ],sx2[SZ],sy1[SZ],sy2[SZ];
int main()
{
	scanf("%d%d%d",&d,&n,&m);
	for(int i=1;i<=d;i++)
	{
		scanf("%d%d%d%d",x1+i,y1+i,x2+i,y2+i);
		if(x1[i]>x2[i]) swap(x1[i],x2[i]);
		if(y1[i]>y2[i]) swap(y1[i],y2[i]);
		sx1[i]=x1[i],sx2[i]=x2[i],sy1[i]=y1[i],sy2[i]=y2[i];
	}
	int cl,cr,ct,cb;
	scanf("%d%d%d%d",&cl,&cr,&ct,&cb);
	#define sor(x) sort(x+1,x+1+d)
	#define geq(x,y) (x+1+d-lower_bound(x+1,x+1+d,y))
	#define leq(x,y) (upper_bound(x+1,x+1+d,y)-x-1)
	sor(sx1);sor(sx2);sor(sy1);sor(sy2); int ans=0;
	for(int i=1;i<=d;i++)
	{
		int l=leq(sx1,x2[i]-1)-(x1[i]<x2[i])
		,r=geq(sx2,x1[i]+1)-(x2[i]>x1[i]);
		int t=leq(sy1,y2[i]-1)-(y1[i]<y2[i]),
		b=geq(sy2,y1[i]+1)-(y2[i]>y1[i]);
		if(l==cl&&r==cr&&t==ct&&b==cb)
		{
			printf("%d\n",i);
			return 0;
		}
	}
	puts("-1");
}