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
struct pii
{
int fi,se;
pii() {}
pii(int a,int b):fi(a),se(b) {}
};
pii operator + (pii a,pii b)
{return pii(min(a.fi,b.fi),max(a.se,b.se));}
struct Seg
{
const int M=262144;
pii seg[555555];
void init()
{
	for(int i=1;i<=M+M;++i)
		seg[i]=pii(2e9,-2e9);
}
void upd(int x,pii g)
{
	seg[x+=M]=g;
	while(x>>=1)
		seg[x]=seg[x+x]+seg[x+x+1];
}
pii qry(int l,int r)
{
	pii a(2e9,-2e9);
	for(l+=M-1,r+=M+1;l^r^1;l>>=1,r>>=1)
	{
		if(~l&1) a=a+seg[l^1];
		if(r&1) a=a+seg[r^1];
	}
	return a;
}
}g[16];
int n,k;
void upd(int x)
{
	register int u[5];
	for(int i=0;i<k;++i)
		scanf("%d",u+i);
	for(int i=0;i<(1<<(k-1));++i)
	{
		int xx=u[k-1];
		for(int j=0;j<k-1;++j)
			if(i&(1<<j)) xx-=u[j];
			else xx+=u[j];
		g[i].upd(x,pii(xx,xx));
	}
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=0;i<(1<<(k-1));++i)
		g[i].init();
	for(int i=1;i<=n;++i) upd(i);
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int o,a,b;
		scanf("%d%d",&o,&a);
		if(o==1) upd(a);
		else
		{
			scanf("%d",&b);
			int ans=0;
			for(int i=0;i<(1<<(k-1));++i)
			{
				auto w=g[i].qry(a,b);
				ans=max(ans,w.se-w.fi);
			}
			printf("%d\n",ans);
		}
	}
}