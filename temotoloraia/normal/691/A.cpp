#include <bits/stdc++.h>
using namespace std;
int n,a[2000],i,j,ans;
int main()
{
cin>>n;
for (i=1;i<=n;i++){cin>>a[i];ans+=a[i];}
if (n==1)ans--;
if (ans==n-1)cout<<"YES"<<endl;
else cout<<"NO"<<endl;
return 0;
}