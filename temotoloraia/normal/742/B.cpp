#include <bits/stdc++.h>
using namespace std;
long long n,x;
long long a[500005],b[500005];
long long ans;
int main() {
   cin>>n>>x;
   for (int i=1;i<=n;i++)cin>>a[i];
   for (int i=1;i<=n;i++)b[a[i]]++;
   for (int i=1;i<=n;i++)
   if (x)ans+=b[a[i]^x];
   else ans+=b[a[i]^x]-1;
   cout<<ans/2<<endl;
	return 0;
}