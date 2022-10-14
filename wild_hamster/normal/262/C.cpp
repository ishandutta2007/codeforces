#include <iostream>
#include <map>
#include <time.h>
#include <algorithm>
using namespace std;
typedef long long ll;
#define tr 1000000007
ll a[100500],b[100500];
ll Abs(ll x)
{
if (x<0) return -x; else return x;
}
int main()
{
ll min1,m,n,k2,s,k1,rez,i,j,k;
cin>>m;
min1=(ll)1e+12;
for (i=0;i<m;i++) {cin>>a[i];if (a[i]<min1) min1=a[i];}
cin>>n;
k=min1+2;
s=k*100500;
for (i=0;i<n;i++) cin>>b[i];
sort(b,b+n);
rez=0;
for (i=n-1;i>=0;i--)
{
if (s%k==1||s%k==2) rez=rez; else rez+=b[i];
s--;
}
cout<<rez<<endl;
return 0;
}