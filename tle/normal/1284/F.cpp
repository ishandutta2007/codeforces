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
#include <assert.h>
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
int n,c[SZ],d[SZ],A[SZ],B[SZ]; Edg
int ch[SZ][2],fa[SZ],vv[SZ],m1[SZ],m2[SZ];
bool rev[SZ];
bool top(int x) {return !(ch[fa[x]][0]==x||ch[fa[x]][1]==x);}
void upd(int x)
{
	if(!x) return;
	if(m1[ch[x][0]]) m1[x]=m1[ch[x][0]];
	else if(vv[x]) m1[x]=vv[x];
	else m1[x]=m1[ch[x][1]];
	if(m2[ch[x][1]]) m2[x]=m2[ch[x][1]];
	else if(vv[x]) m2[x]=vv[x];
	else m2[x]=m2[ch[x][0]];
}
void pd(int x)
{
    if(!rev[x]) return;
    rev[x]=0;
    rev[ch[x][0]]^=1;
    swap(m1[ch[x][0]],m2[ch[x][0]]);
    rev[ch[x][1]]^=1;
    swap(m1[ch[x][1]],m2[ch[x][1]]);
    swap(ch[x][0],ch[x][1]);
}
void rot(int x)
{
    if(top(x)) return;
    int y=fa[x],c=ch[y][0]==x;
    int f=fa[y];
    if(!top(y)) ch[f][ch[f][1]==y]=x;
    if(ch[x][c]) fa[ch[x][c]]=y;
    ch[y][!c]=ch[x][c];
    ch[x][c]=y; fa[x]=f; fa[y]=x;
    upd(y); upd(x); upd(f);
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
	for(int j=sn;j>=1;--j) pd(ss[j]);
	for(int j=1;j<=sn;++j) upd(ss[j]);
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
void makeroot(int x) {access(x); splay(x); rev[x]^=1; swap(m1[x],m2[x]);}
void link(int a,int b) {makeroot(a); fa[a]=b;}
void cut(int a,int b) {makeroot(a); access(b); splay(b); ch[b][0]=fa[a]=0; upd(b);}
int findroot(int x)
{
    access(x); splay(x);
    int lc=x;
    while(ch[lc][0]) lc=ch[lc][0];
    splay(lc); return lc;
}
int getrd(int a,int b) {makeroot(a); access(b); splay(b); return b;}
void dfs(int x,int f=0)
{
	for esb(x,e,b)
		if(b!=f) dfs(b,x);
	if(f)
	{
		//covering x--f
		int e=m1[getrd(x,f)];
//		cout<<c[e]<<"w"<<d[e]<<"!!\n";
		cut(c[e],e+n);
		cut(d[e],e+n);
		assert(e);
		printf("%d %d %d %d\n",x,f,c[e],d[e]);
		m1[e+n]=m2[e+n]=vv[e+n]=0;
		link(x,e+n);
		link(f,e+n);
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1,a,b;i<n;++i)
		scanf("%d%d",&a,&b),adde(a,b),
		A[i]=i,B[i]=i;
	for(int i=1;i<n;++i)
	{
		scanf("%d%d",c+i,d+i);
		m1[i+n]=m2[i+n]=vv[i+n]=i;
		link(c[i],i+n);
		link(d[i],i+n);
	}
	printf("%d\n",n-1);
	dfs(1);
}