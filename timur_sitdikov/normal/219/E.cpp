#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <complex>
using namespace std;
#define pb push_back
#define mp make_pair

const int maxn=200005;
int n; 
int wh[1000005], ind_of[4*maxn];
struct vertex
{
    int mx, l, r, pr, sf, sz, ll, rr;
};

vertex t[4*maxn];

vertex & unite(vertex & l, vertex & r)
{
    vertex tmp;
    int f, mx2;
    tmp.ll=l.ll;
    tmp.rr=r.rr;
    tmp.sz=l.sz+r.sz;
    tmp.pr=l.pr;
    if (l.pr==l.sz)
        tmp.pr+=r.pr;
    tmp.sf=r.sf;
    if (r.sf==r.sz)
        tmp.sf+=l.sf;
    if (l.mx>=r.mx)
    {
        f=0;
        tmp.mx=l.mx;
        tmp.l=l.l;
        tmp.r=l.r;
    }
    else
    {
        f=1;
        tmp.mx=r.mx;
        tmp.l=r.l;
        tmp.r=r.r;
    }
    if (l.sf && r.pr)
    {
        mx2=(l.sf+r.pr+1)>>1;
        if (l.rr-l.sf+1==0 || r.ll+r.pr-1==n-1)
            mx2=l.sf+r.pr;
        if (!f && (mx2>tmp.mx || tmp.l==l.rr-l.sf+1) || f && mx2>=tmp.mx)
        {
            tmp.mx=mx2;
            tmp.l=l.rr-l.sf+1;
            tmp.r=r.ll+r.pr-1;
        }
    }
    return tmp;
}

int find_mid(int l, int r)
{
    if (l==0)
        return l;
    if (r==n-1)
        return r;
    return (l+r)>>1;
}

void build(int ind, int tl, int tr)
{
    if (tl==tr)
    {
        ind_of[tl]=ind;
        t[ind].l=t[ind].r=t[ind].ll=t[ind].rr=tl;
        t[ind].mx=1; t[ind].pr=t[ind].sf=t[ind].sz=1;
        return;
    }
    int tm=(tl+tr)>>1;
    build(ind<<1, tl, tm);
    build((ind<<1)+1, tm+1, tr);
    t[ind].l=t[ind].ll=tl;
    t[ind].r=t[ind].rr=tr;  
    t[ind].pr=t[ind].sf=t[ind].sz=tr-tl+1;
    t[ind].mx=(t[ind].sz+1)>>1;
    if (tl==0 || tr==n-1)
        t[ind].mx=t[ind].sz;
}

void change(int ind)
{
    t[ind].mx=t[ind].pr=t[ind].sf=1-t[ind].pr;
    for(ind>>=1; ind; ind>>=1)
        t[ind]=unite(t[ind<<1], t[(ind<<1)+1]);
}

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int m, a, b, i, tmp;
    scanf("%d %d", &n, &m);
    build(1, 0, n-1);
    for(i=0; i<m; i++)
    {
        scanf("%d %d", &a, &b);
        if (a==1)
        {
            tmp=find_mid(t[1].l, t[1].r);
            printf("%d\n", tmp+1);
            wh[b]=tmp;
            change(ind_of[tmp]);
        }
        else
        {
            change(ind_of[wh[b]]);
        }
    }
}