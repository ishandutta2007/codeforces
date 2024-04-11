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

vvi g, gr;
vi in, out, bad;
int TIME = 1;
bool fail = 0;

void dfs(int v) {
  in[v] = TIME++;
  for (int nv : g[v]) {
    if (in[nv] == -1) dfs(nv);
    else if (out[nv] != -1 || in[nv] >= in[v]) fail = 1;
  }
  out[v] = TIME++;
}

int dfs1(int v) {
  int sum = 0;
  for (int nv : g[v]) {
    if (in[nv] > in[v]) {
      sum += dfs1(nv);
    } else {
      ++sum;
    }
  }
  for (int nv : gr[v]) {
    if (in[nv] > in[v]) {// && out[nv] < out[v]) {
      --sum;
    }
  }
  if (sum > 1) bad[v] = 2;
  return sum;
}

void dfs2(int v) {
  for (int nv : g[v]) {
    if (in[nv] < in[v] && bad[nv]) bad[v] = 1;
  }
  for (int nv : g[v]) {
    if (in[nv] > in[v]) {
      dfs2(nv);
    } 
  }
}

int main() {
  srand(1248763287464875648561874671354547312453244LL);
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int T;
  cin >> T;
  for (int test = 1; test <= T; ++test) {
    int n, m;
    cin >> n >> m;
    g.assign(n, vi());
    gr.assign(n, vi());
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      if (a == b) continue;
      --a; --b;
      g[a].push_back(b);
      gr[b].push_back(a);
    }
    vi ord(n);
    for (int i = 0; i < n; ++i) ord[i] = i;
    random_shuffle(ord.begin(), ord.end());
    vi ans;
    for (int i = 0; i < min((int)ord.size(), 100); ++i) {
      in.assign(n, -1);
      out.assign(n, -1);
      fail = 0;
      dfs(i);
      if (!fail) {
        bad.assign(n, 0);
        dfs1(i);
//        dfs2(i);
//        for (int v = 0; v < n; ++v) for (int nv : g[v]) if (in[nv] < in[v] && bad[nv]) bad[v] = 1;
        vii ts;
        for (int i = 0; i < n; ++i) if (bad[i]) ts.emplace_back(in[i], i);
        sort(ts.begin(), ts.end());
        for (pii p : ts) {
          vi q(1, p.second);
          bad[q[0]] = 1;
          int it = 0;
          while (it < q.size()) {
            int v = q[it++];
//            cerr << p.second + 1 << ' ' << v + 1 << endl;
            for (int nv : gr[v]) if (in[nv] > p.first && bad[nv] != 1) {
              bad[nv] = 1;
              q.push_back(nv);
            }
          }
        }
        assert(!bad[i]);
        for (int j = 0; j < n; ++j) if (!bad[j]) ans.push_back(j);
        break;
      }
    }
    if (ans.size() * 5 < n) {
      cout << -1 << '\n';
    } else {
//      cout << ans.size() << '\n';
      sort(ans.begin(), ans.end());
      for (int x : ans) cout << x + 1 << ' ';
      cout << '\n';
    }
  }
  return 0;
}