#include<bits/stdc++.h> 
using namespace std; 
int main() { 
  long long n,k;
  cin>>n>>k;
  long long a[n];
  for(int i=0;i<n;i++)cin>>a[i];
  sort(a,a+n);
  long long cnt=n,tt=0;
  for(int i=1;i<n;i++){
    if(a[i]==a[i-1])continue;
    long long bot=tt,top=i,ans=i;
    while(bot<=top){
      long long mid=(bot+top)/2;
      if(a[mid]+k<a[i]||a[mid]>=a[i])bot=mid+1;
      else ans=mid,top=mid-1;
    }
    cnt-=i-ans;
    tt=i;
  }
  cout<<cnt;
}