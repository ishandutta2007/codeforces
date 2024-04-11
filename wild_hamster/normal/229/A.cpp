#include <iostream>
#include <map>
#include <algorithm>
#include <cstring>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <vector>
#include <cmath>
//#define tr 1000000007
using namespace std;
typedef long long ll;
typedef double db;
ll max1,rez,k,m,k1,k2,k3,k4,k5,k6,i,n,j;
ll a[101][10001],b[101][10001],c[101];
vector <ll> f;
//map <ll,ll> f1[2];
ll gcd(ll a, ll b)
{
if (a<b) swap(a,b);
if (b==0) return a; else
return gcd(b,a%b);
}
int main()
{
char c1;
cin>>m>>n;
for (i=0;i<m;i++) b[i][0]=1;
for (i=0;i<m;i++)
for (j=0;j<n;j++)
{
cin>>c1;
if (c1=='1') b[i][b[i][0]++]=j;
}
max1=10000000;
for (i=0;i<m;i++) if (b[i][0]==1) {cout<<-1;return 0;}
for (i=0;i<=m;i++) c[i]=0;
for (j=0;j<n;j++)
{
k=0;
for (i=0;i<m;i++)
if (b[i][c[i]+1]==j) c[i]++;
else
{
if (c[i]==0) k+=min(j+n-b[i][b[i][0]-1],b[i][1]-j); else
if (c[i]==b[i][0]-1) k+=min(j-b[i][b[i][0]-1],n-j+b[i][1]); else
k+=min(j-b[i][c[i]],b[i][c[i]+1]-j);
} 
//for (i=0;i<m;i++) cout<<c[i]<<" ";
if (k<max1) max1=k;
//cout<<k<<endl;
}
cout<<max1<<endl;
return 0;
}