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
int ch[SZ][2],fa[SZ],vv[SZ],mx[SZ];
bool rev[SZ];
bool top(int x) {return !(ch[fa[x]][0]==x||ch[fa[x]][1]==x);}
void pd(int x)
{
    if(!rev[x]) return;
    rev[x]=0;
    rev[ch[x][0]]^=1;
    rev[ch[x][1]]^=1;
    swap(ch[x][0],ch[x][1]);
}
void upd(int x)
{
    //sum[x]=sum[ch[x][0]]+sum[ch[x][1]]+vv[x];
    if(vv[mx[ch[x][0]]]>vv[mx[ch[x][1]]]&&vv[mx[ch[x][0]]]>vv[x]) mx[x]=mx[ch[x][0]];
    else if(vv[mx[ch[x][1]]]>vv[x]) mx[x]=mx[ch[x][1]];
    else mx[x]=x;
    
}
void rot(int x)
{
    if(top(x)) return;
    int y=fa[x],c=ch[y][0]==x;
    int f=fa[y];
    if(!top(y)) ch[f][ch[f][1]==y]=x; //f
    if(ch[x][c]) fa[ch[x][c]]=y;
    ch[y][!c]=ch[x][c];
    ch[x][c]=y; fa[x]=f; fa[y]=x;
    upd(y); upd(x);
}
int ss[SZ],sn;
void splay(int x)
{
    sn=0;
    for(int c=x;;c=fa[c])
    {
        ss[++sn]=c;
        if(top(c)) break;
    }
    while(sn) pd(ss[sn--]);
    while(!top(x))
    {
        int y=fa[x];
        if(!top(y))
        {
            if(ch[fa[y]][0]==y^ch[y][0]==x) rot(x);
            else rot(y);
        }
        rot(x);
    }
}
void access(int x)
{
    for(int c=0;x;c=x,x=fa[x]) splay(x), ch[x][1]=c, upd(x);
}
void makeroot(int x) {access(x); splay(x); rev[x]^=1;}
void link(int a,int b) {makeroot(a); fa[a]=b;}
void cut(int a,int b) {makeroot(a); access(b); splay(b); ch[b][0]=fa[a]=0;}
int findroot(int x)
{
    access(x); splay(x);
    int lc=x;
    while(ch[lc][0]) lc=ch[lc][0];
    splay(lc); return lc;
}
int getrd(int a,int b) {makeroot(a); access(b); splay(b); return b;}
int n,m,anss[SZ];
struct qs_ {int k,l,r,id;}qs[SZ]; int Q;
bool operator < (qs_ a,qs_ b)
{
	if(a.r!=b.r) return a.r<b.r;
	if(a.k!=b.k) return a.k<b.k;
	return a.l<b.l;
}
int ea[SZ],eb[SZ],q;
int bs[SZ];
void edt(int x,int y)
{
	for(;x<=233333;x+=x&-x)
		bs[x]+=y;
}
int sum(int r)
{
	int a=0;
	for(;r>=1;r-=r&-r)
		a+=bs[r];
	return a;
}
int sum(int l,int r) {return sum(r)-sum(l-1);}
int main()
{
    scanf("%d%*d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
    	int a,b;
    	scanf("%d%d",&a,&b);
    	vv[i+n]=a; ea[i]=a; eb[i]=b;
    	qs[++Q]=qs_{0,a,b,i};
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
    {
    	int a,b;
    	scanf("%d%d",&a,&b);
    	qs[++Q]=qs_{1,a,b,i};
    	anss[i]=b-a+1;
	}
	sort(qs+1,qs+1+Q);
    for(int i=1;i<=Q;i++)
    {
    	if(!qs[i].k)
    	{
    		int l=qs[i].l,r=qs[i].r;
   			if(findroot(l)==findroot(r))
   			{
			int g=mx[getrd(l,r)];
			if(vv[g]>=l) continue;
			edt(ea[g-n],-1);
			cut(g,ea[g-n]); cut(g,eb[g-n]);
			}
			edt(l,1);
   			link(l,qs[i].id+n);
   			link(qs[i].id+n,r);
		}
		else anss[qs[i].id]-=sum(qs[i].l,qs[i].r);
    }
	for(int i=1;i<=q;i++)
		printf("%d\n",anss[i]);
}