#include <iostream>
#include <map>
#include <algorithm>
#include <cstring>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <vector>
#define tr 1000000007
using namespace std;
typedef long long ll;
typedef double db;
ll i1,k,j1,a[100005],b[105][105],c[105][105],m,d,k1,k2,k3,i,n,j;
int main()
{
char c1;
cin>>n>>k;
for (i=0;i<n;i++) cin>>a[i];
sort(a,a+n);
k2=0;
for (i=0;i<n;i++)
if (a[i]!=0)
{
k1=upper_bound(a,a+n,a[i]*k)-a-1;
//cout<<k1<<endl;
if (k1!=i&&a[k1]==a[i]*k) {k2++;a[k1]=0;}
}
cout<<n-k2;
return 0;
}