#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
#include <stdio.h>
#include <cmath>
#define tr 1000000007
#define y1 azazazaza
#define y2 azazazaza1
#define y3 azazazaza2
#define x1 azazazaza3
#define x2 azazazaza4
#define x3 azazazaza5
#define eps 1e+12
using namespace std;
typedef long long ll;
typedef double db;
//map <ll,ll> a,b,c;
ll k1,k2,i,n,max1,a[10000][2],rez1,rez2,y,p,b,c,x1,y1,x2,y2,x3,x,y3;
ll gcd(ll x, ll y)
{
if (y==0) return x;
else return gcd(y,x%y);
}
int main()
{
string s;
cin>>b>>c;
cin>>s;
p=s.size();
a[0][0]=0;a[0][1]=0;
k1=0;k2=0;
for (i=0;i<p;i++)
{
if (s[i]=='U') k2++;
if (s[i]=='D') k2--;
if (s[i]=='R') k1++;
if (s[i]=='L') k1--;
a[i+1][0]=k1;a[i+1][1]=k2;
}
rez1=a[p][0];rez2=a[p][1];
for (i=0;i<=p;i++)
if (rez1!=0&&rez2!=0) 
{if ((b-a[i][0])/rez1==(c-a[i][1])/rez2&&(c-a[i][1])/rez2>=0
&&(b-a[i][0])%rez1==0&&(c-a[i][1])%rez2==0)
{cout<<"Yes";return 0;}} else
if (rez1==0&&rez2!=0)
{if (b==a[i][0]&&(c-a[i][1])%rez2==0&&(c-a[i][1])/rez2>=0) {cout<<"Yes";return 0;}} else
if (rez1!=0&&rez2==0)
{if (c==a[i][1]&&(b-a[i][0])%rez1==0&&(b-a[i][0])/rez1>=0) {cout<<"Yes";return 0;}} else
if (rez1==0&&rez2==0)
{if (b==a[i][0]&&c==a[i][1]) {cout<<"Yes";return 0;}}
cout<<"No"<<endl;
return 0;
}