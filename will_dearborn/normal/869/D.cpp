#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<double, double> pdd;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
const int mod = 1000000007;

ll n, m;

int lca(int x, int y) {
  while (x != y) {
    if (x < y) swap(x, y);
    x /= 2;
  }
  return x;
}

pii norm(pii p) {
  if (p.first > p.second) swap(p.first, p.second);
  return p;
}

vii get_path(pii p) {
  int c = lca(p.first, p.second);
  if (c == p.first || c == p.second) return vii(1, norm(p));
  vii v(2, p);
  v[0].first = c;
  v[1].second = c;
  v[0] = norm(v[0]);
  v[1] = norm(v[1]);
  return v;
}

void add_path(vii & v, pii p) {
  vii x = get_path(p);
  for (pii t : x) v.push_back(t);
}

vi up(int a, int b) {
  vi v;
  while (a != b) {
    v.push_back(a);
    a /= 2;
  }
  return v;
}

const int DEBUG = 1;

bool intersect(pii a, pii b) {
  a = norm(a); b = norm(b);
  if (a.first < b.first) swap(a, b);
  bool res = false;
  if (lca(a.first, b.second) == a.first && lca(a.first, b.first) == b.first) res = true;
  if (0 && DEBUG) {
    assert(lca(a.second, a.first) == a.first);
    assert(lca(b.second, b.first) == b.first);
    vi p1 = up(a.second, a.first); p1.push_back(a.first);
    sort(p1.begin(), p1.end());
    vi p2 = up(b.second, b.first); p2.push_back(b.first);
    bool was = 0;
    for (int x : p2) if (binary_search(p1.begin(), p1.end(), x)) was = 1;
    assert(was == res);
  }
  return res;
}

bool intersect(const vii& v, pii a) {
  for (pii x : v) if (intersect(x, a)) return true;
  return false;
}

bool intersect(const vii & a, const vii & b) {
  for (pii x : a) for (pii y : b) if (intersect(x, y)) return true;
  return false;
}

ll get_size(int v) {
  assert(v >= 1 && v <= n);
  ll l = v, r = v, res = 0;
  while (l <= n) {
    res += min(r, n) - l + 1;
    l *= 2;
    r = 2 * r + 1;
  }
  if (0 && DEBUG) {
    ll c = 0;
    for (int i = 1; i <= n; ++i) if (lca(i, v) == v) ++c;
    assert(c == res);
  }
  return res;
}

ll subtree(int v, const vii & used) {
  assert(v);
  ll res = get_size(v);
  vi u;
  for (pii p : used) {
    if (lca(p.first, v) == v && p.first != v) {
      u.push_back(p.first);
    } else if (lca(v, p.second) == v && p.second != v) {
      int t = p.second;
      while (t / 2 != v) t /= 2;
      u.push_back(t);
    }
  }
  sort(u.begin(), u.end());
  u.resize(unique(u.begin(), u.end()) - u.begin());
  for (int i : u) {
    assert(lca(i, v) == v && i != v);
    bool ok = 1;
    for (int j : u) if (i != j && lca(i, j) == j) {ok = 0; break;}
    if (ok) res -= get_size(i);
  }
  assert(res >= 1);
  if (0 && DEBUG) {
    ll c = 1;
    for (int i = 1; i <= n; ++i) {
      if (lca(i, v) == v && i != v) {
        int t = i;
        while (t / 2 != v) t /= 2;
        if (!intersect(used, get_path(pii(t, i)))) ++c;
      }
    }
    assert(c == res);
  }
  return res % mod;
}

int neig(int v, int i) {
  assert(v != i);
  if (lca(i, v) == v) {
    int t = i;
    while (t / 2 != v) t /= 2;
    return t;
  } else {
    assert(v != 1);
    return v / 2;
  }
}

ll calc(int v, vii used) {
  assert(v);
  int v0 = v;
  ll res = 0;
  vii used0 = used;
  while (1) {
    res += subtree(v, used);
    v /= 2;
    if (!v) break;
    if (intersect(used, pii(v, v))) break;
    used.push_back(pii(v, v));
  }
  if (0 && DEBUG) {
    ll c = 1;
    for (int i = 1; i <= n; ++i) if (i != v0) {
      if (lca(i, v0) == v0) {
        int t = i;
        while (t / 2 != v0) t /= 2;
        if (!intersect(used0, get_path(pii(t, i)))) ++c;
      } else {
        assert(v0 != 1);
        int t = v0 / 2;
        if (!intersect(used0, get_path(pii(t, i)))) ++c;
      }
    }
//    cerr << c << ' ' << res << endl;
    //return c;
    assert(c == res);
  }
//  cerr << "calc: " << v0 << ' ' << res << endl; for (pii p : used) cerr << p.first << "," << p.second << ' '; cerr << endl;
//  assert(0);
  return res % mod;
}

