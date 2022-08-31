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
#define SZ 1234567
Edgc
int n,sz[SZ],son[SZ],fc[SZ],dep[SZ];
void gs(int x,int f=0)
{
    sz[x]=1;
    for esb(x,e,b)
    {
        if(b==f) continue;
        fc[b]=fc[x]^vc[e];
        dep[b]=dep[x]+1;
        gs(b,x); sz[x]+=sz[b];
        if(sz[b]>sz[son[x]]) son[x]=b;
    }
}
const int S='v'-'a'+1,inf=1e9;
int md[5555555],cans,skip,cdep;
void clr(int x) {md[fc[x]]=-inf;}
void upd(int x)
{
	cans=max(cans,md[fc[x]]+dep[x]-cdep*2);
	for(int i=0;i<S;i++)
		cans=max(cans,md[fc[x]^(1<<i)]+dep[x]-cdep*2);
}
void ins(int x)
{md[fc[x]]=max(md[fc[x]],dep[x]);}
template<void(*func)(int)>
void edt(int x,int f)
{
	func(x);
    for esb(x,e,b)
        if(b!=f&&b!=skip) edt<func>(b,x);
}
int dp[SZ]; 
void dfs(int x,int f=0,bool kep=0)
{
    for esb(x,e,b)
        if(b!=f&&b!=son[x]) dfs(b,x);
    if(son[x])
        dfs(son[x],x,1), skip=son[x];
    cdep=dep[x];
    for esb(x,e,b) if(b!=f)
    	dp[x]=max(dp[x],dp[b]);
    for esb(x,e,b) if(b!=f&&b!=son[x])
    	edt<upd>(b,x), edt<ins>(b,x);
	upd(x); ins(x);
    dp[x]=max(dp[x],cans);
	skip=0;
    if(!kep) edt<clr>(x,f), cans=-inf;
}
int main()
{
	for(int i=0;i<(1<<S);i++)
		md[i]=-inf;
    scanf("%d",&n);
    for(int i=2;i<=n;i++)
    {
    	int x; char c[3];
    	scanf("%d%s",&x,c);
    	adde(i,x,1<<(c[0]-'a'));
	}
	gs(1); dfs(1);
    for(int i=1;i<=n;i++)
    	printf("%d ",dp[i]);
}