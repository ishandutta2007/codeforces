#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define f first
#define s second
typedef long long ll;
typedef long double ld;
using namespace std;
using namespace __gnu_pbds;
typedef tree<
pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>
ordered_set;

int main() {
  int t; cin >> t;
  while(t--) {
    int n, k; cin >> n >> k;
    for(int i=1;i<=k;i++) {
      if(i<2*k-n) cout << i << " ";
      else cout << 3*k-n-i << " ";
    }
    cout << "\n";
  }
}