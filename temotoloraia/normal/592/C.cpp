#include <bits/stdc++.h>
using namespace std;
long long m,n,k,ans,p,q;
int main()
{
cin>>m>>n>>k;
if (m<n && m<k){
cout<<"1/1"<<endl;return 0;}
p=n/__gcd(n,k)*k;
q=max(n,k);
n=min(n,k);
if (p%n!=0 || p%q!=0)
ans=n-1;
else
{
ans=n*(m/p)+n-1;
if (n-m%p>0)
ans=ans+m%p-n+1;
}
k=__gcd(ans,m);
cout<<ans/k<<"/"<<m/k<<endl;
return 0;
}