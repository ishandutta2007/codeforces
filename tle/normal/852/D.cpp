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
#define VIZ {printf("digraph G{\n"); for(int i=1;i<=n;i++) for es(i,e) printf("%d->%d;\n",i,vb[e]); puts("}");}
#define VIZ2 {printf("graph G{\n"); for(int i=1;i<=n;i++) for es(i,e) if(vb[e]>=i)printf("%d--%d;\n",i,vb[e]); puts("}");}
#define SZ 666666
int v,e,n,k,st[SZ],dis[233][666]; Edgc
int q[SZ]; bool iq[SZ];
void spfa(int s,int* d)
{
	int h=0,t=1; q[0]=s;
	for(int i=1;i<=v;i++)
		d[i]=1e9, iq[i]=0;
	d[s]=0; iq[s]=1;
	while(h!=t)
	{
		int cur=q[h++]; h&=524287;
		for(int e=fst[cur];e;e=nxt[e])
		{
			int b=vb[e],c=vc[e];
			if(d[b]<=d[cur]+c) continue;
			d[b]=d[cur]+c;
			if(!iq[b]) q[t++]=b;
			t&=524287;
		}
		iq[cur]=0;
	}
}
namespace Dinic
{
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
                if(b==S) return 1; // 
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
    for(int& e=fst[x];e;e=nxt[e]) // 
    {
        int b=vb[e];
        if(d[b]+1!=d[x]) continue;
        int w=dfs(b,(cap[e]<f-ca)?cap[e]:(f-ca));
        cap[e]-=w; cap[e^1]+=w; ca+=w;
        if(ca==f) break;
    }
    if(!ca) d[x]=-1; // 
    return ca;
}
#define inf 2e9+3
int dinic()
{
    int ans=0;
    memcpy(ff,fst,4*(N+1));
    while(bfs())
    {
        //
        ans+=dfs(S,inf);
        memcpy(fst,ff,4*(N+1));
    }
    return ans;
}
bool ok(int r)
{
	memset(fst,0,sizeof fst);
	M=1; N=n; S=++N; T=++N;
	for(int i=1;i<=n;++i)
		ad_dl(S,i,1);
	int p=N; N+=v;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=v;++j) if(dis[i][j]<=r)
			ad_dl(i,j+p,1);
	for(int j=1;j<=v;++j)
		ad_dl(j+p,T,1);
	int s=dinic();
	return s>=k;
}
}
#define UP 1731311
int main()
{
	scanf("%d%d%d%d",&v,&e,&n,&k);
	for(int i=1;i<=n;++i)
		scanf("%d",st+i);
	for(int i=1;i<=e;++i)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		adde(a,b,c);
	}
	for(int i=1;i<=n;++i)
		spfa(st[i],dis[i]);
	int l=0,r=UP+1;
	while(l<r)
	{
		int s=(l+r)>>1;
		if(Dinic::ok(s)) r=s; else l=s+1;
	}
	if(l<=UP) printf("%d\n",l);
	else puts("-1");
}