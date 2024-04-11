#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
ll a[100005],y,k2,k3,r1,z,k4,r,max1,k5,k1,min1,b[1005],n1,n,m,k,i,j;
vector<char > f;
int main()
{
cin>>y>>k>>n;
k1=0;
for (i=y/k;i<=n/k;i++)
if (i*k>y&&i*k<=n) {cout<<i*k-y<<" ";k1++;}
if (k1==0) cout<<-1;
return 0;
}