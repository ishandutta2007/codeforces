#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define f first
#define s second
#define vi vector<int>
#define vvi vector<vector<int>>
#define pb push_back
#define mp make_pair
typedef long double ld;
typedef gp_hash_table<int, null_type, hash<int>> ht;
#define ordered_set tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update> 
const int MX = 2e5 + 5;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int q; cin >> q;
  while(q--){ 
    int n; cin >> n;
    vector<int> st(n), en(n);
    fill(st.begin(), st.end(), -1);
    fill(en.begin(), en.end(), -1);
    vector<int> a(n);
    for(auto &a : a) cin >> a, --a;
    set<int> s;
    for(auto &a : a) s.insert(a);
    map<int, int> m;
    int v = 0;
    for(auto &it : s) m[it] = v++;
    for(int i=0;i<n;i++) a[i] = m[a[i]];
    for(int i=n-1;i>=0;i--) {
      st[a[i]] = i;
    }
    for(int i=0;i<n;i++) {
      en[a[i]] = i;
    }
    vector<int> dp(n);
    vector<int> temp(n);
    fill(dp.begin(), dp.end(), -10000000);
    fill(temp.begin(), temp.end(), -10000000);
    int ans = 0;
    for(int i=0;i<n;i++) {
      if(st[a[i]] == i) {
        if(a[i])
          temp[a[i]] = max(1, dp[a[i]-1]+1);
        else
          temp[a[i]] = 1;
      }
      if(en[a[i]] == i) {
        dp[a[i]] = temp[a[i]];
        ans = max(ans, dp[a[i]]);
      }
    }
    cout << s.size() - ans << "\n";
  }
}