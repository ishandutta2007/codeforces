#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <time.h>
using namespace std;
typedef long long ll;
typedef double db;
#define tr 1000000007
ll t,s,y,j1,j2,rez,a[150000],t1,t2,z,x,y1,y2,m,n,i,j,k1,k;
ll binpow(ll a, ll x)
{
if (x==0) return 1;
if (x%2) return (a*binpow(a,x-1))%tr;
ll t=binpow(a,x/2);
return (t*t)%tr;
}
int main()
{
string s;
cin>>s;
cin>>k;
n=s.size();
a[0]=1;
for (i=1;i<=n;i++)
a[i]=(a[i-1]*2)%tr;
rez=0;
for (i=0;i<n;i++)
if (s[i]=='5'||s[i]=='0') rez=(rez+a[i])%tr;
y1=((binpow(a[n],k)-1+tr)*binpow(a[n]-1,tr-2))%tr;
cout<<(rez*y1)%tr<<endl;
return 0;
}