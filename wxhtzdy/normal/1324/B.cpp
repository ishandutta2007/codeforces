#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    int a[n];
    map<int,int> cnt;
    for(int i=0;i<n;i++)cin>>a[i];
    bool ok=0;
    cnt[a[0]]=1;
    for(int i=1;i<n;i++){
      if((cnt[a[i]]==1&&a[i]!=a[i-1])||(cnt[a[i]]>=2))ok=1;
      cnt[a[i]]++;
    }
    if(ok)cout<<"YES\n";
    else cout<<"NO\n";
  }
}