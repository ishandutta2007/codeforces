//By zzq
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define fi first
#define se second
#define SZ 666666
typedef long long ll;
int n,m,s,t,fst[SZ],vb[SZ],nxt[SZ],vid[SZ],M=0,l,vc[SZ];
int ea[SZ],eb[SZ],emp[SZ]; ll ec[SZ];
ll d1[SZ],d2[SZ];
void clr()
{
	M=0; memset(fst,0,sizeof(fst));
}
void ad_de(int a,int b,int c,int i)
{
	++M; nxt[M]=fst[a]; fst[a]=M; vb[M]=b; vc[M]=c; vid[M]=i;
}
typedef pair<int,ll> rec;
void dj(int s,ll* d,int t)
{
	priority_queue<rec,vector<rec>,greater<rec> > pq;
	d[s]=0; pq.push({d[s],s});
	while(!pq.empty())
	{
		rec xx=pq.top(); pq.pop();
		if(xx.fi!=d[xx.se]) continue;
		int x=xx.se;
		for(int e=fst[x];e;e=nxt[e])
		{
			int b=vb[e],c=vc[e],i=vid[e];
			if(t&&emp[i]) c=ec[i]=max(ec[i],l-d[x]-d1[b]);
			if(d[b]<=d[x]+c) continue;
			d[b]=d[x]+c;
			pq.push({d[b],b});
		}
	}
}
int main()
{
	memset(d1,127/3,sizeof(d1));
	memset(d2,127/3,sizeof(d2));
	scanf("%d%d%d%d%d",&n,&m,&l,&s,&t);
	++s; ++t;
	for(int i=1;i<=m;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		++a; ++b; emp[i]=!c; if(!c) c=1;
		ea[i]=a; eb[i]=b; ec[i]=c;
		ad_de(a,b,c,i); ad_de(b,a,c,i);
	}
	dj(t,d1,0); dj(s,d2,1);
	if(d2[t]!=l)
	{
		puts("NO");
		return 0;
	}
	puts("YES");
	for(int i=1;i<=m;i++)
	printf("%d %d %I64d\n",ea[i]-1,eb[i]-1,ec[i]);
}