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
int n,d,b,a[SZ],p;
pair<pii,int> qj[SZ];
int du(int x,int y) {return (x+y-1)/y;}
int ne[SZ];
bool ok(int x)
{
	int L=x+1,R=n-x;
	if(L>R) return 1;
	for(int i=1;i<=n;++i) ne[i]=0;
	for(int i=L;i<=R;++i) ne[i]=b;
	int g=1;
	for(int i=1;i<=n;++i)
	{
		while(g<qj[i].fi.fi) ++g;
		int w=qj[i].se;
		while(w)
		{
			while(!ne[g]&&g<=qj[i].fi.se) ++g;
			if(g>qj[i].fi.se) break;
			int u=min(ne[g],w);
			ne[g]-=u; w-=u;
		}
	}
	for(int i=L;i<=R;++i)
		if(ne[i]) return 0;
	return 1;
}
int main()
{
	scanf("%d%d%d",&n,&d,&b); p=(n+1)/2;
	for(int i=1;i<=n;++i) scanf("%d",a+i);
	for(int i=1;i<=n;++i)
	{
		int l=1,r=i;
		while(l<r)
		{
			int m=(l+r)>>1,ne=du(abs(i-m),d);
			if(ne<=min(m,n+1-m)) r=m; else l=m+1;
		}
		qj[i].fi.fi=l;
		l=i; r=n;
		while(l<r)
		{
			int m=(l+r+1)>>1,ne=du(abs(i-m),d);
			if(ne<=min(m,n+1-m)) l=m; else r=m-1;
		}
		qj[i].fi.se=l;
		qj[i].se=a[i];
	}
	sort(qj+1,qj+1+n);
	int l=0,r=p;
	while(l<r)
	{
		int w=(l+r)>>1;
		if(ok(w)) r=w; else l=w+1;
	}
	printf("%d\n",l);
}