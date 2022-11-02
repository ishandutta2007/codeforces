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
//const int mod = ;

vi p, sz, in, out;
vvi g;
int TIME = 0;

void dfs(int v) {
  ++TIME;
  in[v] = TIME;
  sz[v] = 1;
  for (int nv : g[v]) {
    dfs(nv);
    sz[v] += sz[nv];
  }
  out[v] = TIME;
//  cerr << "dfs: " << v + 1 << ' ' << in[v] << ' ' << out[v] << endl;
}

int getp(int v) {
  if (p[v] == v) return v;
  return p[v] = getp(p[v]);
}

int join(int a, int b) {
  a = getp(a);
  b = getp(b);
  if (a == b) return -1;
  p[a] = b;
  g[b].push_back(a);
  return b;
}

const int N = 1 << 18;
pii ma[2 * N];

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n, m, Q;
  cin >> n >> m >> Q;
  vi a(n);
  p.resize(n);
  g.resize(n);
  sz.assign(n, 0);
  in.assign(n, 0);
  out.assign(n, 0);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    p[i] = i;
  }
  vector<array<int, 2>> e(m);
  for (int i = 0; i < m; ++i) {
    cin >> e[i][0] >> e[i][1];
    --e[i][0];
    --e[i][1];
  }
  vi del(m);
  vector<array<int, 2>> q(Q);
  for (int i = 0; i < Q; ++i) {
    cin >> q[i][0] >> q[i][1];
    --q[i][1];
    if (q[i][0] == 2) del[q[i][1]] = 1;
  }
  for (int i = 0; i < m; ++i) if (!del[i]) join(e[i][0], e[i][1]);
  for (int i = Q - 1; i >= 0; --i) {
    if (q[i][0] == 1) {
      q[i][1] = getp(q[i][1]);
    } else {
      q[i][1] = join(e[q[i][1]][0], e[q[i][1]][1]);
    }
  }
  for (int i = 0; i < n; ++i) if (p[i] == i) dfs(i);
  for (int i = N; i < 2 * N; ++i) ma[i] = pii(-1, i - N);
  for (int i = 0; i < n; ++i) {
    ma[in[i] + N].first = a[i];
  }
  for (int i = N - 1; i > 0; --i) ma[i] = max(ma[2 * i], ma[2 * i + 1]);
  for (int t = 0; t < Q; ++t) {
    int v = q[t][1];
    if (q[t][0] == 1) {
      int l = in[v] + N, r = out[v] + N;
      pii best(0, in[v]);
      while (l <= r) {
        if (l & 1) {
          best = max(best, ma[l]);
          ++l;
        }
        if (!(r & 1)) {
          best = max(best, ma[r]);
          --r;
        }
        l /= 2;
        r /= 2;
      }
      int u = best.second;
//      cerr << v + 1 << ' ' << in[v] << ' ' << out[v] << ' ' << u << ' ';
      cout << best.first << '\n';
      int x = u + N;
      ma[x].first = 0;
      while (x > 1) {
        x /= 2;
        ma[x] = max(ma[2 * x], ma[2 * x + 1]);
      }
    } else if (v >= 0) {
      assert(!g[v].empty());
      out[v] -= sz[g[v].back()];
//      cerr << v + 1 << ' ' << out[v] << endl;
      g[v].pop_back();
    }
  }
  return 0;
}