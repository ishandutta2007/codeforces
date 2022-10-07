#include <iostream>
#include <set>
using namespace std;
long long n,m,i,j,p,k,a[200],b[200];
main()
{
cin>>n>>m;
cout<<n+m-1<<endl;
for (i=1;i<=n;i++)
for (j=1;j<=m;j++)
{
a[i]++;
b[j]++;
if (a[i]>1 && b[j]>1)
continue;
cout<<i<<" "<<j<<endl;
}
}