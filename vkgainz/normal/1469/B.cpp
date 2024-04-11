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
    vector<int> r(n);
    for(int i=0;i<n;i++) cin >> r[i];
    int m; cin >> m;
    vector<int> b(m);
    for(int i=0;i<m;i++) cin >> b[i];
    int x = 0, curr = 0;
    for(int i=0;i<n;i++) {
      curr+=r[i], x = max(x, curr);
    }
    int y = 0;
    curr = 0;
    for(int i=0;i<m;i++) {
      curr+=b[i], y = max(y, curr);
    }
    cout << x+y << "\n";
  }
}