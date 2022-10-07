#include <iostream>
#include <algorithm>
using namespace std;
int n,a[5000],b[5000],i,j,k,p;
pair<int,int>P[5000];
#define f first
#define s second
main()
{
cin>>n;
for (i=1;i<=n;i++)
{
cin>>a[i];
b[i]=a[i];
}
sort(b+1,b+n+1);
for (i=1;i<=n;i++)
for (j=1;j<=n;j++)
if (i!=j)
if (a[i]==b[j] && a[j]==b[i] && a[i]!=b[i] && a[j]!=b[j])
{
k++;
P[k].f=i;
P[k].s=j;
swap(a[i],a[j]);
}
for (i=1;i<=n;i++)
for (j=1;j<=n;j++)
if (i!=j)
{
p=0;
if (a[i]==b[j])
p++;
if (a[j]==b[i])
p++;
if (a[i]==b[i])
p--;
if (a[j]==b[j])
p--;
if (p>0)
{
k++;
P[k].f=i;
P[k].s=j;
swap(a[i],a[j]);
}
}
cout<<k<<endl;
for (i=1;i<=k;i++)
cout<<P[i].f-1<<" "<<P[i].s-1<<endl;
}