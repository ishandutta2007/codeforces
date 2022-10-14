#include <bits/stdc++.h>
using namespace std;
const int inf=400000050;
int main(){
  int n;
  cin>>n;
  int a[n],b[n];
  for(int i=0;i<n;i++)cin>>a[i];
  for(int i=0;i<n;i++)cin>>b[i];
  int mn[n];  
  for(int i=0;i<n;i++)mn[i]=inf;
  for(int i=1;i<n;i++){
    for(int j=0;j<i;j++){
      if(a[j]<a[i])mn[i]=min(mn[i],b[j]+b[i]);
    }
  }
  int mx[n];
  for(int i=0;i<n;i++)mx[i]=inf;
  for(int i=2;i<n;i++){
    for(int j=1;j<i;j++){
      if(mn[j]==inf||a[i]<=a[j])continue;
      mx[i]=min(mx[i],mn[j]+b[i]);
    }
  } 
  int ans=inf;
  for(int i=0;i<n;i++)ans=min(ans,mx[i]);
  if(ans==inf)cout<<-1;
  else cout<<ans;
}