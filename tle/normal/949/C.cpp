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
int n,m,h,u[SZ]; Edg
int bl[SZ],R=0; vector<int> rs[SZ];
int dfn[SZ],low[SZ],C=0,ss[SZ],sn=0,ins[SZ];
void tj(int x)
{
	dfn[x]=low[x]=++C; ss[++sn]=x; ins[x]=1;
	for esb(x,e,b)
	{
		if(!dfn[b])
		{tj(b); low[x]=min(low[x],low[b]);}
		else if(ins[b]) low[x]=min(low[x],dfn[b]);
	}
	if(dfn[x]!=low[x]) return;
	int g; ++R;
	while(1)
	{
		g=ss[sn--]; rs[R].pb(g);
		ins[g]=0; bl[g]=R;
		if(g==x) break;
	}
}
bool ban[SZ];
int main()
{
	scanf("%d%d%d",&n,&m,&h);
	for(int i=1;i<=n;++i)
		scanf("%d",u+i);
	for(int i=1;i<=m;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if((u[x]+1)%h==u[y]) ad_de(y,x);
		if((u[y]+1)%h==u[x]) ad_de(x,y);
	}
	pii ans(1e9,1e9);
	for(int i=1;i<=n;++i)
		if(!dfn[i]) tj(i);
	for(int i=1;i<=n;++i)
		for esb(i,e,b)
			if(bl[i]!=bl[b]) ban[bl[b]]=1;
	for(int i=1;i<=R;++i)
		if(!ban[i]) ans=min(ans,pii(rs[i].size(),i));
	printf("%d\n",ans.fi);
	for(auto x:rs[ans.se]) printf("%d ",x);
}