#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
using namespace std;
typedef long long ll;
typedef double db;
#define tr 5000000
//map <ll,ll> a,b,c;
ll i,m,p,q,n,min1,k,k1,k2,a[100500][2],b[100500];
int main() 
{
cin>>n>>m;
if (m>=(n*(n-1))/2) {cout<<"no solution";return 0;}
for (i=1;i<=n;i++) {cout<<i%2<<" "<<i<<endl;}
return 0;
}