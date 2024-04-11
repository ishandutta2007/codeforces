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
ll k,k1,i,k2,a[150][150],n,m,b[200],c[200],azaza,z1,z2,yw,xb,yb,r,z;
vector <ll> f[200];
void dfs(int x)
{
if (b[x]==1) return;
b[x]=1;
if (c[x]<2) k-=100000; else k+=1;
for (int i=0;i<f[x].size();i++)
dfs(f[x][i]);
}
int main()
{
cin>>n>>m;
for (i=0;i<200;i++) c[i]=0;
while (m--)
{
cin>>k1>>k2;
//if (a[k1][k2]==1) continue;
//a[k1][k2]=1;a[k2][k1]=1;
f[k1].push_back(k2);
f[k2].push_back(k1);
c[k1]++;c[k2]++;
}
k1=0;
for (i=0;i<200;i++) b[i]=0;
for (i=1;i<=n;i++)
{
k=0;
dfs(i);
k1+=(max(k,(ll)0))%2;
}
if ((n-k1)%2==1) k1++;
cout<<k1<<endl;
return 0;
}