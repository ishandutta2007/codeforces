#include <iostream>
using namespace std;
int k,i,j,m,n;
int a[101][101];
int d[150][150];
int e[150],f[150];
void dfs(int x)
{
int i1,j1;
if (f[x]==0)
{
for (i1=1;i1<a[x][0]+1;i1++)
{
e[a[x][i1]]=1;
f[x]=1;
for (j1=1;j1<=d[a[x][i1]][0];j1++)
dfs(d[a[x][i1]][j1]);
}
}
}
int main(){
int z,k1,xp;
z=0;
xp=0;
for (i=0;i<120;i++)
for (j=0;j<120;j++)
d[i][j]=0;
for (i=0;i<120;i++)
{e[i]=0;f[i]=0;}
cin>>n>>m;
for (i=1;i<=n;i++)
{
cin>>k;
if (k==0) xp++; else z=1;
a[i][0]=k;
for (j=1;j<=k;j++)
cin>>a[i][j];
}
if (z==0) 
{
cout<<n;
return 0;
}
for (i=1;i<=n;i++)
for (j=1;j<a[i][0]+1;j++)
{
d[a[i][j]][d[a[i][j]][0]+1]=i;
d[a[i][j]][0]++;
}
for (i=1;i<=m;i++)
{
if ((e[i]==0)&&(d[i][0]!=0))
{
for (j=1;j<=d[i][0];j++)
dfs(d[i][j]);
xp=xp+1;
e[i]=1;
}
}
cout<<xp-1;
return 0;
}