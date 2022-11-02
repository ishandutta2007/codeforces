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
  int n;
  cin>>n;
  cout << n+1<<endl;
}