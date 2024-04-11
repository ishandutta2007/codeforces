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
#include <assert.h>
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
int n,ls[SZ],ln;
pair<pii,pii> a[SZ];
const int M=262144;
struct seg
{
int a[SZ];
void init()
{
	memset(a,127/2.01,sizeof a);
}
void cmin(int l,int r,int u)
{
	for(l+=M-1,r+=M+1;l^r^1;l>>=1,r>>=1)
	{
		if(~l&1) a[l^1]=min(a[l^1],u);
		if(r&1) a[r^1]=min(a[r^1],u);
	}
}
void pd()
{
	for(int i=1;i<M;++i)
		a[i+i]=min(a[i+i],a[i]),
		a[i+i+1]=min(a[i+i+1],a[i]);
}
}A,B;
#define LS(p) (lower_bound(ls+1,ls+1+ln,p)-ls)
bool work()
{
	sort(a+1,a+1+n); ln=0;
	for(int i=1;i<=n;++i)
		ls[++ln]=a[i].se.fi,
		ls[++ln]=a[i].se.se+1;
	sort(ls+1,ls+1+ln);
	for(int i=1;i<=n;++i)
		a[i].se.fi=LS(a[i].se.fi),
		a[i].se.se=LS(a[i].se.se+1)-1;
	A.init(); B.init();
	for(int i=1;i<=n;++i)
	{
		A.cmin(a[i].se.fi,a[i].se.se,a[i].fi.se);
		B.cmin(a[i].se.fi,a[i].se.se,-a[i].fi.fi);
	}
	A.pd(); B.pd();
	for(int i=1;i<ln;++i)
		if(A.a[i+M]<-B.a[i+M])
			return 0;
	return 1;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d%d%d%d",&a[i].fi.fi,
		&a[i].fi.se,&a[i].se.fi,&a[i].se.se);
	bool ok=work();
	for(int i=1;i<=n;++i)
		swap(a[i].fi,a[i].se);
	ok&=work();
	puts(ok?"YES":"NO");
}