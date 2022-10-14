#include <iostream>
#include <map>
#include <cstring>
#include <string>
#include <stdio.h>
#include <cmath>
using namespace std;
char c[100005][20];
int main()
{
long long z,s1,s2,s,k,k1,k2,k3,n,i,j,a[100000],b[50],d[50];
map <long long, long long> f[32];

cin>>n>>k;
for (i=0;i<n;i++)
{
scanf("%s",c[i]);
c[i][strlen(c[i])]='.';
s1=0;s2=0;
k3=0;
for (j=0;j<strlen(c[i]);j++)
{
if (c[i][j]!='.') s1=s1*10+(int)c[i][j]-48; else
{s2=256*s2+s1;s1=0;}
}
a[i]=s2;
}
for (i=0;i<32;i++) b[i]=0;
for (i=31;i>=0;i--)
{
// cout<<endl;
for (j=0;j<n;j++)
{
  //  cout<<a[j]<<" ";
if (f[i][a[j]]==0) {f[i][a[j]]++;b[i]++;}
a[j]/=2;
}
}
z=0;
for (i=0;i<32;i++) if (b[i]==k) {z=1;k1=i;break;}
if (z==0) {cout<<-1<<endl;return 0;}
d[1]=1;
for (i=2;i<35;i++)
d[i]=d[i-1]*2;
s=0;
for (i=32-k1;i<=32;i++)
s+=d[i];
cout<<s/16777216<<"."<<(s/65536)%256<<"."<<(s/256)%256<<"."<<s%256;
return 0;
}