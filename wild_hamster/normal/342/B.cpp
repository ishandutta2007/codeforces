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
#define tr 1000000007
int k1,k2,k3,t,s,y,j1,j2,rez,z,a[1000500][2],t1,t2,x,y1,y2,m,n,i,j,k;
int main()
{
string s;
char kl;
cin>>n>>m>>k1>>k2;
for (i=0;i<1000300;i++)
{
a[i][0]=10000000;a[i][1]=100000000;
}
for (i=0;i<m;i++)
{
cin>>x>>y>>t;
if (x<1000500) {a[x][0]=y;a[x][1]=t;}
}
if (k1<k2) {kl='R';z=1;} else {kl='L';z=-1;}
i=1;
while (k1!=k2)
{
if ((k1<a[i][0]||k1>a[i][1])&&(k1+z<a[i][0]||k1+z>a[i][1]))
{s.push_back(kl);k1+=z;} else s.push_back('X');
i++;
}
cout<<s<<endl;
return 0;
}