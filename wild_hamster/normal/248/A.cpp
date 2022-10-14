#include <iostream>
#include <map>
#include <algorithm>
#include <cstring>
#include <string.h>
#include <time.h>
#include <stdio.h>
using namespace std;
typedef long long ll;
ll s,m,k1,k2,k3,k4,j,n,i,i1,i2,i3,max1,a[200200];
int main()
{
cin>>n;
while (n--)
{
cin>>i1>>i2;
if (i1==0) k1++; else k2++;
if (i2==0) k3++; else k4++;
}
max1=min(k1,k2)+min(k3,k4);
cout<<max1<<endl;
return 0;
}