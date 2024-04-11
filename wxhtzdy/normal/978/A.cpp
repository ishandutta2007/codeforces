#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++)cin>>a[i];
  vector<int> v;
  map<int,int> cnt;
  for(int i=n-1;i>=0;i--){
    if(cnt[a[i]]==0)v.push_back(a[i]);
    cnt[a[i]]++;
  }
  cout<<(int)v.size()<<endl;
  reverse(v.begin(),v.end());
  for(auto c:v)cout<<c<<" ";
}