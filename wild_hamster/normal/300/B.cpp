#include <iostream>
#include <cmath>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
long long a[10000],b[10000][3],m,k11,k12,k13,n,i,j,k,k1,k2,k3;
vector <vector <long long> > f(10000),f2(10000);
vector <vector <long long> > f1(10000);
void dfs(int x)
{
int i;
if (a[x]!=1)
{
a[x]=1;
f1[k3].push_back(x);
for (i=0;i<f[x].size();i++)
dfs(f[x][i]);
}
}
int main()
{
cin>>n>>m;
for (i=0;i<m;i++)
{
cin>>k1>>k2;
f[k1].push_back(k2);f[k2].push_back(k1);
}
for (i=1;i<=n;i++) a[i]=0;
k3=0;k11=0;k12=0;k13=0;
for (i=1;i<=n;i++)
if (a[i]!=1)
{
dfs(i);
//for (j=0;j<f1[k3].size();j++) cout<<f1[k3][j]<<" ";
if (f1[k3].size()==1) k11++;
else if (f1[k3].size()==2) k12++;
else if (f1[k3].size()==3) k13++;
else {cout<<-1;return 0;}
k3++;
}
k=0;
k1=k12;k2=k12;
for (i=0;i<k3;i++)
if (f1[i].size()==3)
{
for (j=0;j<f1[i].size();j++)
f2[k].push_back(f1[i][j]);
k++;
}
for (i=0;i<k3;i++)
if (f1[i].size()==2)
{
for (j=0;j<f1[i].size();j++)
f2[k].push_back(f1[i][j]);
k++;
}
if (k>n/3) {cout<<-1;return 0;}
k=0;
for (i=0;i<k3;i++)
if (f1[i].size()==1)
{
while (f2[k].size()==3) k++;
f2[k].push_back(f1[i][0]);
}
for (i=0;i<n/3;i++)
{
for (j=0;j<3;j++)
cout<<f2[i][j]<<" ";
cout<<endl;
}
//system("pause");
return 0;
}