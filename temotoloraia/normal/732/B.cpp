#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k,a[505],ans;
int main(){
   cin>>n>>k;
   for (int i=1;i<=n;i++)cin>>a[i];
   for (int i=2;i<=n;i++)
   if (a[i]+a[i-1]<k){
      ans+=k-a[i]-a[i-1];
      a[i]=k-a[i-1];
   }
   cout<<ans<<endl;
   for (int i=1;i<=n;i++)cout<<a[i]<<" ";
	return 0;	
}