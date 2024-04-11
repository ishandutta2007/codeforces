#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <time.h>
using namespace std;
typedef long long ll;
typedef double db;
ll z,y1,y2,m,n,x,i,j,k,a[150500],b[150500];
ll t[1000000];
void build(int v, int tl, int tr, int x) {
if (tl==tr) t[v]=a[tl];
else {
int tm=(tl+tr)/2;
build(v*2,tl,tm,x+1);
build(v*2+1,tm+1,tr,x+1);
if ((x+k)%2==1) t[v]=(t[v*2]|t[v*2+1]); else t[v]=(t[v*2]^t[v*2+1]);
}
}
void update (int v, int tl, int tr, int x, int pos, int new_val) {
if (tl==tr) t[v]=new_val;
else {
int tm=(tl+tr)/2;
if (pos<=tm) update (v*2,tl,tm,x+1,pos,new_val);
else update (v*2+1,tm+1,tr,x+1,pos,new_val);
if ((x+k)%2==1) t[v]=(t[v*2]|t[v*2+1]); else t[v]=(t[v*2]^t[v*2+1]);
}
}
int main()
{
string s;
cin>>k>>m;
n=(1<<k);
for (i=0;i<n;i++) cin>>a[i];
build(1,0,n-1,0);
for (i=0;i<m;i++)
{
cin>>y1>>y2;
update(1,0,n-1,0,y1-1,y2);
cout<<t[1]<<endl;
}
return 0;
}