#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define SZ 666666
int n,a[SZ],fa[SZ],vb[SZ],vc[SZ],M=0,fst[SZ],nxt[SZ],sz[SZ],ans=0;
void ad_de(int a,int b,int c) {++M; nxt[M]=fst[a]; fst[a]=M; vb[M]=b; vc[M]=c;}
void adde(int a,int b,int c) {ad_de(a,b,c); ad_de(b,a,c);}
void dfs1(int x)
{
	sz[x]=1;
	for(int e=fst[x];e;e=nxt[e])
	{
		int b=vb[e],c=vc[e]; if(b==fa[x]) continue;
		fa[b]=x; dfs1(b); sz[x]+=sz[b];
	}
}
void dfs2(int x,long long cur=0,long long mcur=0)
{
	mcur=min(mcur,cur);
	if(cur-mcur>a[x]) {ans+=sz[x]; return;}
	for(int e=fst[x];e;e=nxt[e])
	{
		int b=vb[e],c=vc[e]; if(b==fa[x]) continue;
		dfs2(b,cur+c,mcur);
	}
} 
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	for(int i=1;i<n;i++)
	{
		int p,c; scanf("%d%d",&p,&c);
		adde(i+1,p,c);
	}
	dfs1(1); dfs2(1);
	printf("%d\n",ans);
}