#include <iostream>
#include <cstring>
#include <string.h>
#include <algorithm>
#include <map>
#include <stdio.h>
#include <cmath>
typedef long long ll;
using namespace std;
ll k,d,n,s,a[101000],b[100100],k1,k2,k3,k4,m,j,i;
int main()
{

cin>>n;
k=0;
for (i=0;i<2*n-1;i++)
{cin>>a[i];if (a[i]<0) k++;a[i]=abs(a[i]);}
if (n%2==1||k%2==0) k1=0; else k1=1;
sort(a,a+2*n-1);
s=0;
for (i=0;i<2*n-1;i++)
if (i<k1) s-=a[i]; else s+=a[i];
cout<<s<<endl;
return 0;
}