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
Edg
int n,cc[SZ],col[SZ],sz[SZ],son[SZ];
ll anss[SZ];
void gs(int x,int f=0)
{
    sz[x]=1;
    for esb(x,e,b)
    {
        if(b==f) continue;
        gs(b,x); sz[x]+=sz[b];
        if(sz[b]>sz[son[x]]) son[x]=b;
    }
}
int skip=0;
int cx=0; ll sum=0;
void edt(int x,int f,int k)
{
    cc[col[x]]+=k;
    if(k>0&&cc[col[x]]>=cx)
    {
        if(cc[col[x]]>cx)
            sum=0, cx=cc[col[x]];
        sum+=col[x];
    }
    for esb(x,e,b)
        if(b!=f&&b!=skip) edt(b,x,k);
}
void dfs(int x,int f=0,bool kep=0)
{
    for esb(x,e,b)
        if(b!=f&&b!=son[x]) dfs(b,x);
    if(son[x])
        dfs(son[x],x,1), skip=son[x];
    edt(x,f,1);
    anss[x]=sum;
	skip=0;
    if(!kep) edt(x,f,-1), cx=sum=0;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",col+i);
    for(int i=1;i<n;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        adde(a,b); 
    }
    gs(1); dfs(1);
    for(int i=1;i<=n;i++) printf("%I64d ",anss[i]);
}