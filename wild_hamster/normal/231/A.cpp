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
ll y,j1,j2,rez,p[15],t1,t2,z,x,y1,y2,m,n,i,j,k1,k,a[1500150];
vector <ll> f;
ll gcd(ll a, ll b)
{
if (b==0) return a;
else return gcd(b,a%b);
}
ll Abs(ll a)
{
if (a<0) return -a; else return a;
}
ll sasai(ll n)
{
if (n%9==0) return 9; else return n%9;
}
int main()
{
cin>>n;
k=0;
while (n--)
{
cin>>y>>j1>>j2;
if (y+j1+j2>=2) k++;
}
cout<<k<<endl;
return 0;
}