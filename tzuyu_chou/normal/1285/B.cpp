#include<vector>
#include<iostream>

using namespace std;
 
#define ll long long
#define ar array
 
#define fi first
#define se second

ll tzuyu(vector<int>b){
  ll cur=0;
  ll best=-1e18;
  for(int x:b){
    cur+=x;
    best=max(best,cur);
    cur=max(cur,0ll);
  }
  return best;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vector<int>a(n);
    ll tot=0;
    for(int i=0;i<n;i++){
      cin>>a[i];
      tot+=a[i];
    }
    auto l=a;
    l.erase(l.begin());
    ll kek=tzuyu(l);
    l=a;
    l.pop_back();
    kek=max(kek,tzuyu(l));
    if(kek>=tot){
      cout<<"NO\n";
    }else{
      cout<<"YES\n";
    }
  }
}