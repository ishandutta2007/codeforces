#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
#include <stdio.h>
using namespace std;
typedef long long ll;
typedef double db;
//map <ll,ll> a,b,c;
ll x,a[15][2000],b[12][500][500],n1,i1,c[2000500],d,t,m,i,j,k,rez,n,k1[15],k2[15],k3,k4,k5;
bool z;
string s4,s1,s2[15],s[300];
char s3;
map <char,ll> f;
map <string, ll> g;
int main()
{
cin>>s1;
cin>>n;
for (i=0;i<n;i++)
cin>>s2[i]>>k1[i]>>k2[i];
rez=0;
for (i=0;i<s1.size();i++)
{
    for (j=0;j<n;j++)
    for (k4=i;k4<s1.size();k4++)
    for (k=0;k<s2[j].size();k++)
    b[j][k4][k]=0;
    s4.clear();
for (k4=i;k4<s1.size();k4++)
{
    s3=s1[k4];
    s4.push_back(s3);
    z=true;
for (j=0;j<n;j++)
for (k=0;k<s2[j].size();k++)
b[j][i][k]=1;
for (j=0;j<n;j++)
{
    t=0;
for (k=0;k<s2[j].size();k++)
if (s3==s2[j][k]&&b[j][k4][k]==1) {b[j][k4+1][k+1]=1;t++;}
if (t<k1[j]||t>k2[j]) z=false;
}
if (z&&!g[s4]) {rez++;g[s4]=1;}
}
}
cout<<rez<<endl;
return 0;
}