#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree <pair<ll, int>, null_type, less<pair<ll, int>>, rb_tree_tag, tree_order_statistics_node_update>
typedef long long ll;
typedef long double ld;
#define f first
#define s second
const int MX = 5e3 + 5;

int main() {
  int n; cin >> n;
  vector<int> a(n, 0);
  for(int i=0;i<n;i++) {
    cin >> a[i];
  }
  vector<int> inOne, inTwo, inThree;
  vector<int> nxt(n, -1);
  for(int i=n-1;i>=0;i--) {
    if(a[i] == 0) continue;
    if(a[i] == 1) {
      inOne.push_back(i);
    }
    else if(a[i] == 2) {
      if(inOne.empty()) {
        cout << -1 << "\n";
        return 0;
      }
      nxt[i] = inOne.back();
      inOne.pop_back();
      inTwo.push_back(i);
    }
    else {
      if(!inThree.empty()) {
        nxt[i] = inThree.back();
      }
      else if(!inTwo.empty()) {
        nxt[i] = inTwo.back();
      }
      else if(!inOne.empty()) {
        nxt[i] = inOne.back();
        inOne.pop_back();
      }
      else {
        cout << -1 << "\n";
        return 0;
      }
      inThree.push_back(i);
    }
  }
    vector<bool> vis(n, false);
    int currRow = 0;
    vector<pair<int, int>> ans;
    for(int i=0;i<n;i++) {
      if(a[i] == 0) continue;
      if(vis[i]) continue;
      int curr = i;
      while(curr != -1) {
        vis[curr] = true;
        int next = nxt[curr];
        if(next == -1) { //a[curr] == 1
          ans.push_back({currRow, curr});
          ++currRow;
          curr = next;
        }
        else {
            ans.push_back({currRow, curr});
          if(a[curr] == 3) {
            ans.push_back({currRow, next});
            ++currRow;
          }
          curr = next;
        }
      }
    }
    cout << ans.size() << "\n";
    for(auto &it : ans) {
      cout << it.f+1 << " " << it.s+1 << "\n";
    }
}