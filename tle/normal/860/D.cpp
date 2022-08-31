#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
#define SZ 666666
int n,m,M=0,fst[SZ],vb[SZ],nxt[SZ];
void ad_de(int a,int b)
{++M; nxt[M]=fst[a]; fst[a]=M; vb[M]=b;}
void adde(int a,int b) {ad_de(a,b); ad_de(b,a);}
bool vis[SZ],cho[SZ]; int r[SZ];
int sn=0,A[SZ],B[SZ],C[SZ];
#define prt(x,y,z) ++sn,A[sn]=x,B[sn]=y,C[sn]=z
#define deal(a) {if(d) prt(d,x,a),d=0; else d=a;}
void dfs(int x,int f=0)
{
	vis[x]=1; int d=0;
	for(int e=fst[x];e;e=nxt[e])
	{
		int b=vb[e];
		if(cho[e^(e&1)]) continue;
		if(vis[b])
		{cho[e^(e&1)]=1; deal(b)}
		else
		{
			cho[e^(e&1)]=1; dfs(b,x);
			if(r[b]) prt(r[b],b,x);
			else deal(b)
		}
	}
	if(d) r[x]=d;
}
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
int main()
{
	scanf("%d%d",&n,&m); M=1;
	for(int i=1,a,b;i<=m;++i)
		scanf("%d%d",&a,&b),adde(a,b);
	for(int i=1;i<=n;++i)
		if(!vis[i]) dfs(i);
	printf("%d\n",sn);
	for(int i=1;i<=sn;++i)
		printf("%d %d %d\n",A[i],B[i],C[i]);
}