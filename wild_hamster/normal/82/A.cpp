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
k=0;x=5;
while (k<n-x)
{
k+=x;
x*=2;
}
if ((n-k-1)/(x/5)==0) cout<<"Sheldon"<<endl;
if ((n-k-1)/(x/5)==1) cout<<"Leonard"<<endl;
if ((n-k-1)/(x/5)==2) cout<<"Penny"<<endl;
if ((n-k-1)/(x/5)==3) cout<<"Rajesh"<<endl;
if ((n-k-1)/(x/5)==4) cout<<"Howard"<<endl;
return 0;
}