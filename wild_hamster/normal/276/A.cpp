#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
int i,max,n,k,x1,x2;
cin>>n>>k;
max=-1500000000;
for (i=0;i<n;i++)
{
scanf("%d%d",&x1,&x2);
if (x2>k)
{if (x1-(x2-k)>max) max=x1-(x2-k);}
else
{if (x1>max) max=x1;}
}
cout<<max;
return 0;
}