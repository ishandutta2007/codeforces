#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define f first
#define s second
typedef gp_hash_table<int, null_type, hash<int>> ht;
#define ordered_set tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update> 
const int MX = 2e5 + 5;
int main() {
  int t; cin >> t;

  while(t--) {
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }

    vector<int> stack;
    for(int i = 0; i < n; i++) {
      if(a[i] > 1) {
        while(stack.size() && stack.back() != a[i] - 1)
          stack.pop_back();
        if(stack.size())
          stack.pop_back();
      }
      stack.push_back(a[i]);

      string curr = "";
      for(int j = 0; j < (int) stack.size(); j++) {
        curr += to_string(stack[j]);
        if(j < (int) stack.size() - 1)
          curr += ".";
      }
      cout << curr << "\n";
    }
  }
}