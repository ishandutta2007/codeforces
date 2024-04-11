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

const int N = 3e5 + 10;
int p[N], sz[N];

int find(int v) {
  return p[v] == v ? v : p[v] = find(p[v]);
}

bool merge(int a, int b) {
  a = find(a), b = find(b);
  if (a == b) {
    return false;
  }
  if (sz[a] < sz[b]) {
    swap(a, b);
  }
  p[b] = a;
  sz[a] += sz[b];
  return true;
}

int a[N], b[N];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }  
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
  }
  for (int i = 1; i <= n + m; i++) {
    p[i] = i;
    sz[i] = 1;
  }
  int all_sum = 0;
  vector<pair<int, pair<int, int>>> edges;
  for (int st = 1; st <= n; st++) {
    int cnt;
    cin >> cnt;
    for (int i = 0; i < cnt; i++) {
      int x;
      cin >> x;
      all_sum += a[st] + b[x];
      edges.pb(make_pair(-1 * (a[st] + b[x]), make_pair(st, n + x)));
    }
  }
  sort(all(edges));
  for (auto it : edges) {
    if (merge(it.S.F, it.S.S)) {
      all_sum += it.F;
    }
  }
  cout << all_sum << '\n';
}