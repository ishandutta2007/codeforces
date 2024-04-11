#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
#define int ll
typedef pair<int, int> pii;
typedef vector<int> vi;


void FST(vi& a, bool inv) {
  for (int n = sz(a), step = 1; step < n; step *= 2) {
    for (int i = 0; i < n; i += 2 * step) rep(j,i,i+step) {
      int &u = a[j], &v = a[j + step]; tie(u, v) =
        pii(u + v, u - v);
    }
  }
  if (inv) trav(x, a) x /= sz(a);
}
vi conv(vi a, vi b) {
  FST(a, 0); FST(b, 0);
  rep(i,0,sz(a)) a[i] *= b[i];
  FST(a, 1); return a;
}

int32_t main() {
  cin.sync_with_stdio(0); cin.tie(0);
  cin.exceptions(cin.failbit);
  int n, m;
  cin >> n >> m;
  const int B = n, N = 1<<B;
  vector<string> s(n);
  rep(i,0,n) cin>>s[i];
  vi cnt(N), pc(N);
  rep(j,0,m) {
    int x = 0;
    rep(i,0,n) x = 2*x + s[i][j]-'0';
    ++cnt[x];
  }
  rep(i,0,N) pc[i] = min(__builtin_popcountll(i), __builtin_popcountll(i^(N-1)));
  auto ans = conv(cnt, pc);
  // ans[i] = sum_{x^y = i} cnt[x] pc[y]

  cout << *min_element(all(ans)) << endl;
}