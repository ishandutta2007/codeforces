#include<bits/stdc++.h> 
using namespace std; 
int main() { 
  int n;
  cin>>n;
  pair<long long,long long> a[n];
  map<long long,long long> cnt;
  for(int i=0;i<n;i++){
    cin>>a[i].first>>a[i].second;
    cnt[a[i].first]=max(cnt[a[i].first],a[i].second);
  }  
  int m;
  cin>>m;
  pair<long long,long long> b[m];
  for(int i=0;i<m;i++){
    cin>>b[i].first>>b[i].second;
    cnt[b[i].first]=max(cnt[b[i].first],b[i].second);
  }
  map<long long,long long> taken;
  long long sum=0;
  for(int i=0;i<n;i++){
    if(!taken[a[i].first])sum+=cnt[a[i].first];
    taken[a[i].first]=1;
  }
  for(int i=0;i<m;i++){
    if(!taken[b[i].first])sum+=cnt[b[i].first];
    taken[b[i].first]=1;
  }
  cout<<sum;
}