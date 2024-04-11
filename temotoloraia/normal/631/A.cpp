#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
int n,m,k,p,i,j,a1,a2;
main()
{
cin>>n;
for (i=1;i<=n;i++)
{
cin>>k;
a1|=k;
}
for (i=1;i<=n;i++)
{
cin>>k;
a2|=k;
}
cout<<a1+a2<<endl;
}