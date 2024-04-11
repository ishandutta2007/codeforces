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
vector <ll> f;
int main()
{
cin>>n>>m;
for (i=0;i<m;i++)
{
cin>>x>>y;
a[x]=1;a[y]=1;
}
for (i=1;i<=n;i++) if (a[i]==0) x=i;
cout<<n-1<<endl;
for (i=1;i<=n;i++)
if (i!=x) cout<<x<<" "<<i<<endl;
return 0;
}