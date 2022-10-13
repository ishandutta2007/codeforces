#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using cd = complex<double>;
#define ll long long
#define f first
#define s second
#define vi vector<int>
#define vvi vector<vi>
#define vll vector<ll>
#define vvll vector<vll>
#define vpi vector<pair<int, int>>
#define vvpi vector<vpi>
#define pb push_back
#define mp make_pair
typedef long double ld;
typedef gp_hash_table<int, int, hash<int>> ht;
#define ordered_set tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update> 
const int MX = 400005;
const double PI = acos(-1);

int main() {
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    vector<int> a(n);
    for(auto &a : a) cin >> a;
    map<int, int> m;
    for(auto &a : a) 
      m[a] = 1;
    int x = 0;
    for(auto &a : m)
      m[a.f] = x++;
    for(auto &a : a)
      a = m[a];
    vector<int> l(n, n), r(n, -1);
    vector<int> pos(n, -1);
    vector<int> freq(n);
    for(int i = 0; i < n; i++)
      l[a[i]] = min(l[a[i]], i), r[a[i]] = max(r[a[i]], i);
    vector<int> dp(n);
    for(int i = n - 1; i >= 0; i--) {
      dp[i] = 1;
      if(a[i] + 1 < n && l[a[i] + 1] > i && r[a[i] + 1] != -1) //take all of nxt if nxt is in middle
        dp[i] = max(dp[i], dp[r[a[i] + 1]] + freq[a[i] + 1]);
      //go to nxt occurence of a[i]
      if(pos[a[i]] != -1)
        dp[i] = max(dp[i], 1 + dp[pos[a[i]]]);
      //end it at nxt
      if(a[i] + 1 < n)
        dp[i] = max(dp[i], 1 + freq[a[i] + 1]);
      ++freq[a[i]];
      pos[a[i]] = i;
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
      ans = max(ans, dp[i]);
    cout << n - ans << "\n";
  }
}