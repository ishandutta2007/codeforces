#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
int j,k,l,s,i,m,x,n;
int b[100000],a[100000];
scanf("%d%d",&n,&m);
for (i=0;i<n;i++)
scanf("%d",&a[i]);
x=0;
while (a[x]==a[x+1])
x++;
if (a[x]>a[x+1]) 
for (i=0;i<=x;i++)
b[i]=0;
else
for (i=0;i<=x;i++)
b[i]=1;
x=b[x]%2;
for (i=1;i<n;i++)
{
if (x==0)
{if (a[i]>=a[i-1]) b[i]=b[i-1]; 
else {x=1;b[i]=b[i-1];}}
else 
{if (a[i]<=a[i-1]) b[i]=b[i-1];
else {x=0;b[i]=b[i-1]+1;
if (i!=1)
{
j=i;b[i-1]=b[i];
while (a[j-1]==a[j-2])
{
b[j-2]=b[j-1];
j--;
}
b[i]=b[i-1]+1;
}} }
}
for (i=0;i<m;i++)
{
scanf("%d%d",&k,&l);
k--;l--;
if (b[k]%2==0) {if (b[l]-b[k]<2) printf("%s \n","Yes"); else printf("%s \n","No");}
else {if ((b[l]-b[k]<2)||(b[l]-b[k]==2&&b[l-1]+1==b[l])||(b[l]-b[k]==2&&b[k]+1==b[k+1])) printf("%s \n","Yes"); else printf("%s \n","No");}
}
return 0;
}