#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n;
ll total;
ll lhs[200000];
ll rhs[200000];

void solve() {
  int n;
  cin >> n >> total;
  ll amt = 0;
  for(int i = 0; i < n; i++) cin >> lhs[i] >> rhs[i];
  for(int i = 0; i < n; i++) amt += rhs[i];
  if(amt > total) {
    cout << "-1\n";
    return;
  }
  amt = 0;
  for(int i = 0; i < n; i++) amt += lhs[i];
  vector<ll> diff;
  for(int i = 0; i < n; i++) diff.push_back(lhs[i] - rhs[i]);
  sort(diff.begin(), diff.end());
  reverse(diff.begin(), diff.end());
  int ret = 0;
  for(ll out: diff) {
    if(amt <= total) break;
    ret++;
    amt -= out;
  }
  cout << ret << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL); cerr.tie(NULL);
  solve();
}