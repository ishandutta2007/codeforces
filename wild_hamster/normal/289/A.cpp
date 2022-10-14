#include <iostream>
#include <cmath>
#include <map>
#include <cstring>
#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
int s,n,i,j,x,k,k1,k2,a[100000];
cin>>n>>k;
s=0;
for (i=0;i<n;i++)
{
cin>>k1>>k2;
s+=k2-k1+1;
}
s=(k-(s%k))%k;
cout<<s;
return 0;
}