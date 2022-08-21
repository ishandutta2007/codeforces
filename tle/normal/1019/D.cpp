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
int n; pii s[SZ];
pair<ld,pii> ps[9999999];
pii operator - (pii a,pii b)
{return pii(a.fi-b.fi,a.se-b.se);}
ld ang(pii t)
{
	if(t.fi==0)
		return (t.se>0)?1e18:(-1e18);
	return t.se/(ld)t.fi;
}
inline ll operator * (pii a,pii b)
{return a.fi*(ll)b.se-a.se*(ll)b.fi;}
int id[SZ],a[SZ],pn; ll S;
inline ll area(int x,int y,int z)
{
	ll v=(s[x]-s[y])*(s[z]-s[y]);
	if(v<0) v=-v;
	if(v==S)
	{
		puts("Yes");
		printf("%d %d\n",s[x].fi,s[x].se);
		printf("%d %d\n",s[y].fi,s[y].se);
		printf("%d %d\n",s[z].fi,s[z].se);
		exit(0);
	}
	return v;
}
int main()
{
	scanf("%d%lld",&n,&S); S*=2;
	for(int i=1;i<=n;++i)
		scanf("%d%d",&s[i].fi,&s[i].se);
	sort(s+1,s+1+n);
	for(int i=1;i<=n;++i)
		id[i]=a[i]=i;
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			ps[++pn]=mp(ang(s[j]-s[i]),pii(i,j));
	sort(ps+1,ps+1+pn);
	for(int i=1;i<=pn;++i)
	{
		int x=ps[i].se.fi,y=ps[i].se.se;
		if(id[x]>id[y]) swap(x,y);
		int l=1,r=id[x]-1;
		while(r-l>3)
		{
			int m=(l+r)>>1;
			ll s=area(a[m],x,y);
			if(s>S) l=m+1; else r=m-1;
		}
		for(int i=l;i<=r;++i) area(a[i],x,y);
		l=id[y]+1,r=n;
		while(r-l>3)
		{
			int m=(l+r)>>1;
			ll s=area(a[m],x,y);
			if(s<S) l=m+1; else r=m-1;
		}
		for(int i=l;i<=r;++i) area(a[i],x,y);
		swap(id[x],id[y]);
		swap(a[id[x]],a[id[y]]);
	}
	puts("No");
}