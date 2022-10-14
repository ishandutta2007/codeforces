#include <iostream>
#include <map>
#include <algorithm>
#include <cstring>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <vector>
#include <cmath>
#define tr 1000000007
using namespace std;
typedef long long ll;
typedef double db;
ll max1,rez,sum,k,m,k1,k2,k3,k4,k5,k6,i,n,j;
ll dp[10000],a[1000100];
vector <vector <ll> > f(100005);
ll gcd(ll a, ll b)
{
if (a<b) swap(a,b);
if (b==0) return a;
else return gcd(b,a%b);
}
int main()
{
cin>>n>>m;
k=n%m;
for (i=0;i<k;i++)
cout<<n/m+1<<" ";
for (i=k;i<m;i++)
cout<<n/m<<" ";
return 0;
}