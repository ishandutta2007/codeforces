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

vvi gr;
string s;
vl ans;
vi rm, sz;
int tmp[1<<20];

void dfs_sz(int v, int p) {
  sz[v] = 1;
  for (int i = 0; i < gr[v].size(); ++i) {
    int nv = gr[v][i];
    if (nv == p || rm[nv]) continue;
    dfs_sz(nv, v);
    sz[v] += sz[nv];
  }
}

int find_center(int v) {
  dfs_sz(v, -1);
  int tot = sz[v], p = -1;
  while (true) {
    bool ok = 1;
    for (int i = 0; i < gr[v].size(); ++i) {
      int nv = gr[v][i];
      if (rm[nv] || nv == p) continue;
      if (sz[nv] > tot/2) {
        ok = 0;
        p = v;
        v = nv;
      }
    }
    if (ok) return v;
  }
}

void dfs(int v, int p, int xr, int add) {
  xr ^= 1 << (s[v] - 'a');
  tmp[xr] += add;
  for (int nv : gr[v]) {
    if (nv == p || rm[nv]) continue;
    dfs(nv, v, xr, add);
  }
}

ll solve(int v, int p, int xr, int xr0) {
  xr ^= 1 << (s[v] - 'a');
  int t = xr ^ xr0;
  ll sum = tmp[t];
  for (int i = 0; i < 20; ++i) sum += tmp[t ^ (1 << i)];
  for (int nv : gr[v]) {
    if (nv == p || rm[nv]) continue;
    sum += solve(nv, v, xr, xr0);
  }
  ans[v] += sum;
  return sum;
}

void push_centroid(int v) {
//  cerr << v+1 << endl; for (int i = 0; i < 64; ++i) assert(tmp[i] == 0);
  dfs(v, -1, 0, 1);
  int xr0 = 1 << (s[v] - 'a');
  ll sum = tmp[0];
  for (int i = 0; i < 20; ++i) {
    sum += tmp[(1 << i)];
  }
  for (int nv : gr[v]) {
    if (rm[nv]) continue;
    dfs(nv, v, xr0, -1);
    sum += solve(nv, v, xr0, xr0);
    dfs(nv, v, xr0, 1);
  }
  assert(sum % 2);
  ans[v] += (sum + 1) / 2;
  dfs(v, -1, 0, -1);
  rm[v] = 1;
  for (int i = 0; i < gr[v].size(); ++i) {
    int nv = gr[v][i];
    if (rm[nv]) {
      continue;
    }
    int c = find_center(nv);
    push_centroid(c);
  }
}

void centroid() {
  int c0 = find_center(0);
  push_centroid(c0);
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n;
  cin >> n;
  gr.resize(n);
  ans.assign(n, 0);
  rm.assign(n, 0);
  sz.assign(n, 0);
  for (int i = 0; i < n-1; ++i) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    gr[a].push_back(b);
    gr[b].push_back(a);
  }
  cin >> s;
  centroid();
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << ' ';
  }
  return 0;
}