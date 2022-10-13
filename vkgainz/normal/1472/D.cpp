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
const int MX = 2e5 + 5;
int w[MX];
bool cmp(const int &x, const int &y) {
  return w[x] < w[y];
}
int main() {
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    vector<int> odd, even;
    for(int i=0;i<n;i++) {
      if(a[i]%2==0) even.push_back(a[i]);
      else odd.push_back(a[i]);
    }
    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());
    ll alice = 0LL, bob = 0LL;
    int turn = 0;
    while(true) {
      if(odd.size()==0 && even.size()==0) break;
      if(turn==0) {
        if(odd.size()==0) {
          alice+=even.back();
          even.pop_back();
        }
        else if(even.size()==0) {
          odd.pop_back();
        }
        else {
          if(even.back()>odd.back()) {
            alice+=even.back();
            even.pop_back();
          }
          else odd.pop_back();
        }
      }
      else {
        if(odd.size()==0) {
          even.pop_back();
        }
        else if(even.size()==0) {
          bob+=odd.back();
          odd.pop_back();
        }
        else {
          if(odd.back()>even.back()) {
            bob+=odd.back();
            odd.pop_back();
          }
          else even.pop_back();
        }

      }
      turn = 1-turn;
    }
    if(alice==bob) cout << "Tie" << "\n";
    else if(alice > bob) cout << "Alice" << "\n";
    else cout << "Bob" << "\n";
  }
}