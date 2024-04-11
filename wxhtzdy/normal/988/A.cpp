#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,k;
  cin>>n>>k;
  int a[n];
  for(int i=0;i<n;i++)cin>>a[i];
  map<int,int> was;
  int cnt=0;
  for(int i=0;i<n;i++){
    if(!was[a[i]])cnt++;
    was[a[i]]=1;
  }
  if(cnt<k){
    cout<<"NO";
    return 0;
  }
  cout<<"YES"<<endl;
  map<int,int> was2;
  for(int i=0;i<n;i++){
    if(!was2[a[i]]){
      cout<<i+1<<" ";
      k--;
      was2[a[i]]=1;
    }
    if(k<=0)break;
  }
}