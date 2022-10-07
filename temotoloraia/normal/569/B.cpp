#include <bits/stdc++.h>
using namespace std;
int n,a[100001],b[100001],m[100001],k,i;
int main ()
{
cin>>n;
for (i=0;i<n;i++)
{
cin>>a[i];
b[a[i]]=1;
}
for (i=1;i<=n;i++)
if (b[i]==0)
{
m[k]=i;
k++;
}
k=0;
for (i=0;i<n;i++)
{
if (b[a[i]]==2 || a[i]>n)
{
a[i]=m[k];
k++;
}
b[a[i]]=2;
}
for (i=0;i<n;i++)
cout<<a[i]<<" ";
}