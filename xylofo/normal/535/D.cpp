#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


vi Z(const string &s) {
  int n = sz(s), l = 0, r = 0;
  vi z(n);
  rep(i,1,n) {
    if (i <= r) z[i] = min(r - i + 1, z[i-l]);
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
    if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
  }
  return z;
}

const ll mod = 1000000007;
ll modpow(ll a, ll e) {
  if (e == 0) return 1;
  ll x = modpow(a * a % mod, e >> 1);
  return e & 1 ? x * a % mod : x;
}

void answer(ll k) {
  cout << k << endl;
  exit(0);
}

int main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);
  int n,m;
  cin>>n>>m;
  string s;
  cin>>s;
  vi z = Z(s);
  int q = sz(s), lst = -1e9, fill = 0;
  rep(i,0,m) {
    int x;
    cin>>x;
    int y = x-lst;
    if(y < q && y + z[y] < q) answer(0);
    fill += min(y, q);
    lst = x;
  }
  assert(fill <= n);
  ll ans = modpow(26, n-fill);
  answer(ans);
}