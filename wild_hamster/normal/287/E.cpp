#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
int t,i,j,n,k,z,a[2000000],b[2000000],p1[2000000],p[2000000],q[2000000],y[2000000];
cin>>n;
for (i=1;i<=n;i++)
scanf("%d",&p1[i]);
cin>>t;
for (i=0;i<t;i++)
{
scanf("%d",&q[i]);
q[i]=n-q[i]+1;
b[q[i]]=1;
}
k=0;
for (i=1;i<=n;i++)
p[i]=p1[n-i+1];
for (i=1;i<=n;i++)
if (k==0||a[k]!=p[i]||(a[k]==p[i]&&b[i]==1))
{k++;a[k]=p[i];y[i]=p[i];} else
{k--;y[i]=-p[i];}
if (k>0) cout<<"NO"; else
{
cout<<"YES"<<endl;
for (i=1;i<=n;i++) cout<<-y[n-i+1]<<" ";
}
return 0;
}