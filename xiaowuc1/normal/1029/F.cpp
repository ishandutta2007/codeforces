#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ll a, b;
vector<ll> aF, bF;

bool valid(ll x, vector<ll>& f, ll i, ll j) {
  int lhs = 0;
  int rhs = f.size()-1;
  while(lhs < rhs) {
    ll mid = (lhs+rhs+1)/2;
    if(f[mid] > i) rhs = mid-1;
    else lhs = mid;
  }
  ll other = x / f[lhs];
  return other <= j;
}

void init(ll x, vector<ll>& f) {
  for(ll i = 1; i * i <= x; i++) {
    if(x%i==0) {
      f.push_back(i);
      f.push_back(x/i);
    }
  }
  sort(f.begin(), f.end());
}

void solve() {
  cin >> a >> b;
  init(a, aF);
  init(b, bF);
  ll total = a+b;
  ll ret = 1e18;
  for(ll i = 1; i * i <= total; i++) {
    if(total%i) continue;
    ll j = total / i;
    if(valid(a, aF, i, j) || valid(b, bF, i, j)) {
      ret = min(ret, 2*(i+j));
    }
  }
  cout << ret << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL); cerr.tie(NULL);
  solve();
}