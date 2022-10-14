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
ll rez,p[5],t1,t2,z,x,y1,y2,m,n,i,j,k1,k,a[3000];
vector <ll> f;
ll gcd(ll a, ll b)
{
if (b==0) return a;
else return gcd(b,a%b);
}
int main()
{
cin>>n>>p[1]>>p[2]>>p[3]>>t1>>t2;
ll max1=-5,min1=100500;
for (i=0;i<n;i++) 
{
cin>>y1>>y2;
for (j=y1;j<y2;j++) a[j]=1;
if (y2-1>max1) max1=y2-1;
if (y1<min1) min1=y1;
}
z=1;rez=0;k=0;
for (i=min1;i<=max1;i++)
{
rez+=p[z];
if (a[i]==1) {z=1;k=0;}
if (z==1&&a[i]==0) {if (k<t1) k++; else {z=2;k=0;} }
if (z==2&&a[i]==0) {if (k<t2) k++; else {z=3;k=0;}}
}
cout<<rez<<endl;
return 0;
}