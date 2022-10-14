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
ll a[100100],b[100100],c[100100];
vector <ll> f;
map <ll,ll> f1[2];
ll data(ll k2, ll k1, ll k3)
{
ll k=0;
if (k1>=1) k+=31;
if (k1>=2) if (k2%4==0&&k2!=1900) k+=29; else k+=28;
if (k1>=3) k+=31;
if (k1>=4) k+=30;
if (k1>=5) k+=31;
if (k1>=6) k+=30;
if (k1>=7) k+=31;
if (k1>=8) k+=31;
if (k1>=9) k+=30;
if (k1>=10) k+=31;
if (k1>=11) k+=30;
if (k1>=12) k+=31;
if (k1==1) k-=31-k3;
if (k1==2) if (k2%4==0&&k2!=1900) k-=29-k3; else k-=28-k3;
if (k1==3) k-=31-k3;
if (k1==4) k-=30-k3;
if (k1==5) k-=31-k3;
if (k1==6) k-=30-k3;
if (k1==7) k-=31-k3;
if (k1==8) k-=31-k3;
if (k1==9) k-=30-k3;
if (k1==10) k-=31-k3;
if (k1==11) k-=30-k3;
if (k1==12) k-=31-k3;
return k;
}
int main()
{
    string s1,s2;
    ll a1,a2,a3,b1,b2,b3;
cin>>n;
if (n%2==0) {cout<<-1;return 0;}
for (i=0;i<n;i++) {a[i]=i;b[i]=i;c[i]=(2*i)%n;}
for (i=0;i<n;i++) printf("%d ",a[i]);
cout<<endl;
for (i=0;i<n;i++) printf("%d ",b[i]);
cout<<endl;
for (i=0;i<n;i++) printf("%d ",c[i]);
cout<<endl;
return 0;
}