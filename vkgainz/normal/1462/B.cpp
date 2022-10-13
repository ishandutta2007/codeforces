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
    string s; cin >> s;
    if(s=="2020") {
      cout << "Yes" << "\n";
    }
    else {
      bool w = false;
      for(int i=0;i<=4;i++) {
        for(int j=n-1;j>=n-5;j--) {
          if(j<i) continue;
          string x = s.substr(0, i) + s.substr(j+1, n-j-1);
          if(x=="2020") {
            w = true;
          }
        }
      }
      if(w) cout << "Yes" << "\n";
      else cout << "No" << "\n";
    }
  }
}