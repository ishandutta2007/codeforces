#include<bits/stdc++.h> 
using namespace std; 
int main() { 
  int n,m;
  cin>>n>>m;
  int a[n],b[m];
  map<int,int> cnt;
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  vector<int> v;
  for(int i=0;i<m;i++){
    cin>>b[i];
    cnt[b[i]]=1;
  }
  for(int i=0;i<n;i++){
    if(cnt[a[i]])v.push_back(a[i]);
  }
  for(auto c:v)cout<<c<<" ";
}