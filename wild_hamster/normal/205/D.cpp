#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;
typedef double db;
ll d[100500],d1[100500],rez,s,n,k,k1,k2,i,j;
map <ll,ll> a,b,c;
int main() 
{
cin>>n;
for (i=0;i<n;i++)
{
cin>>k1>>k2;
d[i]=k1;d1[i]=k2;
if (k1==k2) c[k1]++; else
{a[k1]++;b[k2]++;}
}
ll min1=100500;
for (i=0;i<n;i++)
{
k=(n+1)/2-a[d[i]]-c[d[i]];
//cout<<k<<endl;
if (b[d[i]]>=k) if (min1>k) min1=k;
}
for (i=0;i<n;i++)
{
k=(n+1)/2-a[d1[i]]-c[d1[i]];
//cout<<k<<endl;
if (b[d1[i]]>=k) if (min1>k) min1=k;
}
if (min1==100500) cout<<-1<<endl; else cout<<max((ll)0,min1)<<endl;
return 0;
}