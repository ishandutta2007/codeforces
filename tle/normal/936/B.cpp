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
int n; vector<int> adj[SZ];
pii vis[SZ][2]; int cnt[SZ],cm=0;
int dfn[SZ],low[SZ],C=0; bool ins[SZ];
int st[SZ],sn=0;
void tarjan(int x)
{
    dfn[x]=low[x]=++C; st[++sn]=x; ins[x]=1;
    for(auto b:adj[x])
    {
        if(!dfn[b])
            tarjan(b), low[x]=min(low[b],low[x]);
        else if(ins[b]) low[x]=min(low[x],dfn[b]);
    }
    if(low[x]!=dfn[x]) return;
    vector<int> v;
    while(1)
    {
    	int r=st[sn--];
    	v.pb(r); ins[r]=0;
		if(r==x) break;
	}
	if(v.size()>1) cm=1;
}
void dfs2(int s,int g)
{
	for(auto b:adj[s]) if(!vis[b][g^1].fi)
	{
		vis[b][g^1]=pii(s,g); dfs2(b,g^1);
	}
}
int main()
{
	int m; scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	{
		int c,x; scanf("%d",&c);
		while(c--)
			scanf("%d",&x),adj[i].pb(x);
	}
	int s; scanf("%d",&s); tarjan(s);
	vis[s][0]=pii(-1,-1); dfs2(s,0);
	for(int i=1;i<=n;++i) if(!adj[i].size()&&vis[i][1].fi)
	{
		pii g(i,1); vector<int> w;
		while(g.fi>-1) w.pb(g.fi),g=vis[g.fi][g.se];
		reverse(w.begin(),w.end());
		puts("Win");
		for(auto s:w) printf("%d ",s);
		return 0;
	}
	if(cm) puts("Draw");
	else puts("Lose");
}