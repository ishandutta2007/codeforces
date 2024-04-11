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
const int MX = 3e5+5;
int query(int x) {
  cout << "?" << " " << x << "\n";
  cout.flush();
  int ret; cin >> ret;
  return ret;
}
int main() {
  int n, k; cin >> n >> k;
  int currIter = 0;
  int curr = n;
  int ans = -1;
  while(true) {
    int x = query(curr);
    if(x==k) {
      ++currIter;
      curr-=(currIter-1);
    }
    else if(x<k) {
      if(currIter==1) {
        ans = 1;
      }
      else {
        ans = curr+currIter-1;
      }
      break;
    }
    else {
      break;
    }
  }
  if(ans != -1) {
    cout << "!" << " " << ans << "\n";
    return 0;
  }
  while(true) {
    --curr;
    int x = query(curr);
    if(x==k) {
      ans = curr;
      break;
    }
  }
  cout << "!" << " " << ans << "\n";
}