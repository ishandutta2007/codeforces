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
int n,m,d;
vector<int> ad[SZ]; 
int M=0,fst[100002*51],vb[100002*51],nxt[100002*51];
void ad_de(int a,int b){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;}
char s[100000][53];
int dfn[100000*51],low[100000*51],C=0,G=0,bl[100000*51];
bool ins[100000*51]; int st[100000*51],sn=0;
int id[100000*51],dp[100000*51],ex[100000*51],vv[100005];
bool good[100005*51];
int su[100005*51];
bool cmp(int a,int b)
{return bl[a]<bl[b];}
void tarjan(int x)
{
    dfn[x]=low[x]=++C; st[++sn]=x; ins[x]=1;
    for esb(x,e,b)
    {
        if(!dfn[b])
            tarjan(b), low[x]=min(low[b],low[x]);
        else if(ins[b]) low[x]=min(low[x],dfn[b]);
    }
    if(low[x]!=dfn[x]) return;
    ++G;
    while(1)
    {
    	int r=st[sn--];
		bl[r]=G; ins[r]=0;
		if(r==x) break;
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&d);
	for(int i=1,a,b;i<=m;++i)
		scanf("%d%d",&a,&b),ad[a-1].pb(b-1);
	for(int i=0;i<n;++i)
		scanf("%s",s[i]);
	for(int i=0;i<n;++i)
		for(int j=0;j<d;++j)
			for(auto u:ad[i])
				ad_de(i*d+j,u*d+(j+1)%d);
	for(int i=0;i<n;++i)
		if(!dfn[i]) tarjan(i);
	for(int i=0;i<n*d;++i)
		++su[bl[i]];
	for(int i=1;i<=n*d+3;++i)
		su[i]+=su[i-1];
	for(int i=0;i<n*d;++i)
		id[--su[bl[i]]]=i;
	memset(vv,-1,sizeof vv);
	int ans=0;
	for(int i=0;i<n*d;++i)
	{
		int x=id[i],y=bl[x];
		for esb(x,e,b)
			if(bl[b]<y)
				dp[y]=max(dp[y],dp[bl[b]]+ex[bl[b]]);
		if(x==0) good[y]=1;
		if(vv[x/d]!=y&&s[x/d][x%d]!='0') ++ex[y],vv[x/d]=y;
		if(good[y]) ans=max(ans,dp[y]+ex[y]);
	}
	printf("%d\n",ans);
}