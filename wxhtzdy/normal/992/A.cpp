#include<bits/stdc++.h> 
using namespace std; 
int main() { 
  int n;
  cin>>n;
  int a[n];
  map<int,int> cnt;
  int ans=0;
  for(int i=0;i<n;i++){
    cin>>a[i];
    if(a[i]!=0&&cnt[a[i]]==0)ans++;
    cnt[a[i]]++;
  }
  cout<<ans;
}