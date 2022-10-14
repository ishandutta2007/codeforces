#include <iostream>
#include <map>
#include <stdio.h>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
    long long i,j,n,m,k,a[100000],b[100000][3],d[100000],e[100000],f[100000];
long long t[400000];
long long max2(long long a, long long b)
{if (a>b) return a; else return b;}
long long min2(long long a, long long b)
{if (a>b) return b; else return a;}
void build1 (long long v, long long tl, long long tr) {
    if (tl == tr)
        t[v] = a[tl];
    else {
        int tm = (tl + tr) / 2;
        build1 (v*2, tl, tm);
        build1 (v*2+1, tm+1, tr);
    }
}
void build2(long long v, long long tl, long long tr) {
    if (tl == tr)
        t[v] = d[tl];
    else {
        int tm = (tl + tr) / 2;
        build2 (v*2, tl, tm);
        build2 (v*2+1, tm+1, tr);
    }
}
 void update (long long v, long long tl, long long tr, long long l, long long r, long long add) {
    if (l > r)
        return;
    if (l == tl && tr == r)
        t[v] += add;
    else {
        int tm = (tl + tr) / 2;
        update (v*2, tl, tm, l, min2(r,tm), add);
        update (v*2+1, tm+1, tr, max2(l,tm+1), r, add);
    }
}
 
long long get (long long v, long long tl, long long tr, long long pos) {
    if (tl == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return t[v] + get (v*2, tl, tm, pos);
    else
        return t[v] + get (v*2+1, tm+1, tr, pos);
    }
int main()
{
    long long k1,k2;
cin>>n>>m>>k;
for (i=0;i<n;i++) cin>>a[i];
for (i=0;i<m;i++) cin>>b[i][0]>>b[i][1]>>b[i][2];
for (i=0;i<n;i++) {d[i]=0;e[i]=0;}
for (i=0;i<4*n;i++) t[i]=0;
 build2(1,0,n-1); 
for (i=0;i<k;i++) {cin>>k1>>k2;update(1,0,m-1,k1-1,k2-1,1);}
for (i=0;i<m;i++) e[i]=get(1,0,m-1,i);
for (i=0;i<4*n;i++) t[i]=0;
 build1(1,0,n-1);
for (i=0;i<m;i++) update(1,0,n-1,b[i][0]-1,b[i][1]-1,b[i][2]*e[i]);
for (i=0;i<n;i++) f[i]=get(1,0,n-1,i);
for (i=0;i<n;i++) cout<<f[i]<<" ";
return 0;
}