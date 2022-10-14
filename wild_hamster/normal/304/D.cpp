#include <iostream>
#include <map>
#include <algorithm>
#include <cstring>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <vector>
//#include <cmath>
//#define tr 1000000007
using namespace std;
typedef long long ll;
typedef double db;
ll x1,x2,y1,y2,max1,rez,k,m,k1,k2,k3,k4,k5,k6,i,n,j;
//ll a[100100],b[100100],c[100100];
vector <ll> f;
map <ll,ll> f1[2];
ll gcd(ll a, ll b)
{
if (a<b) swap(a,b);
if (b==0) return a; else
return gcd(b,a%b);
}
int main()
{
    string s1,s2;
    ll x,y,m,n,a,b;
cin>>n>>m>>x>>y>>a>>b;
k=gcd(a,b);
a/=k;b/=k;
k=min(n/a,m/b);
if ((a*k)%2==0) {x1=x-(a*k)/2;x2=x+(a*k)/2;} else
{x1=x-(a*k)/2-1;x2=x+(a*k)/2;}
if ((b*k)%2==0) {y1=y-(b*k)/2;y2=y+(b*k)/2;} else
{y1=y-(b*k)/2-1;y2=y+(b*k)/2;}
if (x1<0) {x2-=x1;x1=0;}
if (x2>n) {x1=x1-(x2-n);x2=n;}
if (y1<0) {y2-=y1;y1=0;}
if (y2>m) {y1=y1-(y2-m);y2=m;}
cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
return 0;
}