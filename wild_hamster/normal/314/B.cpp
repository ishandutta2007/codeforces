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
vector <ll> f;
ll a[2000500],n1,i1,c[2000500],b[2000500],d,s,t,m,i,j,k,rez,n,k1,k2,k3,k4,k5;
string s1,s2,s3;
int main()
{
cin>>k1>>k2;
cin>>s1;
cin>>s2;
k3=s1.size();
for (i=0;i<=210;i++)
for (j=0;j<k3;j++)
s3.push_back(s1[j]);
k=0;k4=0;k5=s2.size();
for (i=0;i<s3.size();i++)
{
if (s2[k4]==s3[i]&&k4!=k5-1) k4++;
else if (s2[k4]==s3[i]&&k4==k5-1) {k4=0;k++;}
if ((i+1)%k3==0) b[(i+1)/k3]=k;
}
//for (i=1;i<=211;i++) cout<<b[i]<<" ";
rez=100500;
for (i=1;i<=105;i++)
{
bool z=true;
d=b[i+1]-b[1];
if (d==0) z=false;
for (j=1;j<=104;j++)
if (b[j+i]-b[j]!=d) z=false;
if (z) {rez=i;break;}
}
b[0]=0;
if (k1%rez==0) k5=rez; else k5=k1%rez;
k=(d*((k1-1)/rez)+b[k5])/k2;
cout<<k<<endl;
return 0;
}