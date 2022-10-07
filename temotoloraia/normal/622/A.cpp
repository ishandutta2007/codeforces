#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
long long n,m,k,p,i,j,a1,a2;
main()
{
cin>>n;
for (i=1;i<=n;i++)
if (i*(i+1)/2>n)
break;
i--;
n-=i*(i+1)/2;
if (n>0)
cout<<n<<endl;
else
cout<<i<<endl;
}