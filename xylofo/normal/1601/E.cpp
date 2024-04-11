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

template<class T>
struct RMQ {
  vector<vector<T>> jmp;
  RMQ(const vector<T>& V) : jmp(1, V) {
    for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k) {
      jmp.emplace_back(sz(V) - pw * 2 + 1);
      rep(j,0,sz(jmp[k]))
        jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
    }
  }
  T query(int a, int b) {
    assert(a < b); // or return inf if a == b
    int dep = 31 - __builtin_clz(b - a);
    return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, q, k;
  cin >> n >> q >> k;
  vi a(n);
  rep(i,0,n) cin>>a[i];

  RMQ<int> rmq(a);


  vector<ll> ans(q,-1);
  vector<ll> ans2(q,0);
  vi query_r(q);
  vector<vi> at_l(n);
  rep(i,0,q) {
    int l, r;
    cin >> l >> r;
    --l;
    query_r[i] = r;
    at_l[l].emplace_back(i);
  }

  auto f = [&](int sz) { return (sz+k-1)/k; };

  // ans to [l,r) is min(a_l,a_{l+0k}) + min(a_l, a_{l+k}) + min(a_l, a_{l+2k}) ...
  rep(off,0,k) {
    deque<tuple<int,ll,ll>> ivals; // [endpos, val, suffsum]
    ivals.emplace_front(n+100,0,0);
    for(int x = n-1-off; x >= 0; x -= k) {
      ll nmin = rmq.query(x,min(x+k,n));
      int endpos = -1;
      while(get<1>(ivals.front()) >= nmin) {
        auto [ep, val, suff] = ivals.front();
        endpos = ep;
        ivals.pop_front();
      }
      if(endpos != -1) {
        auto [ep, val, suff] = ivals.front();
        ll nsuff = suff + val*f(ep-endpos);
        ivals.emplace_front(endpos, nmin, nsuff);
      }
      if(a[x] != nmin || endpos == -1) {
        assert(a[x] >= nmin);
        endpos = x+1;
        auto [ep, val, suff] = ivals.front();
        ll nsuff = suff + val*f(ep-endpos);
        ivals.emplace_front(endpos, a[x], nsuff);
      }

      ll tot_sum = 0;
      {
        auto [ep, val, suff] = ivals.front();
        tot_sum = suff + val*f(ep-x);
      }

      for(auto qi : at_l[x]) {
        int r = query_r[qi];
        auto it = upper_bound(all(ivals), make_tuple(r,-1,-1));
        assert(it != end(ivals));
        auto [ep, val, suff] = *it;
        ll after = suff + val*f(ep-r);
        ans[qi] = tot_sum - after;
      }
    }
  }

  rep(i,0,q) cout << ans[i] << "\n";
}