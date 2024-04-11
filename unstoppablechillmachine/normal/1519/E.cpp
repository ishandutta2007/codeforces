#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back  
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll

int gcd(int a, int b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}

pair<int, int> get(int a, int b, int c, int d) {
  int e = a * d, f = b * c;
  int k = gcd(e, f);
  e /= k;
  f /= k;
  return make_pair(e, f);
}

const int N = 2e5 + 10;
pair<int, int> r[N], up[N];
vector<pair<int, int>> ans;
vector<pair<int, int>> g[2 * N];
bool used[2 * N];
int h[2 * N];

int dfs(int v, int ch = 0) {
  used[v] = true;
  h[v] = ch;
  vector<int> other_edges;
  for (auto u : g[v]) {
    if (!used[u.first]) {
      int id = dfs(u.first, ch + 1);
      if (id) {
        ans.push_back({id, u.second});
      }
      else {
        other_edges.push_back(u.second);
      }
    }
    else if (h[v] < h[u.first]) {
      other_edges.push_back(u.second);
    }
  }  
  for (int i = 0; i + 1 < SZ(other_edges); i += 2) {
    ans.push_back({other_edges[i], other_edges[i + 1]});
  }
  return (SZ(other_edges) % 2 == 1 ? other_edges.back() : 0);
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int n;
  cin >> n;
  vector<pair<int, int>> srt;
  for (int i = 1; i <= n; i++) {
    int xa, xb, ya, yb;
    cin >> xa >> xb >> ya >> yb;
    r[i] = get(xa + xb, xb, ya, yb); 
    up[i] = get(xa, xb, ya + yb, yb);
    srt.pb(r[i]);
    srt.pb(up[i]);
  }  
  sort(all(srt));
  srt.resize(unique(all(srt)) - srt.begin());
  map<pair<int, int>, int> vl;
  for (int i = 0; i < SZ(srt); i++) {
    vl[srt[i]] = i + 1;
  }
  for (int i = 1; i <= n; i++) {
    int v = vl[r[i]], u = vl[up[i]];
    g[u].pb({v, i});
    g[v].pb({u, i});
  }
  for (int i = 1; i <= SZ(srt); i++) {
    if (!used[i]) {
      dfs(i);
    }
  }
  cout << SZ(ans) << '\n';
  for (auto it : ans) {
    cout << it.F << ' ' << it.S << '\n';
  }
}