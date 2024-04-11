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
ll a,b,c;
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
cin>>s1>>s2;
a1=1000*((ll)s1[0]-48)+100*((ll)s1[1]-48)+10*((ll)s1[2]-48)+((ll)s1[3]-48);
b1=1000*((ll)s2[0]-48)+100*((ll)s2[1]-48)+10*((ll)s2[2]-48)+((ll)s2[3]-48);
a2=10*((ll)s1[5]-48)+((ll)s1[6]-48);
b2=10*((ll)s2[5]-48)+((ll)s2[6]-48);
a3=10*((ll)s1[8]-48)+((ll)s1[9]-48);
b3=10*((ll)s2[8]-48)+((ll)s2[9]-48);
//cout<<a1<<" "<<a2<<" "<<a3<<endl<<b1<<" "<<b2<<" "<<b3;
k1=0;k2=0;
for (i=1900;i<a1;i++)
if (i!=1900&&i%4==0) k1+=366; else k1+=365;
for (i=1900;i<b1;i++)
if (i!=1900&&i%4==0) k2+=366; else k2+=365;
//cout<<k1<<" "<<k2<<endl;
k1+=data(a1,a2,a3);
k2+=data(b1,b2,b3);
//cout<<k1<<" "<<k2<<endl;
cout<<abs((double)(k1-k2));
return 0;
}