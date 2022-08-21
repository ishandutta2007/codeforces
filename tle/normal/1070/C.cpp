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
#define SZ 2333333
const int M=1048576;
int n,k,m;
ll mi[SZ];
int ls[SZ],rs[SZ],tg[SZ],su[SZ];
struct gs {int l,r,c,p;} aa[233333];
bool operator < (gs a,gs b) {return a.p<b.p;}
ll ans=0;
void pd(int x)
{
	if(!tg[x]) return;
	mi[x]-=tg[x];
	if(x<=M)
		tg[x+x]+=tg[x],tg[x+x+1]+=tg[x];
	tg[x]=0;
}
void upd(int x)
{
	pd(x+x); pd(x+x+1);
	mi[x]=min(mi[x+x],mi[x+x+1]);
	su[x]=su[x+x]+su[x+x+1];
}
void go(int x,int l,int r,int c,int p)
{
	if(rs[x]<l||r<ls[x]||!su[x]) return;
	pd(x);
	if(l<=ls[x]&&rs[x]<=r)
	{
		if(mi[x]>c)
		{
			tg[x]+=c;
			ans+=su[x]*(ll)c*p;
			return;
		}
		if(ls[x]==rs[x])
		{
			ans+=mi[x]*(ll)p;
			mi[x]=8e18; su[x]=0;
			return;
		}
	}
	go(x+x,l,r,c,p);
	go(x+x+1,l,r,c,p);
	upd(x);
}
int main()
{
	scanf("%d%d%d",&n,&k,&m);
	for(int i=1;i<=m;++i)
		scanf("%d%d%d%d",&aa[i].l,&aa[i].r,
		&aa[i].c,&aa[i].p);
	sort(aa+1,aa+1+m);
	for(int i=1;i<=n;++i)
		mi[i+M]=k,su[i+M]=1;
	for(int i=1;i<=M;++i)
		ls[i+M]=rs[i+M]=i;
	for(int i=M-1;i>=1;--i)
		mi[i]=min(mi[i+i],mi[i+i+1]),
		ls[i]=ls[i+i],rs[i]=rs[i+i+1],
		su[i]=su[i+i]+su[i+i+1];
	for(int i=1;i<=m;++i)
		go(1,aa[i].l,aa[i].r,aa[i].c,aa[i].p);
	printf("%lld\n",ans);
}