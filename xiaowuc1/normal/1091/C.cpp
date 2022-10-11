#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> matrix;

ll gen(int n, int k) {
  // 0, (n/k), (2n/k), ... n*(k-1)/k
  ll scale = n/k;
  // 0, 1, ..., k-1
  ll ret = (k-1LL)*k/2;
  return ret*scale + k;
}

void solve() {
  int n;
  cin >> n;
  set<ll> ret;
  ret.insert(1);
  ret.insert(n*(n+1LL)/2);
  for(int i = 2; i * i <= n; i++) {
    if(n%i) continue;
    ret.insert(gen(n, i));
    ret.insert(gen(n, n/i));
  }
  for(ll out: ret) {
    cout << out << " ";
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cerr.tie(NULL);
  solve();
}