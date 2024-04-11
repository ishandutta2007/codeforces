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
#define tr 1000000009
ll rez,z,x,y1,y2,m,n,i,j,k,a[100500],b[100500];
int main()
{
cin>>n;
for (i=0;i<n;i++)
{
cin>>k;
a[k]++;
}
rez=a[4];
k=min(a[3],a[1]);
rez+=k;
a[3]-=k;a[1]-=k;
rez+=a[3];
rez+=a[2]/2;
if (a[2]%2) {rez++;a[1]-=2;}
if (a[1]>0)
if (a[1]%4>0) rez+=a[1]/4+1; else rez+=a[1]/4;
cout<<rez<<endl;
return 0;
}