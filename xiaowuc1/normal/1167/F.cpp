#include <algorithm>
#include <bitset>
#include <cassert>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, ll> pill;

const int BIT_SIZE = 500005;
const int MOD = 1000000007;

pill bit[BIT_SIZE];
pill query(int n) {
  n += 2;
  int amt = 0;
  ll sum = 0;
  while(n > 0) {
    amt += bit[n].first;
    sum += bit[n].second;
    n -= n & -n;
  }
  return {amt, sum};
}
void update(int i, int v) {
  i += 2;
  while(i < BIT_SIZE) {
    bit[i].first++;
    bit[i].second += v;
    i += i & -i;
  }
}

pii l[500005];
void solve() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> l[i].first;
    l[i].second = i+1;
  }
  sort(l, l+n);
  ll ret = 0;
  ll totalSum = 0;
  for(int i = 0; i < n; i++) {
    ll match = 0;
    {
      // 1 count
      int lhs = l[i].second;
      int rhs = n+1-lhs;
      match += lhs * (ll)rhs;
      match %= MOD;
    }
    {
      // lhs count
      pill lhsQuery = query(l[i].second);
      pill rhsQuery = {i - lhsQuery.first, totalSum - lhsQuery.second};
      // cout << lhsQuery.first << " " << lhsQuery.second << endl;
      // cout << rhsQuery.first << " " << rhsQuery.second << endl;

      lhsQuery.second %= MOD;
      rhsQuery.second %= MOD;
      int rhs = n + 1 - l[i].second;
      // cout << lhsQuery.second * rhs << " left matches for " << l[i].first << endl;
      match += lhsQuery.second * rhs;
      match %= MOD;
      // rhsCount
      {
        int lhs = l[i].second;
        ll rhsinc = (n+1LL) * rhsQuery.first - rhsQuery.second;
        rhsinc %= MOD;
        rhsinc += MOD;
        rhsinc %= MOD;
        rhsinc *= lhs;
        rhsinc %= MOD;
        // cout << rhsinc << " right matches for " << l[i].first << endl;
        match += rhsinc;
        match %= MOD;
      }
    }
    // cout << match << " matches for " << l[i].first << endl;
    ret += match * l[i].first;
    ret %= MOD;
    totalSum += l[i].second;
    update(l[i].second, l[i].second);
  }
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
  /*
  int t;
  cin >> t;
  for(int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  */
}