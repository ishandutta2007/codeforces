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
const int mod = 1e9 + 7;

vector<vii> g;
vi neig, was, xr, in;
vi tmp;
vvi dim;
int TIME = 0;

void dfs(int v, int pr) {
  in[v] = TIME++;
  for (pii p : g[v]) if (p.first != pr && !neig[p.first] && p.first) {
    if (was[p.first]) {
      if (in[v] < in[p.first]) tmp.push_back(p.second ^ xr[v] ^ xr[p.first]);
//      cerr << v+1 << ' ' << p.first+1 << ' ' << tmp.back() << endl;
    } else {
      was[p.first] = 1;
      xr[p.first] = p.second ^ xr[v];
      dfs(p.first, v);
    }
  }
}

void norm(vi& v) {
  if (v.empty()) return;
  if (v.size() > 5) {
    v.assign(1, 0);
    return;
  }
  for (int x : v) if (x == 0) {
    v.assign(1, 0);
    return;
  }
  int it = 0;
  for (int b = 16; b >= 1 && it < v.size(); b /= 2) {
    for (int i = it; i < v.size(); ++i) if (v[i] & b) {
      swap(v[i], v[it]);
      break;
    }
    if (v[it] & b) {
      for (int i = 0; i < v.size(); ++i) if (i != it && (v[i] & b)) {
        v[i] ^= v[it];
      }
      ++it;
    }
  }
  if (v.back() == 0) {
    v.assign(1, 0);
    return;
  }
}

const int N = 400;
int calced[N][N];
int prec[N][N];
map<vi, int> ind;
vvi invind;

int getind(const vi& v) {
  if (ind.count(v)) return ind[v];
  int sz = ind.size();
  ind[v] = sz;
  invind.push_back(v);
  return sz;
}

vi prod(vi a, vi b) {
  if (a > b) swap(a, b);
  for (int x : a) b.push_back(x);
  norm(b);
  return b;
}

int prod(int a, int b) {
  if (a > b) swap(a, b);
  if (calced[a][b]) return prec[a][b];
  prec[a][b] = getind(prod(invind[a], invind[b]));
  calced[a][b] = 1;
  return prec[a][b];
}

void out(vi v) {
  for (int x : v) cerr << x << ' ';
  cerr << endl;
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, m;
  cin >> n >> m;
  g.resize(n);
  for (int i = 0; i < m; ++i) {
    int a,b,w;
    cin >> a >> b >> w;
    --a; --b;
    g[a].emplace_back(b, w);
    g[b].emplace_back(a, w);
  }
  was.assign(n, 0);
  neig.assign(n, 0);
  dim.resize(n);
  xr.assign(n, 0);
  in.assign(n, 0);
  was[0] = 1;
  vi up(n);
  for (pii p : g[0]) {
    was[p.first] = neig[p.first] = 1;
    up[p.first] = p.second;
  }
  for (pii p : g[0]) {
    tmp.clear();
    dfs(p.first, 0);
//    cerr << p.first + 1 << endl;
//    out(tmp);
    norm(tmp);
    dim[p.first] = tmp;
//    out(tmp);
  }
/*  for (int a1 = 0; a1 < 32; ++a1) {
    getind({a1});
    for (int a2 = 0; a2 < 32; ++a2) {
      getind({a1, a2});
      for (int a3 = 0; a3 < 32; ++a3) {
        getind({a1, a2, a3});
        for (int a4 = 0; a4 < 32; ++a4) {
          getind({a1, a2, a3, a4});
        }
      }
    }
  }
  cerr << ind.size() << endl;*/
  vi used(n);
  vi d(N);
  d[getind(vi())] = 1;
  for (pii p : g[0]) if (!used[p.first]) {
    used[p.first] = 1;
    vi nd = d;
    bool one = true;
    for (pii q : g[p.first]) {
      if (neig[q.first]) {
        one = false;
        vi sd = prod(dim[p.first], dim[q.first]);
        vi ssd = prod(sd, vi(1, up[p.first] ^ up[q.first] ^ q.second));
        int j1 = getind(sd);
        int j2 = getind(ssd);
        for (int i = 0; i < d.size(); ++i) if (d[i]) {
          int v = prod(i, j1);
          nd[v] = (nd[v] + 2LL * d[i]) % mod;
          v = prod(i, j2);
          nd[v] = (nd[v] + d[i]) % mod;
        }
        used[q.first] = 1;
        break;
      }
    }
    if (one) {
      int j = getind(dim[p.first]);
      for (int i = 0; i < d.size(); ++i) if (d[i]) {
        int v = prod(i, j);
        nd[v] = (nd[v] + d[i]) % mod;
      }
    }
    d.swap(nd);
  }
  ll res = 0; 
  for (int i = 0; i < d.size(); ++i) if (d[i]) {
    vi v = invind[i];
    if (v.empty() || v[0]) res += d[i];
  }
  cout << res % mod << endl;
  return 0;
}