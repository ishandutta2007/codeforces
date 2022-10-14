#include <iostream>
#include <map>
#include <algorithm>
#include <cstring>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;
typedef double db;
ll k,k1,k2,i,n,m,azaza,min1,z1,x,z2,yw,xb,yb,z;
vector <ll> a1,b1;
int main()
{
    char t;
cin>>n;
min1=(ll)1e+17;
for (i=1;i<=81;i++)
{
k=i*i+4*n;
k1=max((ll)0,(ll)sqrt(db(k))-1);
while (k1*k1<k) k1++;
if (k1*k1==k&&(-i+k1)%2==0)
{
x=(-i+k1)/2;
z1=x;
k2=0;
while (z1) {k2+=z1%10;z1/=10;}
if (k2==i) if (x<min1) min1=x;
}
}
if (min1==(ll)1e+17) cout<<-1; else cout<<min1;
return 0;
}