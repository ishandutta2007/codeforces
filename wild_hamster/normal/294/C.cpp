#include <iostream>
#include <cmath>
#include <map>
#include <cstring>
#include <stdio.h>
#include <algorithm>
#define tr 1000000007
long long dfs(long long y)
{
long long i,j;
j=1;
for (i=1;i<y;i++)
j=(j*2)%tr;
return j;
} 
long long gsd(int a, int b)
{
int t;
if (b>a) {t=a;a=b;b=t;}
if (b==0) return a; else 
return gsd(b,a%b);
}
using namespace std;
int main()
{
long long t1,t2,j1,x,s,s1,s2,s3,s4,m,n,k,k1,k2,i,j,a[1005],b[1005],c[1005],d[1005],e[1005];
cin>>n>>m;
for (i=0;i<m;i++) cin>>a[i];
sort(a,a+m);
k1=0;k=-1;k2=m;s=1;
if (a[0]>1) {k++;b[k]=a[0]-1;}
for (i=k1+1;i<k2;i++)
{k++;b[k]=a[i]-a[i-1]-1;s=(s*dfs(b[k]))%tr;}
if (a[m-1]<n) {k++;b[k]=n-a[m-1];}
for (i=0;i<=1005;i++) c[i]=0;
t1=1;
for (i=0;i<=k;i++)
{
for (j=0;j<b[i];j++) c[j]=j+1;
for (j=0;j<b[i];j++) d[j]=t1+j;
for (j=0;j<b[i];j++)
for (j1=0;j1<b[i];j1++)
{s4=gsd(c[j],d[j1]);c[j]/=s4;d[j1]/=s4;}
for (j=0;j<b[i];j++) s=(s*d[j])%tr;
t1+=b[i];
}
cout<<s; 
return 0;
}