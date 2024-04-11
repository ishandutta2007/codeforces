#include <iostream>
#include <map>
#include <time.h>
#include <algorithm>
using namespace std;
typedef long long ll;
#define tr 1000000007
ll a[100500];
ll Abs(ll x)
{
if (x<0) return -x; else return x;
}
int main()
{
ll n,k2,s,k1,i,j,k;
cin>>n>>k;
k1=0;s=0;
for (i=0;i<n;i++) {cin>>a[i]; if (a[i]<0&&k) {k--;a[i]=Abs(a[i]);}}
sort(a,a+n);
if (k%2) s=-2*a[0]; else s=0;
for (i=0;i<n;i++) s+=a[i];
cout<<s<<endl;
return 0;
}