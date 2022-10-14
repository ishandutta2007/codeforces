#include <iostream>
#include <map>
#include <algorithm>
#include <cstring>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <vector>
using namespace std;
typedef long long ll;
typedef double db;
ll k,k1,i,x,k2,j,er[10000100],a[10000005],b[10000005],a2[100005],b2[100005],n,m,azaza,z1,z2,yw,xb,yb,z;
vector <ll> a1,b1;
int main()
{
    char t;
cin>>n;
if (n%2==1) cout<<-1;
else 
for (i=1;i<=n;i++)
if (i%2==0) cout<<i-1<<" "; else cout<<i+1<<" ";
return 0;
}