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


struct UF {
  vi e;
  UF(int n) : e(n, -1) {}
  bool sameSet(int a, int b) { return find(a) == find(b); }
  int size(int x) { return -e[find(x)]; }
  int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
  bool join(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return false;
    if (e[a] > e[b]) swap(a, b);
    e[a] += e[b]; e[b] = a;
    return true;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, m;
  cin >> n >> m;
  vector<tuple<int,int,int>> ed(m);
  for(auto& [w,x,y] : ed) {
    cin>>x>>y>>w;
    --x,--y;
    //x = rand()%n;
    //y = rand()%n;
    //w = 1e8;
  }
  sort(all(ed));

  auto query = [&](int x) {
    UF uf(n);
    int r = upper_bound(all(ed),make_tuple(x,0,0))-begin(ed);
    int l = r;
    ll ans = 0;
    int cmp = n;

    int cr = 1e9, cl = 1e9;
    if(r != m) cr = get<0>(ed[r])-x;
    if(l != 0) cl = x-get<0>(ed[l-1]);

    int below = 0;
    int above = 0;

    vi vals;

    while(cmp != 1) {
      if(cl < cr) {
        --l;
        if(uf.join(get<1>(ed[l]), get<2>(ed[l]))) {
          ans += cl, --cmp, ++below;
          vals.emplace_back(get<0>(ed[l]));
        }
        if(l != 0) cl = x-get<0>(ed[l-1]);
        else cl = 1e9;
      }
      else {
        if(uf.join(get<1>(ed[r]), get<2>(ed[r]))) {
          ans += cr, --cmp, ++above;
          vals.emplace_back(get<0>(ed[r]));
        }
        ++r;
        if(r != m) cr = get<0>(ed[r])-x;
        else cr = 1e9;
      }
    }
    assert(cmp == 1);
    sort(all(vals));
    vector<ll> pref(sz(vals)+1);
    rep(i,0,sz(vals)) pref[i+1] = pref[i]+vals[i];
    return make_pair(vals,pref);
  };

  vi events;
  rep(i,0,m) rep(j,0,i) {
    events.emplace_back((get<0>(ed[i]) + get<0>(ed[j]))/2);
    events.emplace_back((get<0>(ed[i]) + get<0>(ed[j]))/2+1);
  }
  events.emplace_back(-2);
  events.emplace_back(1e9);
  sort(all(events));
  events.erase(unique(all(events)), end(events));
  vector<tuple<vi,vector<ll>>> anss;
  for(int x : events) {
    anss.emplace_back(query(x));
  }

  auto q2 = [&](ll x) {
    int i = upper_bound(all(events),x)-begin(events)-1;
    assert(i >= 0);
    const auto& [vals,pref] = anss[i];
    int below = upper_bound(all(vals),x)-begin(vals);
    int above = n-1-below;
    ll res = 0;
    res += below * x - pref[below];
    res += pref.back()-pref[below] - above * x;
    return res;
  };

  debug(events);
  debug(anss);

  int p, k, a, b, c;
  cin>>p>>k>>a>>b>>c;
  int lst = 0;
  ll xans = 0;
  rep(i,0,k) {
    int q = (lst*1LL*a+b)%c;
    if(i < p) cin>>q;
    ll res = q2(q);
    xans ^= res;
    //if(i <= 100) debug(res);
    lst = q;
    //cout << res << "\n";
  }
  cout << xans << endl;
}