#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stack>
#include <string.h>
#include <queue>
using namespace std;
typedef long long ll;
#define SZ 333333
int n,m,q,i1[SZ],i2[SZ],qa[SZ],qb[SZ];
int M=0,fst[SZ],vb[SZ],nxt[SZ],vc[SZ];
int ad_de(int a,int b,int c){++M;nxt[M]
=fst[a];fst[a]=M;vb[M]=b;vc[M]=c;return M;}
ll dist[SZ],od[SZ];
typedef pair<ll,int> pii;
#define fi first
#define se second
void dj()
{
	priority_queue<pii,vector<pii>,greater<pii> > pq;
	for(int i=1;i<=n;++i)
		dist[i]=1e18;
	dist[1]=0;
	pq.push(pii(0,1));
	while(!pq.empty())
	{
		pii t=pq.top(); pq.pop();
		if(t.fi!=dist[t.se]) continue;
		int x=t.se;
		for(int e=fst[x];e;e=nxt[e])
		{
			int b=vb[e];
			if(dist[b]<=dist[x]+vc[e])
				continue;
			dist[b]=dist[x]+vc[e];
			pq.push(pii(dist[b],b));
		}
	}
}
#define SS 3333333
int tp[SS],ns[SS],xx[SS],C=0;
void dj2(int s)
{
	C=0;
	for(int i=0;i<=s;++i) tp[i]=0;
	for(int i=1;i<=n;++i)
		od[i]=dist[i],dist[i]=1e18;
	dist[1]=0; ++C; xx[C]=1; ns[C]=0; tp[0]=C;
	for(int i=0;i<=s;++i)
	{
		while(tp[i])
		{
			int x=xx[tp[i]]; tp[i]=ns[tp[i]];
			if(dist[x]!=i) continue;
			for(int e=fst[x];e;e=nxt[e])
			{
				int b=vb[e];
				ll vv=vc[e]-od[b]+od[x];
				if(dist[b]<=dist[x]+vv)
					continue;
				dist[b]=dist[x]+vv;
				if(dist[b]<=s)
					++C, ns[C]=tp[dist[b]],
					xx[C]=b, tp[dist[b]]=C;
			}
		}
	}
	for(int i=1;i<=n;++i)
	{
		dist[i]+=od[i];
		if(dist[i]>1e18) dist[i]=1e18;
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=m;++i)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		i1[i]=ad_de(a,b,c);
	}
	dj();
	int shi=0;
	for(int i=1;i<=q;++i)
	{
		int t,x;
		scanf("%d%d",&t,&x);
		if(t==1)
		{
			if(shi) dj2(shi),shi=0;
			ll d=dist[x],op;
			if(d>1e17) op=-1;
			else op=d;
			printf("%lld\n",op);
		}
		else
		{
			while(x--)
			{
				int p; scanf("%d",&p);
				++vc[i1[p]]; ++shi;
			}
		}
	}
}