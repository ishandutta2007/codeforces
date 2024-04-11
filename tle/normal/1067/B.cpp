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
int n,k,d[SZ],fa[SZ],de[SZ]; Edg
pii mx(0,0);
void dfs(int x,int f=0)
{
	d[x]=d[f]+1; fa[x]=f;
	mx=max(mx,pii(d[x],x));
	for esb(x,e,b) if(b!=f)
		dfs(b,x);
}
void dd(int x,int dp,int f=0)
{
	int so=0;
	for esb(x,e,b) if(b!=f)
		dd(b,dp+1,x),++so;
	if(so&&so<3)
	{
		puts("No");
		exit(0);
	}
	if(so==0&&dp!=k)
	{
		puts("No");
		exit(0);
	}
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1,a,b;i<n;++i)
		scanf("%d%d",&a,&b),
		++de[a],++de[b],adde(a,b);
	dfs(1,0);
	int u=mx.se;
	mx=pii(0,0);
	dfs(u,0);
	if(mx.fi!=k*2+1)
	{
		puts("No");
		return 0;
	}
	int v=mx.se,t=v;
	for(int j=1;j<=k;++j) t=fa[t];
	dd(t,0,0);
	puts("Yes");
}