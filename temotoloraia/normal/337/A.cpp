#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,a[100],ans;
int main(){
   cin>>n>>m;
   for (int i=1;i<=m;i++)cin>>a[i];
   sort(a+1,a+m+1);
   ans=a[n]-a[1];
   for (int i=2;i<=m-n+1;i++)
      ans=min(ans,a[i+n-1]-a[i]);
   cout<<ans<<endl;
	return 0;	
}