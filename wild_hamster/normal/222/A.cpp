#include <iostream>
#include <map>
#include <algorithm>
#include <cstring>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <vector>
using namespace std;
typedef long long ll;
typedef double db;
ll k,k1,i,k2,j,a[100100],n,m,azaza,z1,z2,yw,xb,yb,r,z;
int main()
{
cin>>n>>k;
for (i=0;i<n;i++) cin>>a[i];
z=0;
for (i=k;i<n;i++)
if (a[i]!=a[i-1]) {z=1;break;}
azaza=1;
for (i=n-1;i>0;i--)
if (a[i]==a[i-1]) azaza++; else break;
if (z==1) {cout<<-1;} else cout<<n-azaza;
return 0;
}