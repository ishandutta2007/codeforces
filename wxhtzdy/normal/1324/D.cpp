#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int a[n],b[n];
  for(int i=0;i<n;i++)cin>>a[i];
  for(int i=0;i<n;i++)cin>>b[i];
  vector<int> v;
  for(int i=0;i<n;i++){
    v.push_back(a[i]-b[i]);
  }
  sort(v.begin(),v.end());
  long long ans=0;
  int j=n-1;
  for(int i=0;i<n;i++){
    j=min(j,n-1);
    while(j>i+1&&v[i]+v[j-1]>0)j--;
    while(j<n&&v[i]+v[j]<=0)j++;
    j=max(j,i+1);
    ans+=n-j;
  }
  cout<<ans<<endl;
}