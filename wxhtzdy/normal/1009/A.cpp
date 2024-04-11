#include<bits/stdc++.h> 
using namespace std; 
int main() { 
  int n,m;
  cin>>n>>m;
  int a[n],b[m];
  for(int i=0;i<n;i++)cin>>a[i];
  for(int i=0;i<m;i++)cin>>b[i];
  int sz=0,ans=0;
  for(int i=0;i<n;i++){
    if(sz<m&&b[sz]>=a[i])ans++,sz++;
  }
  cout<<ans;
}