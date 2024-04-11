#include <iostream>
using namespace std;
int main()
{
long long k,s,i,m,x,n;
long long a[100000];
cin>>n>>x;
for (i=0;i<n;i++)
cin>>a[i];
k=0;i=0;s=0;
while (i<n)
if (s+a[i]<=x)
{
s+=a[i];
k++;
i++;
}
else
{
s+=a[i]-a[i-k];
i++;
}
cout<<k;
return 0;
}