#include <bits/stdc++.h>

using namespace std;

int dig(int x){
  int ans=0;
  while (x){
    ans+=x%10;
    x/=10;
  }
  return ans;
}
int main(){
  int n;
  cin>>n;
  vector <int> ans;
  for(int i=0;i<min(200,n);i++){
    if (n-i+dig(n-i)==n) ans.push_back(n-i);
  }
  cout<<ans.size()<<'\n';
  for(int i=0;i<ans.size();i++) cout<<ans[ans.size()-i-1]<<" ";
}