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


template<class I>
I bs(I a, I b, auto&& f) {
  assert(a < b);
  while(a + 1 < b) {
    I q = a + (b - a)/2;
    (f(q) ? b : a) = q;
  }
  return b;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int l, n;
  cin >> l >> n;
  vi a(n);
  rep(i,0,n) cin>>a[i];

  auto longest = [&](int q) {
    int lst = 0;
    rep(i,0,n) {
      if(a[i] <= lst + q) lst = min(a[i],lst) + q;
      else return false;
    }
    return lst >= l;
  };

  auto shortest = [&](int q) {
    int lst = 0;
    rep(i,0,n) {
      if(a[i] >= lst) lst = max(a[i],lst+q);
      else return true;
    }
    return false;
  };

  int MAX = bs<int>(0,l+1, longest);
  int MIN = bs<int>(0,l+1, shortest) - 1;
  debug(MIN,MAX);

  vi lo(n+1), hi(n+1);
  lo[0] = hi[0] = 0;
  rep(i,0,n) {
    lo[i+1] = max(lo[i] + MIN, a[i]);
    hi[i+1] = min(hi[i] + MAX, i+1 < n ? a[i+1] : l);
  }
  assert(lo[n] <= l && l <= hi[n]);
  debug(lo);
  debug(hi);

  auto isec = [&](int a, int b, int l, int r) {
    if(l <= a && a <= r) return a;
    if(l <= b && b <= r) return b;
    if(a <= l && l <= b) return l;
    if(a <= r && r <= b) return r;
    assert(false);
  };

  vi ans(n+1);
  ans[n] = l;
  for(int i = n; i--;) {
    int a = ans[i+1]-MAX, b = ans[i+1]-MIN;
    ans[i] = isec(ans[i+1]-MAX, ans[i+1]-MIN, lo[i], hi[i]);
  }

  rep(i,0,n) cout << ans[i] << " " << ans[i+1] << "\n";
}