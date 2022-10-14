#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
ll max1,k1,min1,a[1005][2],b[1005],n1,n,m,k,i,j;
vector<vector<int> > f1(1500);
vector<vector<int> > f2(1500);
void dfs1(int);
void dfs(int i)
{
int j;
if (f1[i].size()==0) return;
for (j=0;j<f1[i].size();j++)
if (b[f1[i][j]]==0)
{
b[f1[i][j]]=1;
dfs1(a[f1[i][j]][1]);
}
f1[i].clear();
}
void dfs1(int i)
{
int j;
if (f2[i].size()==0) return;
for (j=0;j<f2[i].size();j++)
if (b[f2[i][j]]==0)
{
b[f2[i][j]]=1;
dfs(a[f2[i][j]][0]);
}
f2[i].clear();
}
int main()
{
cin>>n;
for (i=0;i<1005;i++) b[i]=0;
for (i=1;i<=n;i++)
{
cin>>a[i][0]>>a[i][1];
f1[a[i][0]].push_back(i);
f2[a[i][1]].push_back(i);
}
k1=0;
for (i=1;i<=1000;i++)
if (f1[i].size())
{
dfs(i);
k1++;
}
cout<<k1-1<<endl;
return 0;
}