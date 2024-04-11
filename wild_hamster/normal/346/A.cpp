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
string g;
ll j,x,n,m,k,a[100500],b[100500],dp[100500],rez,y,cnt,d,l,r,i;
ll f[50000];
ll Abs(ll a)
{
if (a<0) return -a; else return a;
}
ll gcd(ll a, ll b)
{
if (b==0) return a;
else return gcd(b,a%b);
}
int main()
{
cin>>n;
rez=0;
cnt=0;
for (i=0;i<n;i++) {cin>>a[i];f[cnt++]=a[i];}
sort(a,a+n);
rez=a[n-1];
for (i=0;i<1;i++)
for (j=i+1;j<n;j++)
f[cnt++]=(a[j]-a[i]);
ll max1=(ll)1e+10;
for (i=0;i<cnt;i++)
for (j=i+1;j<cnt;j++)
max1=min(max1,gcd(f[i],f[j]));
rez=rez/max1-n;
if (rez%2) cout<<"Alice"<<endl; else cout<<"Bob"<<endl;
return 0;
}