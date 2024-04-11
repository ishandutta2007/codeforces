#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
typedef long long ll;
int main()
{
ll s,min1,i,m,n,k,k1,o,a[100011];
cin>>m>>n;
cout<<min(n,m)+1<<endl;
for (i=0;i<=min(n,m);i++)
cout<<i<<" "<<min(n,m)-i<<endl;
return 0;
}