ll solve(int b, int e, const vii & used) {
  assert(b != e);
  int c = lca(b, e);
  vi p1 = up(b, c), p2 = up(e, c);
  vi p = p1;
  p.push_back(c);
  reverse(p2.begin(), p2.end());
  for (auto x : p2) p.push_back(x);
  assert(p.size() >= 2 && p[0] == b && p.back() == e);
//  for (int i = 0; i < p.size(); ++i) for (int j = i + 1; j < p.size(); ++j) assert(p[i] != p[j]);
  ll res = 0;
  for (int i = 1; i < (int)p.size(); ++i) {
    vii add = (i != 1) ? get_path(pii(p[1], p[i-1])) : vii(0);
    if (intersect(used, add)) break;
    for (int j = i-1; j+1 < (int)p.size(); ++j) {
      vii add1 = (j+3 <= (int)p.size()) ? get_path(pii(p[j+1], p[p.size()-2])) : vii(0);
      if (intersect(used, add1)) continue;
      assert(!intersect(add, add1));
      vii u = used;
      add_path(u, pii(b, e));
      res = (res + calc(p[i-1], u) * calc(p[j+1], u)) % mod;
    }
  }
  if (0 && DEBUG) {
    ll s = 0;
    for (int i = 1; i <= n; ++i) {
      vii u = used;
      if (i != b) {
        int t = neig(b, i);
        if (intersect(used, get_path(pii(t, i)))) continue;
        add_path(u, pii(t, i));
      }
      for (int j = 1; j <= n; ++j) {
        if (j != e) {
          int t = neig(e, j);
          if (intersect(u, get_path(pii(t, j)))) continue;
        }
        ++s;
      }
    }
//    cerr << s << ' ' << res << endl;
    assert(s % mod == res);
  }
//  cerr << "solve: " << b << ' ' << e << ' ' << res << endl; for (pii p : used) cerr << p.first << "," << p.second << ' '; cerr << endl; for (int x : p) cerr << x << ' '; cerr << endl;
  return res % mod;
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  cin >> n >> m;
  vii v(m);
  for (int i = 0; i < m; ++i) {
    cin >> v[i].first >> v[i].second; 
  }
  ll res = n * n % mod;
//  cerr << get_size(1) << ' ' << get_size(2) << endl;
  for (int mask = 1; mask < (1 << m); ++mask) {
    vii x;
    for (int i = 0; i < m; ++i) if (mask & (1 << i)) {
      x.push_back(v[i]);
    }
    for (int m1 = 0; m1 < (1 << x.size()); ++m1) {
      vii y = x;
      for (int i = 0; i < (int)x.size(); ++i) if (m1 & (1 << i)) swap(y[i].first, y[i].second);
      vi ord(x.size());
      for (int i = 0; i < (int)ord.size(); ++i) ord[i] = i;
      do {
        vii z = y;
        for (int i = 0; i < (int)ord.size(); ++i) z[i] = y[ord[i]];
        vii used(1);
        used[0] = pii(z[0].first, z[0].first);
        bool ok = z[0].first != z[0].second;
        pii ep(z[0].second, z[0].second);
        for (int i = 1; i < (int)ord.size(); ++i) {
          if (z[i].first != z[i-1].second) {
            vii t = get_path(pii(z[i-1].second, z[i].first));
            if (intersect(used, t)) {
              ok = 0; break;
            }
            for (pii x1 : t) used.push_back(x1);
          } else {
            used.push_back(ep);
          }
          ep = pii(z[i].second, z[i].second);
          if (intersect(used, ep)) {
            ok = 0; break;
          }
        }
        used.push_back(ep);
        if (ok) {
          res = (res + solve(z[0].first, z.back().second, used)) % mod;
        }
      } while (next_permutation(ord.begin(), ord.end()));
    }
  }
  cout << (res % mod + mod) % mod << endl;
  return 0;
}