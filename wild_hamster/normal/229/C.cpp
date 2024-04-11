#include <iostream>
#include <map>
#include <algorithm>
#include <cstring>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <vector>
#include <cmath>
//#define tr 1000000007
using namespace std;
typedef long long ll;
typedef double db;
ll max1,rez,k,m,k1,k2,k3,k4,k5,k6,i,n,j;
ll a[1000001],b[101][10001],c[101];
vector <ll> f;
//map <ll,ll> f1[2];
ll gcd(ll a, ll b)
{
if (a<b) swap(a,b);
if (b==0) return a; else
return gcd(b,a%b);
}
int main()
{
char c1;
cin>>n>>m;
k=n-2;
ll rez=(n*(n-1)*(n-2))/6;
for (i=1;i<=1000000;i++) a[i]=0;
for (i=0;i<m;i++)
{
scanf("%I64d%I64d",&k1,&k2);
rez-=k-a[k1]-a[k2];
a[k1]++;a[k2]++;
}
cout<<max(rez,(ll)0)<<endl;
return 0;
}