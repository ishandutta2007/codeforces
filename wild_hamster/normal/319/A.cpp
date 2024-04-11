#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
#include <stdio.h>
#define tr 1000000007
using namespace std;
typedef long long ll;
typedef double db;
//map <ll,ll> a,b,c;
ll max1,a[300000],x1,y1,x,y,b[300000],n1,i1,d,t,m,i,j,k,rez,n,k1,k2,k3,k4,k5;
db kkk;
vector <ll> f;
int main()
{
string s;
cin>>s;
for (i=0;i<s.size();i++) 
a[i]=(int)s[i]-'0';
rez=1;
for (i=0;i<s.size()-1;i++) 
rez=(rez*2)%tr;
k1=0;
n=s.size();
for (i=n-1;i>=0;i--)
{
if (a[i]==1) k1=(k1+rez)%tr;
rez=(rez*2)%tr;
}
cout<<k1<<endl;
//system("pause");
return 0;
}