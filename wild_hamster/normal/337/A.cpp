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
ll max1,a[5000],b[50],c[50],rez,x1,ost,x,n,k,m,t,r,j,y,i;
map <ll,ll> prime;
vector <ll> f[50];
int main()
{
cin>>m>>n;
for (i=0;i<n;i++) cin>>a[i];
sort(a,a+n);
ll max1=100000500;
for (i=0;i<n-m+1;i++)
if (a[i+m-1]-a[i]<max1) max1=a[i+m-1]-a[i];
cout<<max1<<endl;
return 0;
}