#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
typedef long long ll;
typedef double db;
#define tr 1000000007
map <ll,ll> c;
ll r,i,j,m,n,k1,k2,k3,k4,k5,k6,k7,k8,k,a[100500],b[100500];
vector <ll> f;
void aza(ll x)
{
if (c[x]==1) {c[x]=0;f.push_back(x);} else
if (c[x]==0) return; else
{
if (c[x]%2==1) {c[x+1]+=c[x]/2;c[x]=0;f.push_back(x);}
else {c[x+1]+=c[x]/2;c[x]=0;}
aza(x+1);
}
}
int main() 
{
k=0;
cin>>n;
for (i=0;i<n;i++) {cin>>a[i];if (c[a[i]]==0) b[k++]=a[i];c[a[i]]++;}
for (i=0;i<k;i++)
if (c[b[i]]) aza(b[i]);
//for (i=0;i<f.size();i++) cout<<f[i]<<" ";
//cout<<endl;
cout<<f[f.size()-1]+1-f.size()<<endl;
return 0;
}