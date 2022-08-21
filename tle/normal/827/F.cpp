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
int n,m,en;
struct edg
{
int a,b,l,r,o,t;
}es[SZ];
pii ps[SZ];
multiset<int> sb[SZ][2];
set<int> aw[SZ][2];
struct scmp
{
bool operator () (pii a,pii b)
{
	if(a.fi!=b.fi) return a.fi>b.fi;
	return es[a.se].r<es[b.se].r;
}
};
priority_queue<pii,vector<pii>,scmp> eve;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
	{
		int a,b,l,r;
		scanf("%d%d%d%d",&a,&b,&l,&r); --r;
		for(int o=0;o<2;++o)
		{
			int L=l,R=r;
			if((L-o)&1) ++L;
			if((R-o)&1) --R;
			if(L<=R) es[++en]=edg{a,b,L,R,o,-1},
			es[++en]=edg{b,a,L,R,o,-1};
		}
	}
//	for(int i=1;i<=en;++i)
//		cerr<<i<<":"<<es[i].a<<","<<es[i].b<<','<<es[i].l<<","<<es[i].r<<","<<es[i].o<<","<<es[i].t<<"\n";
	for(int i=1;i<=en;++i)
		eve.push(pii(es[i].l,i)),
		eve.push(pii(es[i].r+1,i));
	while(!eve.empty())
	{
		auto _=eve.top(); eve.pop();
		int x=_.se;
		if(_.fi<=es[x].r) //ins
		{
			bool ok=(es[x].l==0&&es[x].a==1);
			ok|=(sb[es[x].a][es[x].o].size()!=0)
			&&(*sb[es[x].a][es[x].o].begin()<_.fi);
			if(ok)
			{
				sb[es[x].b][es[x].o^1].insert(_.fi);
				es[x].t=_.fi;
				if(es[x].t+1<=es[x].r)
				{
				for(auto g:aw[es[x].b][es[x].o^1])
					if(es[x].t+1<=es[g].r) eve.push(pii(es[x].t+1,g));
				aw[es[x].b][es[x].o^1].clear();
				}
			}
			else aw[es[x].a][es[x].o].insert(x),es[x].t=-1;
		}
		else
		{
			if(es[x].t==-1)
				aw[es[x].a][es[x].o].erase(x);
			else
			{
				sb[es[x].b][es[x].o^1].erase(
				sb[es[x].b][es[x].o^1].find(es[x].t));
			}
		}
	}
	int ans=(n==1)?0:2e9;
	for(int i=1;i<=en;++i)
		if(es[i].b==n&&es[i].t!=-1)
			ans=min(ans,es[i].t+1);
	if(ans>1.1e9) ans=-1;
	printf("%d\n",ans);
}