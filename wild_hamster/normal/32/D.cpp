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
ll t,s,y,j1,j2,rez,p[15],t1,t2,z,x,y1,y2,m,n,i,j,k1,k;
vector <int> f[200][2];
vector <int> g[3];
char a[400][400];
int main()
{
cin>>n>>m>>k;
for (i=0;i<n;i++)
for (j=0;j<m;j++)
cin>>a[i][j];
for (i=0;i<n;i++)
for (j=0;j<m;j++)
if (a[i][j]=='*')
for (t=1;t<160;t++)
if (i-t>=0&&i+t<n&&j-t>=0&&j+t<m)
if (a[i-t][j]=='*'&&a[i+t][j]=='*'&&a[i][j-t]=='*'&&a[i][j+t]=='*')
{f[t][0].push_back(i);f[t][1].push_back(j);}
for (i=1;i<200;i++)
{
for (j=0;j<f[i][0].size();j++)
{g[0].push_back(f[i][0][j]);g[1].push_back(f[i][1][j]);g[2].push_back(i);}
f[i][0].clear();f[i][1].clear();
}
if (k>g[0].size()) cout<<-1<<endl;
else 
{
x=g[0][k-1]+1;y=g[1][k-1]+1;y1=g[2][k-1];
cout<<x<<" "<<y<<endl;
cout<<x-y1<<" "<<y<<endl;
cout<<x+y1<<" "<<y<<endl;
cout<<x<<" "<<y-y1<<endl;
cout<<x<<" "<<y+y1<<endl;
}
return 0;
}