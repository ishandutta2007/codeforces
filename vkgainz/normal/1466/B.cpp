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
    vector<int> x(n);
    for(int i=0;i<n;i++) cin >> x[i];
    set<int> s;
    ++x[n-1];
    s.insert(x[n-1]);
    for(int i=n-2;i>0;i--) {
      if(x[i-1]==x[i] || x[i]+1 < x[i+1]) {
        ++x[i];
      }
      s.insert(x[i]);
    }
    s.insert(x[0]);
    cout << s.size() << "\n";
  }
}