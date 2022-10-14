#include <iostream>
#include <cmath>
#include <map>
#include <cstring>
#include <stdio.h>
#include <algorithm>
using namespace std;
long long a1[1000000],a2[1000000];
int main()
{
long long n,n1,i,j,b[30];
cin>>n;
n1=n;
b[0]=0;b[1]=1;
for (i=2;i<30;i++)
b[i]=b[i-1]*2+1;
for (i=29;i>=0;i--)
if (b[i]<n)
{
for (j=n;j>b[i];j--)
{
a1[j]=b[i+1]-j;
a1[b[i+1]-j]=j;
}
n=b[i+1]-1-n;
}
cout<<n1*(n1+1)<<endl;
for (i=0;i<=n1;i++)
cout<<a1[i]<<" ";
return 0;
}