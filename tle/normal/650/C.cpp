//By zzq
#pragma comment(linker, "/STACK:10240000,10240000")
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <set>
#include <map>
using namespace std;
#define SZ 4333333
int n,m,gf[SZ],a[SZ];
#define ID(i,j) (((i)-1)*m+(j)-1)
typedef pair<int,int> pii;
pii ps[SZ];
int ff(int x) {return gf[x]?gf[x]=ff(gf[x]):x;}
void unionn(int a,int b)
{
	int ga=ff(a),gb=ff(b);
	if(ga!=gb) gf[ga]=gb;
}
int M=0,ma[SZ],mb[SZ];
int MM=0,fst[SZ],nxt[SZ],vb[SZ];
void adde(int a,int b)
{
	++MM; nxt[MM]=fst[a]; fst[a]=MM; vb[MM]=b;
}
int dep[SZ]; bool vis[SZ];
int gd(int x)
{
	if(vis[x]) return dep[x];
	int mn=0;
	for(int e=fst[x];e;e=nxt[e])
	{
		int b=vb[e];
		mn=max(mn,gd(b));
	}
	vis[x]=1; return dep[x]=mn+1;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++) scanf("%d",&a[ID(i,j)]); 
	}
	for(int i=1;i<=n;i++)
	{
		int pn=0;
		for(int j=1;j<=m;j++) ps[++pn]=pii(a[ID(i,j)],j);
		sort(ps+1,ps+1+pn);
		for(int j=2;j<=pn;j++)
		{
			pii lst=ps[j-1],cur=ps[j];
			int i1=ID(i,lst.second),i2=ID(i,cur.second);
			if(lst.first==cur.first) unionn(i1,i2);
			else ++M, ma[M]=i2, mb[M]=i1; //i1<i2
		}
	}
	for(int j=1;j<=m;j++)
	{
		int pn=0;
		for(int i=1;i<=n;i++) ps[++pn]=pii(a[ID(i,j)],i);
		sort(ps+1,ps+1+pn);
		for(int i=2;i<=pn;i++)
		{
			pii lst=ps[i-1],cur=ps[i];
			int i1=ID(lst.second,j),i2=ID(cur.second,j);
			if(lst.first==cur.first) unionn(i1,i2);
			else ++M, ma[M]=i2, mb[M]=i1; //i1<i2
		}
	}
	for(int i=1;i<=M;i++)
	{
		int a=ma[i],b=mb[i];
		int f1=ff(a),f2=ff(b);
		adde(f1,f2);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++) gd(ff(ID(i,j)));
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++) printf("%d ",dep[ff(ID(i,j))]);
		printf("\n");
	}
}