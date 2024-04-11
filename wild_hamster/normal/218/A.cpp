#include <iostream>
using namespace std;
typedef long long ll;
int main()
{
ll a[100005],n,m,k,i,j;
cin>>n>>k;
for (i=1;i<=2*n+1;i++) cin>>a[i];
for (i=1;i<=2*n+1;i++)
{
if (i%2==0&&a[i]-1>a[i-1]&&a[i]-1>a[i+1]) {a[i]--;k--;}
if (k==0) break;
}
for (i=1;i<=2*n+1;i++) cout<<a[i]<<" ";
return 0;
}