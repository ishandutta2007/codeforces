#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
#include <map>
using namespace std;
#define SZ 666666
int n,ff[SZ],deg[SZ],fst[SZ],nxt[SZ],vb[SZ],M=0,fa[SZ];
void ad_de(int a,int b) {++M; nxt[M]=fst[a]; fst[a]=M; vb[M]=b;}
void adde(int a,int b) {ad_de(a,b); ad_de(b,a);}
int gf(int x)
{
	return ff[x]?ff[x]=gf(ff[x]):x;
}
void uni(int a,int b)
{
	int aa=gf(a),bb=gf(b);
	if(aa==bb) return;
	ff[aa]=bb;
}
int ss[SZ],sn=0;
bool del[SZ];
bool spec[SZ];
vector<int> gs[233333];
int ls[SZ],ln=0,gp=0;
void findc(int p)
{
	sn=0;
	for(int x=0;x<gs[p].size();x++)
	{
		int i=gs[p][x];
		if(deg[i]==1) ss[++sn]=i, del[i]=1;
	}
	while(sn)
	{
		int cur=ss[sn--];
		for(int i=fst[cur];i;i=nxt[i])
		{
			--deg[vb[i]];
			if(deg[vb[i]]==1&&!del[vb[i]]) ss[++sn]=vb[i], del[vb[i]]=1;
		}
	}
	for(int x=0;x<gs[p].size();x++)
	{
		if(!del[gs[p][x]]) gp=gs[p][x];
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int gg;
		scanf("%d",&gg);
		fa[i]=gg;
		uni(i,gg); adde(i,gg);
		++deg[i]; ++deg[gg];
	}
	for(int i=1;i<=n;i++)
	{
		if(fa[i]==i) spec[gf(i)]=1;
		gs[gf(i)].push_back(i);
	}
	for(int i=1;i<=n;i++)
	{
		if(gf(i)==i&&spec[i]) ls[++ln]=gf(i);
	}
	for(int i=1;i<=n;i++)
	{
		if(gf(i)==i&&!spec[i]) ls[++ln]=gf(i);
	}
	int lst=0,ans=0;
	for(int i=1;i<=ln;i++)
	{
		int x=ls[i]; findc(x);
		int g=gp;
		if(!lst) lst=g;
		if(fa[g]!=lst) ++ans;
		fa[g]=lst; lst=g;
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;i++) printf("%d ",fa[i]);
}