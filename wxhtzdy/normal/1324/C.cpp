#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin>>t;
  while(t--){
    string s;
    cin>>s;
    int n=(int)s.length();
    vector<int> v;
    v.push_back(0);
    for(int i=0;i<n;i++){
      if(s[i]=='R')v.push_back(i+1);
    }
    v.push_back(n+1);
    int ans=0;
    for(int i=1;i<(int)v.size();i++)ans=max(ans,v[i]-v[i-1]);
    cout<<ans<<endl;
  }
}