#include <iostream>
#include <vector>
#include <stdio.h>
#include <map>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
typedef long long ll;
typedef double db;
ll a[300001],b[300000],c[300000],n,m,k,i,j,x1,x2,k1,k2,k3,k4;
int main()
{
cin>>n;
n*=n;
for (i=1;i<=n/2;i++)
cout<<i<<" "<<n-i+1<<endl;
return 0;
}