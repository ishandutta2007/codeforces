#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <sstream>
using namespace std;
typedef long long ll;
typedef double db;
#define tr 1000000007
#define pb push_back
ll j,x,n,m,k,a[100500],b[100500],dp[100500],y,d,l,r,i;
ll gcd(ll a, ll b)
{
if (b==0) return a;
else return gcd(b,a%b);
}
int main()
{
cin>>n;
k=0;l=-1;
for (i=0;i<n;i++) {cin>>a[i];k+=a[i];l=max(l,a[i]);}
cout<<max(l,(k-1)/(n-1)+1)<<endl;
return 0;
}