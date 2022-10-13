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
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 
const int MX = 3e5 + 5;
#define MAXN 200005
#define MAXE 400010
#define  INF (1<<29)
vector<int> nxt, prv;
vector<vector<int>> dp;
vector<int> a;
int currCost;

void solve(int l, int r, int optl, int optr, int k) {
  if(l > r) return;
  int mid = (l + r) / 2;
  int best = optl;
  int mn = 1000000000;
  for(int i = optl; i <= min(mid, optr); i++) {
    int cmp = currCost + dp[i - 1][k - 1];
    if(cmp < mn)
      mn = cmp, best = i;
    if(nxt[i] <= mid)
      currCost -= (nxt[i] - i);
  }
  dp[mid][k] = mn;
  for(int i = min(mid, optr); i >= optl; i--) {
    //put back
    if(nxt[i] <= mid)
      currCost += (nxt[i] - i);
  }
  if(l == r) return;
  int lmid = (l + mid - 1) / 2, rmid = (r + mid + 1) /2;
  for(int i = mid; i > lmid; i--) {
    if(prv[i] >= optl)
      currCost -= (i - prv[i]);
  }
  solve(l, mid - 1, optl, best, k);
  for(int i = lmid + 1; i <= rmid; i++) {
    if(prv[i] >= optl)
      currCost += (i - prv[i]);
  }
  for(int i = optl; i < best; i++) {
    if(nxt[i] <= rmid)
      currCost -= (nxt[i] - i);
  }
  solve(mid + 1, r, best, optr, k);
  for(int i = best - 1; i >= optl; i--)
    if(nxt[i] <= rmid)
      currCost += (nxt[i] - i);
  for(int i = rmid; i > mid; i--)
    if(prv[i] >= optl)
      currCost -= (i - prv[i]);
  //solve left and right
}
int main() {
  int n, k; cin >> n >> k;
  a.resize(n);
  nxt.clear(), nxt.resize(n + 1);
  prv.clear(), prv.resize(n + 1);
  for(int i = 0; i < n; i++) {
    cin >> a[i], --a[i];
  }
  vector<int> bef(n, -1);
  //1 indexing
  for(int i = 0; i < n; i++) {
    prv[i + 1] = bef[a[i]];
    bef[a[i]] = i + 1;
  }
  bef.clear();
  bef.resize(n, n + 1);
  for(int i = n - 1; i >= 0; i--) {
    nxt[i + 1] = bef[a[i]];
    bef[a[i]] = i + 1;
  }
  dp.resize(n + 1, vector<int>(k + 1));
  //solve for base case when k = 0
  dp[0][0] = 0;
  for(int i = 1; i <= n; i++)
    dp[i][0] = 1000000000;
  for(int x = 1; x <= k; x++) {
    currCost = 0;
    int mid = (1 + n) / 2;
    for(int i = 1; i <= mid; i++) {
      if(nxt[i] <= mid)
        currCost += nxt[i] - i;
    }
    solve(1, n, 1, n, x);
  }
  cout << dp[n][k] << "\n";
}