#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,a[100005],ind,ans;
int main(){
   cin>>n;
   for (int i=1;i<=n;i++)cin>>a[i];
   for (int i=1;i<=n;i++){
      ind=i;
      while (a[ind+1]>=a[ind])ind++;
      ans=max(ind-i+1,ans);
      i=ind;
   }
   cout<<ans<<endl;
	return 0;
}