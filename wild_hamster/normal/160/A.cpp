#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int main()
{
ll n,k,s,i,k1,a[1050];
cin>>n;s=0;

for (i=0;i<n;i++) {cin>>a[i];s+=a[i];}
sort(a,a+n);
s/=2;k=0;k1=0;
for (i=n-1;i>=0;i--)
if (k>s) {break;} else
{k1++;k+=a[i];}
cout<<k1<<endl;
return 0;
}