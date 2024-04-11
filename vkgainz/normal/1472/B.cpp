#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define f first
#define s second
typedef long long ll;
typedef long double ld;
typedef gp_hash_table<int, null_type, hash<int>> ht;
const int MX = 1e5+5;

int main() {
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    int none = 0;
    for(int i=0;i<n;i++) {
      int x; cin >> x; 
      if(x==1) ++none;
    }
    if(none == 0) {
      if(n%2==0) cout << "YES" << "\n";
      else cout << "NO" << "\n";
    }
    else {
      if(none%2 ==0 ) cout << "YES" << "\n";
      else cout << "NO" << "\n";
    }
  }
}