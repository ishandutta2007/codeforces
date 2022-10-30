#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<ll, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
//typedef long long int;

const int N = 1 << 19;

pii t[2 * N];
ll add[2 * N];

void build (const vl & a, int v, int tl, int tr) {
  if (tl == tr) {
    t[v] = pii(a[tl], tl);
    //    if (t[v]) cerr << "build " << tl << ' ' << tr << ' ' << v << ' ' << t[v] << endl;
  } else {
    int tm = (tl + tr) / 2;
    build (a, v*2, tl, tm);
    build (a, v*2+1, tm+1, tr);
    t[v] = min(t[2*v], t[2*v + 1]);
  }
}

void update (int v, int tl, int tr, int l, int r, ll a) {
  if (l > r)
    return;
  if (l == tl && tr == r) {
    t[v].first += a;
    add[v] += a;
    //    cerr << "add " << l << ' ' << r << ' ' << a << ' ' << v << ' ' << t[v] << endl;
  } else {
    int tm = (tl + tr) / 2;
    add[2 * v] += add[v];
    add[2 * v + 1] += add[v];
    t[2 * v].first += add[v];
    t[2 * v + 1].first += add[v];
    add[v] = 0;
    update (v*2, tl, tm, l, min(r,tm), a);
    update (v*2+1, tm+1, tr, max(l,tm+1), r, a);
    t[v] = min(t[2*v], t[2*v + 1]);
  }
  //  cerr << v << ' ' << t[v] << ' ' << tl << ' ' << tr << endl;
}

pii get_min (int v, int tl, int tr, int l, int r) {
  if (l > r)
    return pii(1e18, -1);
  if (l == tl && tr == r) {
    return t[v];
  } else {
    int tm = (tl + tr) / 2;
    add[2 * v] += add[v];
    add[2 * v + 1] += add[v];
    t[2 * v].first += add[v];
    t[2 * v + 1].first += add[v];
    add[v] = 0;
    return min(get_min(v*2, tl, tm, l, min(r,tm)),
        get_min(v*2+1, tm+1, tr, max(l,tm+1), r) );
  }
}

vi fen;

void fenadd(int i, int val) {
  for (; i < (int)fen.size(); i |= i + 1)
    fen[i] += val;
}

int getsum(int i) {
  int s = 0;
  for (; i >= 0; i = (i & (i + 1)) - 1)
    s += fen[i];
  return s;
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, Q;
  cin >> n >> Q;
  vi a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  vector<array<int, 3>> q(Q);
  vi res(Q);
  for (int i = 0; i < Q; ++i) {
    cin >> q[i][0] >> q[i][1];
    q[i][2] = i;
  }
  sort(q.rbegin(), q.rend());
  build(vl(N, 1e9), 1, 0, N-1);
  fen.assign(n, 0);
  int it = n - 1;
  for (auto x : q) {
    while (it >= x[0]) {
      if (a[it] <= it + 1) {
        int d = it + 1 - a[it];
        pii cur = get_min(1, 0, N-1, it, it);
        assert(cur.second == it);
        update(1, 0, N-1, it, it, d - cur.first);
//        cur = get_min(1, 0, N-1, it, it);
//        assert(cur.first == d);
      }
      --it;
    }
//      auto mi = get_min(1, 0, N-1, 0, n - 1);
//      cerr << mi.first << ' ' << mi.second << endl;
    while (1) {
      auto mi = get_min(1, 0, N-1, 0, n - 1);
      if (mi.first > 0) break;
//      cerr << x[0] << ' ' << mi.first << ' ' << mi.second << endl;
      update(1, 0, N-1, mi.second + 1, n - 1, -1);
      update(1, 0, N-1, mi.second, mi.second, 1e9);
//      cerr << get_min(1, 0, N-1, mi.second, mi.second).first << endl;
      fenadd(n - 1 - mi.second, 1);
    }
    res[x[2]] = getsum(n - 1) - getsum(x[1] - 1);
  }
  //update(1, 0, N-1, out[v], out[v], w - cup[v]);
  //ll res = get_min(1, 0, N-1, in[u], out[u]) - cu + cv;
  for (int i = 0; i < Q; ++i) cout << res[i] << '\n';
  return 0;
}