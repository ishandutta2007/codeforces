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
ll s,y,j1,j2,rez,p[15],t1,t2,z,x,y1,y2,m,n,i,j,k1,k,a[10000];
ll Abs(ll a)
{
if (a<0) return -a; else return a;
}
vector <ll> f;
int main()
{
cin>>n;
ll max1=100500;
for (i=0;i<n;i++) cin>>a[i];
for (i=0;i<n;i++) if (Abs(a[i]-a[(i+1)%n])<max1) 
{max1=Abs(a[i]-a[(i+1)%n]);y1=i;y2=(i+1)%n;}
cout<<y1+1<<" "<<y2+1<<endl;
return 0;
}