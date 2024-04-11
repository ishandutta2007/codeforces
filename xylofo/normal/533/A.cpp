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


struct T {
  ll delta = 0;
  ll mn = 0;
};
T f(T a, T b) { return {a.delta + b.delta, min(a.mn+b.delta, b.mn)}; };
constexpr T unit;

struct Tree {
  vector<T> s; int n;
  Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}

  void update(int pos, int delta) {
    pos += n;
    s[pos].delta += delta;
    s[pos].mn += delta;
    for (; pos /= 2;)
      s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
  }
  T query(int b, int e) { // query [b, e)
    T ra = unit, rb = unit;
    for (b += n, e += n; b < e; b /= 2, e /= 2) {
      if (b % 2) ra = f(ra, s[b++]);
      if (e % 2) rb = f(s[--e], rb);
    }
    return f(ra, rb);
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, k;
  cin >> n;
  vi h(n);
  rep(i,0,n) cin >> h[i];
  vector<vi> g(n);
  rep(i,1,n) {
    int x,y;
    cin>>x>>y;
    --x,--y;
    g[x].emplace_back(y);
    g[y].emplace_back(x);
  }
  cin >> k;
  vi s(k);
  rep(i,0,k) cin >> s[i];
  sort(all(s));

  /*
     multiset<int> active;
     auto ins = [&](int x) {
     active.emplace(x);
     };
     auto rem = [&](int x) {
     active.erase(active.find(x));
     };
     auto query_ok = [&]() -> bool {
     auto a = active;
     for(int x : s) {
     auto it = a.lower_bound(x);
     if(it == end(a)) return false;
     a.erase(it);
     }
     return true;
     };
     */


  const int inf = 1e9+10;
  vi xs = s;
  xs.emplace_back(inf+10);
  xs.emplace_back(0);
  sort(all(xs));
  xs.erase(unique(all(xs)), end(xs));
  auto compress = [&](int x) {
    return upper_bound(all(xs), x) - begin(xs) - 1;
  };

  Tree st(sz(xs));
  rep(i,0,k) st.update(compress(s[i]),-1);

  auto ins = [&](int x) {
    st.update(compress(x),+1);
  };
  auto rem = [&](int x) {
    st.update(compress(x),-1);
  };
  auto query_ok = [&]() -> bool {
    return st.query(0,sz(xs)).mn >= 0;
  };

  vector<vi> bag(n);
  vi val(n), val2(n);
  function<void(int,int,int,int,int)> dfs =
    [&](int x, int p, int mn, int mn_v, int snd_mn) {
      if(h[x] < mn) {
        snd_mn = mn;
        mn = h[x], mn_v = x;
      }
      else if(h[x] < snd_mn) snd_mn = h[x];
      val[x] = mn;
      val2[x] = snd_mn;
      ins(val[x]);
      bag[mn_v].emplace_back(x);
      for(int y : g[x]) if(y != p) {
        dfs(y,x,mn,mn_v,snd_mn);
      }
    };
  dfs(0,-1,inf,-1,inf);

  if(query_ok()) {
    cout << 0 << endl;
    exit(0);
  }

  ll ans = 1e18;

  rep(rt,0,n) {
    for(int x : bag[rt]) rem(val[x]);

    auto f = [&](int q){
      for(int x : bag[rt]) ins(min(q,val2[x]));
      bool ok = query_ok();
      for(int x : bag[rt]) rem(min(q,val2[x]));
      return ok;
    };

    int l = -1, r = k;
    while(l+1 != r) {
      int mid = (l+r)/2;
      if(f(s[mid])) r = mid;
      else l = mid;
    }

    if(r < k) {
      int q = s[r];
      assert(q > h[rt]);
      ans = min<ll>(ans, q-h[rt]);
    }

    for(int x : bag[rt]) ins(val[x]);
  }

  if(ans == 1e18) ans = -1;
  cout << ans << endl;
}