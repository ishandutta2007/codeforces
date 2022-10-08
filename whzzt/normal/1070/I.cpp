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
typedef long long ll;
int fst[SZ],nxt[SZ],vb[SZ],cap[SZ],ff[SZ],M=1,N=0;
#define ad_de ad_dl
void _ad_dl(int a,int b,int c) {++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;cap[M]=c;}
void ad_dl(int a,int b,int c)
{_ad_dl(a,b,c); _ad_dl(b,a,0);}
int S,T,q[SZ],d[SZ];
bool bfs()
{
    memset(d,-1,4*(N+1));
    d[T]=0; q[1]=T; int h=1,t=2;
    while(h!=t)
    {
        int cur=q[h++];
        for(int e=fst[cur];e;e=nxt[e])
        {
            int b=vb[e];
            if(d[b]==-1&&cap[e^1])
            {
                d[b]=d[cur]+1, q[t++]=b;
                if(b==S) return 1;
            }
        }
    }
    return d[S]!=-1;
}
int dfs(int x,int f)
{
    if(f<=0) return 0;
    if(x==T) return f;
    int ca=0;
    for(int& e=fst[x];e;e=nxt[e])
    {
        int b=vb[e];
        if(d[b]+1!=d[x]) continue;
        int w=dfs(b,(cap[e]<f-ca)?cap[e]:(f-ca));
        cap[e]-=w; cap[e^1]+=w; ca+=w;
        if(ca==f) break;
    }
    if(!ca) d[x]=-1;
    return ca;
}
#define inf 2e9+3
int dinic()
{
    int ans=0;
    memcpy(ff,fst,4*(N+1));
    while(bfs())
    {
        ans+=dfs(S,inf);
        memcpy(fst,ff,4*(N+1));
    }
    return ans;
}
void clr()
{
	M=1;
	for(int i=1;i<=N;++i) fst[i]=0;
}
vector<int> pool[2333];
int n,m,k,dd[2333],col[2333],aa[2333],
bb[2333],u[2333],cm[2333];
void sol()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;++i)
		dd[i]=0,pool[i].clear();
	for(int i=1;i<=m;++i)
	{
		scanf("%d%d",aa+i,bb+i);
		++dd[aa[i]];++dd[bb[i]];
	}
	for(int i=1;i<=n;++i)
		u[i]=max(dd[i]-k,0)*2;
	clr();
	N=n; S=++N; T=++N;
	int su=0;
	for(int i=1;i<=n;++i)
		ad_dl(i,T,u[i]),su+=u[i];
	for(int i=1;i<=m;++i)
	{
		int u=++N;
		ad_dl(S,u,1);
		ad_dl(u,aa[i],1); cm[i]=M;
		ad_dl(u,bb[i],1);
	}
	if(su!=dinic())
	{
		for(int i=1;i<=m;++i)
			printf("0 ");
		puts("");
		return;
	}
	for(int i=1;i<=m;++i) col[i]=i;
	int g=m;
	for(int i=1;i<=m;++i)
	{
		if(cap[cm[i]])
			pool[aa[i]].pb(i);
		else if(cap[cm[i]+2])
			pool[bb[i]].pb(i);
	}
	for(int i=1;i<=n;++i)
		for(int j=0;j<pool[i].size();j+=2)
			col[pool[i][j]]=col[pool[i][j+1]]=++g;
	for(int i=1;i<=m;++i)
		printf("%d ",col[i]);
	puts("");
}
int main()
{
	int T; scanf("%d",&T);
	while(T--) sol();
}