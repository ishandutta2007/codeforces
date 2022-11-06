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
using namespace std; 

struct point {double x, v; int ind;};

bool cmp(point pt1, point pt2)
{
    if (pt1.x<pt2.x) return true;
    else if (pt1.x>pt2.x) return false;
    else return pt1.v<pt2.v;
}

point pt[2][500005];
double dx[2][500005], eps=1e-15;
int inds[2][500005];
int top[2], st[2], en[2];

int main()
{   
   /* freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);*/
    double p, q, t, x1, v1, cur, last, tmp;
    int i, i1, i0, j, n, mx, f;
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        scanf("%lf %lf", &x1, &v1);
        if (v1<0.) {pt[1][top[1]].v=v1; pt[1][top[1]++].x=x1;}
        else {pt[0][top[0]].v=v1; pt[0][top[0]++].x=x1;}
    }
    if (!top[0] || !top[1]) {printf("-1"); return 0;}
    sort(pt[0], pt[0]+top[0], cmp);
    sort(pt[1], pt[1]+top[1], cmp);
    if (pt[1][top[1]-1].x+eps<pt[0][0].x) {printf("-1"); return 0;} 
    for(i=1, i1=i0=0; i0<top[0] && i1<top[1]; )
    {
        if (pt[0][i0].x+eps<pt[1][i1].x) {pt[0][i0++].ind=i++;}
        else if (pt[0][i0].x-eps>pt[1][i1].x) {pt[1][i1++].ind=i++;}
        else {printf("0.000000000000"); return 0;}
    }
    for(; i0<top[0]; ) pt[0][i0++].ind=i++;
    for(; i1<top[1]; ) pt[1][i1++].ind=i++;
    for(p=0., q=(1e+9)+1; p+eps<q; )
    {
        if ((q-p)/q<eps) break;
        t=(p+q)/2.;
        st[0]=0; en[0]=1; 
        inds[0][0]=pt[0][0].ind;
        last=dx[0][0]=pt[0][0].x+pt[0][0].v*t;
        for(i0=1; i0<top[0]; i0++)
        {
            cur=pt[0][i0].x+pt[0][i0].v*t;
            if (cur>last+eps) 
            {
                inds[0][en[0]]=pt[0][i0].ind;
                last=cur; dx[0][en[0]++]=cur;
            }
        }
        st[1]=top[1]-1; en[1]=top[1];
        inds[1][st[1]]=pt[1][st[1]].ind;
        last=dx[1][st[1]]=pt[1][st[1]].x+pt[1][st[1]].v*t;
        for(i1=st[1]-1; i1>=0; i1--)
        {
            tmp=pt[1][i1].v*t;
            cur=pt[1][i1].x+tmp;
            if (cur<last-eps) 
            {
                inds[1][--st[1]]=pt[1][i1].ind;
                last=cur; dx[1][st[1]]=cur;
            }
        }
        mx=0; f=0;
        for(i0=st[0], i1=st[1]; i0<en[0] && i1<en[1]; )
        {
            if (dx[0][i0]>dx[1][i1]) 
            {
                mx=inds[1][i1];
                i1++;
            }
            else
            {
                if (mx>inds[0][i0]) {f=1; break;}
                i0++;
            }
        }
        for(; i0<en[0]; i0++)
        {
            if (mx>inds[0][i0]) {f=1; break;}
            i0++;
        }
        if (f) q=t;
        else p=t;
    }
    printf("%.15lf", t);
}