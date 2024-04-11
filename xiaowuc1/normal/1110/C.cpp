#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

/*
int slow(int n) {
  int ret = 0;
  vector<int> v;
  for(int i = 1; i < n; i++) {
    int cand = __gcd(n&i, n^i);
    if(cand > ret) {
      v.clear();
      ret = cand;
    }
    if(cand == ret) {
      v.push_back(i);
    }
  }
  cout << n << ": " << ret << " with";
  for(int out: v) cout << " " << out;
  cout << endl;
  return ret;
}
*/

int fast(int n) {
  if((n&(n+1)) == 0) {
    for(int i = 2; i * i <= n; i++) {
      if(n%i==0) return n / i;
    }
    return 1;
  }
  int mask = 1;
  while(mask < n) mask |= mask << 1;
  return mask;
}

void solve() {
  int n;
  cin >> n;
  cout << fast(n) << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int q;
  cin >> q;
  while(q--) solve();
}