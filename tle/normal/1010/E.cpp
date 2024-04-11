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
#define SZ 233333
int x[3],n,m,k,a[SZ][3],b[SZ][3],c[SZ][3],
mx[3],mi[3];
int tmp[SZ];
struct ds
{
vector<pii> es[SZ];
vector<pair<pii,int*> > qs[SZ];
void add(int x,int y,int z)
{es[x].pb(pii(y,z));}
void pre()
{
	for(int i=0;i<SZ;++i) tmp[i]=2e9;
	for(int i=1;i<=::x[0];++i)
	{
		for(auto t:es[i])
			for(int g=t.fi;g<SZ;g+=g&-g)
				tmp[g]=min(tmp[g],t.se);
		for(auto t:qs[i])
		{
			int mi=2e9;
			for(int g=t.fi.fi;g>=1;g-=g&-g)
				mi=min(mi,tmp[g]);
			*t.se|=mi<=t.fi.se;
		}
	}
}
void chk(int x,int y,int z,int&tg)
{qs[x].pb(mp(pii(y,z),&tg));}
}ds[8];
int ans[SZ];
int main()
{
	for(int i=0;i<3;++i) scanf("%d",x+i);
	scanf("%d%d%d",&n,&m,&k);
	for(int j=0;j<3;++j) mx[j]=-2e9,mi[j]=2e9;
	for(int i=1;i<=n;++i)
		for(int j=0;j<3;++j)
			scanf("%d",&a[i][j]),
			mx[j]=max(mx[j],a[i][j]),
			mi[j]=min(mi[j],a[i][j]);
	for(int i=1;i<=m;++i)
	{
		bool gg=1;
		for(int j=0;j<3;++j)
		{
			scanf("%d",&b[i][j]);
			gg&=mi[j]<=b[i][j]&&b[i][j]<=mx[j];
		}
		if(gg) {puts("INCORRECT");return 0;}
	}
	for(int t=0;t<8;++t)
	{
		for(int i=1;i<=m;++i)
		{
			int g[3],ok=1;
			for(int j=0;j<3;++j)
			{
				if(t&(1<<j))
				{
					if(b[i][j]>mx[j]) ok=0;
					else g[j]=x[j]+1-b[i][j];
				}
				else
				{
					if(b[i][j]<mi[j]) ok=0;
					else g[j]=b[i][j];
				}
			}
			if(!ok) continue;
			ds[t].add(g[0],g[1],g[2]);
		}
	}
	puts("CORRECT");
	for(int i=1;i<=k;++i)
	{
		int g[8][3],go[8],t=0,ok=1;
		memset(go,-1,sizeof go);
		for(int j=0;j<3;++j)
		{
			scanf("%d",&c[i][j]);
			ok&=mi[j]<=c[i][j]&&c[i][j]<=mx[j];
			for(int t=0;t<8;++t)
			{
				if(c[i][j]>mx[j]&&(t&(1<<j))) go[t]=0;
				if(c[i][j]<mi[j]&&!(t&(1<<j))) go[t]=0;
				if(t&(1<<j)) g[t][j]=x[j]+1-min(c[i][j],mi[j]);
				else g[t][j]=max(c[i][j],mx[j]);
			}
		}
		if(ok) ans[i]=-1;
		else 
			for(int t=0;t<8;++t) if(go[t])
				ds[t].chk(g[t][0],g[t][1],g[t][2],ans[i]);
	}
	for(int t=0;t<8;++t)
		ds[t].pre();
	for(int i=1;i<=k;++i)
		if(ans[i]==-1) puts("OPEN");
		else if(ans[i]) puts("CLOSED");
		else puts("UNKNOWN");
}