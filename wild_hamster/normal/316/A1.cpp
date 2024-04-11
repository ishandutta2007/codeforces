#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
#include <stdio.h>
using namespace std;
typedef long long ll;
typedef double db;
//map <ll,ll> a,b,c;
vector <ll> f;
ll a[2000500],n1,i1,c[2000500],b[2000500],d,s,t,m,i,j,k,rez,n,k1,k2,k3,k4,k5;
string s1;
int main()
{
cin>>s1;
for (i=0;i<1000;i++) a[i]=0;
if (s1[0]>='A'&&s1[0]<='J') {a[s1[0]]--;k=9;m=9;} else 
if (s1[0]=='?') {k=9;m=10;} else {k=1;m=10;}
k1=0;
for (i=1;i<s1.size();i++)
{
if (s1[i]>='A'&&s1[i]<='J'&&a[s1[i]]==0) {k*=m;a[s1[i]]--;m--;}
if (s1[i]=='?') k1++;
}
cout<<k;
for (i=0;i<k1;i++) cout<<0;
return 0;
}