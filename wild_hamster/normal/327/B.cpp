#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
#include <stdio.h>
#define tr 1000000007
#define eps 1e+12
using namespace std;
typedef long long ll;
typedef double db;
//map <ll,ll> a,b,c;
ll n,a[40],rez,i,j,i1,i2,i3,i4,i5,i6;
ll gcd(ll x, ll y)
{
if (y==0) return x;
else return gcd(y,x%y);
}
int main()
{
string s;
cin>>n;
for (i=n;i<2*n;i++)
cout<<i<<" ";
return 0;
}