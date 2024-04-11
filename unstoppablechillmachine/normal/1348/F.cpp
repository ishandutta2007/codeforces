#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll

const int N = 2e5 + 10;
int pos[N], r[N];
pair<int, int> t[4 * N];

void build(int v, int l, int rg) {
  if (l == rg) {
    t[v] = {r[pos[l]], l};
    return;
  }
  int mid = (l + rg) / 2;
  build(2 * v, l, mid);
  build(2 * v + 1, mid + 1, rg);
  t[v] = max(t[2 * v], t[2 * v + 1]);
}

pair<int, int> get_max(int v, int l, int r, int a, int b) {
  if (l > b || r < a) {
    return {0, 0};
  }
  if (l >= a && r <= b) {
    return t[v];
  }
  int mid = (l + r) / 2;
  return max(get_max(2 * v, l, mid, a, b), get_max(2 * v + 1, mid + 1, r, a, b));
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<vector<pair<int, int>>> add(n + 1);
  vector<int> l(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> l[i] >> r[i];
    add[l[i]].pb({r[i], i});
  }
  set<pair<int, int>> cur;
  vector<int> rez(n + 1);
  for (int i = 1; i <= n; i++) {
    for (auto it : add[i]) {
      cur.insert(it);
    }
    assert(!cur.empty());
    assert(cur.begin()->F >= i);
    rez[cur.begin()->S] = i;
    cur.erase(cur.begin());
  }
  for (int i = 1; i <= n; i++) {
    pos[rez[i]] = i;
  }
  build(1, 1, n);
  for (int rval = 2; rval <= n; rval++) {
    int lo = l[pos[rval]];
    pair<int, int> kek = get_max(1, 1, n, lo, rval - 1);
    if (kek.F >= rval) {
      cout << "NO\n";
      for (int i = 1; i <= n; i++) {
        cout << rez[i] << ' ';
      }
      cout << '\n';
      swap(rez[pos[rval]], rez[pos[kek.S]]);
      for (int i = 1; i <= n; i++) {
        cout << rez[i] << ' ';
      }
      cout << '\n';
      exit(0);
    }
  }
  cout << "YES\n";
  for (int i = 1; i <= n; i++) {
    cout << rez[i] << ' ';
  }
  cout << '\n';
}