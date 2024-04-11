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
ll z,x,y1,y2,m,n,i,j,k,a[100500],b[100500];
vector <ll> f;
vector <ll> g;
void dfs(ll x, ll k1, ll k2, ll y)
{
ll i;
if (z==1) return;
if (y==m) {z=1;cout<<"YES"<<endl;for (i=0;i<g.size();i++) cout<<g[i]<<" ";return;}
for (i=0;i<f.size();i++)
if (f[i]!=x&&f[i]+k1>k2)
{
g.push_back(f[i]);
dfs(f[i],k2,f[i]+k1,y+1);
g.pop_back();
}
}
int main()
{
string s;
cin>>s;
cin>>m;
z=0;
y1=0;y2=0;
for (i=0;i<10;i++)
if (s[i]=='1') f.push_back(i+1);
dfs(-5,0,0,0);
if (z!=1) cout<<"NO"<<endl;
return 0;
}