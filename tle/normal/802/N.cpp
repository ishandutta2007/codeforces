#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <limits>
#include <set>
#include <map>
using namespace std;
#define SZ 233333
typedef long long ll;
int M=1,S,T,fst[SZ],nxt[SZ],va[SZ],vb[SZ];
ll cap[SZ],cost[SZ];
void ad_dl(int a,int b,ll ca,ll co)
{
    ++M; nxt[M]=fst[a]; fst[a]=M; va[M]=a; vb[M]=b; cap[M]=ca; cost[M]=co;
}
void addl(int a,int b,ll ca,ll co) {ad_dl(a,b,ca,co); ad_dl(b,a,0,-co);}
ll dis[SZ]; int n,q[SZ],fe[SZ];
bool inq[SZ];
bool spfa()
{
    ll inf=2000000000000000LL;
    for(int i=1;i<=n;i++) dis[i]=inf;
    inq[S]=1; q[1]=S; dis[S]=0; int h=1,t=2;
    while(h!=t)
    {
        int cur=q[h++]; h&=131071;
        for(int e=fst[cur];e;e=nxt[e])
        {
            if(!cap[e]||dis[vb[e]]<=dis[cur]+cost[e]) continue;
            int b=vb[e],co=cost[e];
            dis[b]=dis[cur]+co; fe[b]=e;
            if(!inq[b]) {inq[b]=1; q[t++]=b; t&=131071;}
        }
        inq[cur]=0;
    }
    return dis[T]!=inf;
}
ll mcf()
{
    ll ans=0;
    while(spfa())
    {
        ll cur=2000000000000000LL;
        for(int i=fe[T];i;i=fe[va[i]]) cur=min(cur,cap[i]);
        for(int i=fe[T];i;i=fe[va[i]])
        {
            ans+=cur*cost[i];
            cap[i]-=cur; cap[i^1]+=cur;
        }
    }
    return ans;
}
int N,K,a[SZ],b[SZ];
int main()
{
	scanf("%d%d",&N,&K);
	for(int i=1;i<=N;i++) scanf("%d",a+i);
	for(int i=1;i<=N;i++) scanf("%d",b+i);
	n=N+N; int rs=++n; S=++n; T=++n;
	addl(S,rs,K,0);
	for(int i=1;i<=N;i++)
	{
		addl(rs,i,1e9,0);
		addl(i,i+N,1,a[i]);
		addl(i+N,T,1,b[i]);
		if(i!=N)
		{
			addl(i,i+1,1e9,0);
			addl(i+N,i+N+1,1e9,0);
		}
	}
    printf("%lld\n",mcf());
}