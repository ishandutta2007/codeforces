#include <iostream>
#include <map>
#include <time.h>
using namespace std;
typedef long long ll;
#define tr 1000000007
bool azaza (ll x, ll k)
{
ll k1=0;
while (x)
{
if (x%10==4||x%10==7) k1++;
x/=10;
}
return (k1<=k);
}
int main()
{
ll n,k2,k1,i,j,k;
cin>>n>>k;
k1=0;
for (i=0;i<n;i++)
{
cin>>k2;
if (azaza(k2,k)) k1++;
}
cout<<k1<<endl;
return 0;
}