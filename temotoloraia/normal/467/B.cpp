#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
long long n,m,k,i,a[1005],ans;
bool check()
{
long long p=a[m+1]^a[i],q=0;
while (p)
{
q+=p%2;
p/=2;
}
if (q<=k)
return true;
return false;
}
int main()
{
cin>>n>>m>>k;
for (i=1;i<=m+1;i++)
cin>>a[i];
for (i=1;i<=m;i++)
if (check())
ans++;
cout<<ans<<endl;
return 0;
}