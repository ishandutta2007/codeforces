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
int main()
{
cin>>n;
k=0;
for (c=1;c<=n;c++)
for (a=1;a<c;a++)
{
b=c*c-a*a;
k1=max((ll)1,(ll)(sqrt((db)b)-1));
while (k1*k1<b) k1++;
if (k1*k1==b) k++;
}
cout<<k/2<<endl;
return 0;
}