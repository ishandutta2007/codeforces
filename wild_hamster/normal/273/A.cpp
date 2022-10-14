#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;
typedef double db;
ll a[100005],tmp,m,d[100500],d1[100500],rez,s,n,k,k1,k2,i,j;
//map <ll,ll> a,b,c;
int main() 
{
cin>>n;
for (i=0;i<n;i++) cin>>a[i];
cin>>m;k=0;tmp=a[0];
while (m--)
{
cin>>k1>>k2;
k1--;
if (k>=k1) {cout<<tmp<<endl;tmp+=k2;}
else {cout<<max(a[k1],tmp)<<endl;k=k1;tmp=max(a[k1],tmp)+k2;}
}
return 0;
}