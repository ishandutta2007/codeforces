#include <iostream>
#include <cmath>
#include <algorithm>
#include <stdio.h>
#include <map>
#include <cstring>
#include <string.h>
using namespace std;
int main() {
int m,n,k,t,t1,i,a[100010],b[100010];
cin>>m>>n>>k;
for (i=0;i<m;i++) cin>>a[i];
for (i=0;i<n;i++) cin>>b[i];
sort(a,a+m);
sort(b,b+n);
t=0;t1=0;
for (i=0;i<m;i++)
{
while (a[i]>b[t]) t++;
if (a[i]==b[t]) {a[i]=-1;b[t]=-1;t1++;t++;}
}
sort(a,a+m);
sort(b,b+n);
if (m-t1<1) {cout<<"NO"; return 0;}
for (i=m-1;i>=t1;i--)
{
if (m-t1<1) {cout<<"NO"; return 0;}
if (n-t1<1) {cout<<"YES"; return 0;}
if (a[i]>b[i+n-m]) {cout<<"YES"; return 0;}
}
cout<<"NO";
return 0;
}