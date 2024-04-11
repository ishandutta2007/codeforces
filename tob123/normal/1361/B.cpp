#include<bits/stdc++.h>
#pragma GCC optimize ("O3")
#define int long long

using namespace std;

int pow(int x, int y, int M){
  if(!y) return 1;
  int z = pow(x, y/2, M);
  z *= z;
  z %= M;
  if(y%2) z *= x, z %= M;
  return z;
}

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  int t;
  cin >> t;
  while(t--){
    int n, p, plus = 0, last = 1e6, M = 1e9+7, s = 0, diff = 0;
    cin >> n >> p;
    vector<int> k(n);
    for(int &x : k) cin >> x;
    if(p == 1) {
      cout<<(n%2)<<"\n";
      continue;
    }
    sort(k.begin(), k.end());
    while(n--){
      int x = pow(p, k[n], M);
      for(int i = 0; plus && i < last-k[n]; i++){
        if(plus <= n+1) plus *= p;
        else break;
      }
      if(plus > n+1) s = 1;
      if(s) diff = (diff-x+M)%M;
      else{
        if(plus > 0) (diff += M-x)%=M, plus--;
        else (diff += x)%=M, plus++;
      }
      if(plus > n) s = 1;
      last = k[n];
    }
    cout << diff%M << "\n";
  }
}