#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define debug(...) //ignore
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;

using L = __int128_t;

void solve() {
  ll n;
  cin>>n;
  auto check = [&](L k) {
    if(k < 2) return false;
    L q = k*(k+1)/2;
    return (n >= q) && (n%k == q%k);
  };

  for(L pw2 = 2; pw2 <= L(n)*16; pw2 *= 2) if(check(pw2)) {
    cout << ll(pw2) << "\n";
    return;
  }

  ll odd = n;
  while(odd%2 == 0) odd /= 2;
  if(check(odd)) {
    cout << odd << "\n";
    return;
  }

  assert(odd == 1);
  cout << -1 << "\n";
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int T;
  cin>>T;
  rep(i,0,T) solve();
}