#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
typedef long long ll;
int main()
{
ll s,min1,i,m,n,k,k1,o,a[100011];
cin>>n;
s=n;
for (i=1;i<=n-1;i++)
s+=i*(n-i);
cout<<s<<endl;
return 0;
}