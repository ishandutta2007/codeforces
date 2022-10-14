#include <iostream>
#include <map>
#include <stdio.h>
#include <vector>
#include <cmath>
using namespace std;
int t[400000];
void build(int a[],int v,int tl,int tr)
{
int tm;
if (tl==tr) {t[v]=a[tl];return;} else
{
tm=(tl+tr)/2;
build(a,v*2,tl,tm);
build(a,v*2+1,tm+1,tr);
}
}
void push (int v) {
if (t[v] != -1) {
t[v*2] = t[v*2+1] = t[v];
t[v] = -1;
}
}
void update (int v, int tl, int tr, int l, int r, int color) {
if (l > r) return;
if (l == tl && tr == r)
t[v] = color;
else {
push (v);
int tm = (tl + tr) / 2;
update (v*2, tl, tm, l, min(r,tm), color);
update (v*2+1, tm+1, tr, max(l,tm+1), r, color);
}
}
int get (int v, int tl, int tr, int pos) {
if (tl == tr)
return t[v];
push (v);
int tm = (tl + tr) / 2;
if (pos <= tm)
return get (v*2, tl, tm, pos);
else
return get (v*2+1, tm+1, tr, pos);
}
int k1,k2,k3,k4,k,n,m,i,j,a[100000],b[100000],c[100000],d[100000][3];
int main()
{
cin>>n>>m;
for (i=0;i<n;i++) cin>>a[i];
for (i=0;i<n;i++) cin>>b[i];
for (i=0;i<4*n;i++) t[i]=-1;
j=0;
for (i=0;i<m;i++)
{
cin>>k1;
if (k1==2)
{
cin>>k2;
k=get(1,0,n-1,k2-1);
if (k==-1) cout<<b[k2-1]<<endl;
else cout<<a[k2-d[k][1]+d[k][0]-1]<<endl;
} else
{
cin>>d[j][0]>>d[j][1]>>k4;
update(1,0,n-1,d[j][1]-1,d[j][1]+k4-2,j);
j++;
}
}
//system("pause");
return 0;
}