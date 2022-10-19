#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define dbg(x) cerr << #x << " = " << x << endl
#define _ << " " <<
#define X first
#define Y second
using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MXN = 200005;

int a[MXN], b[MXN];
int pa[MXN], pb[MXN];

vector<pii> tree[MXN];
vector<pii> ttmp[MXN];
vector<int> csum[MXN];

void upd(int x, pii p) {
  for (; x; x -= x & -x)
    ttmp[x].push_back(p);
}
int get(int x, int l, int r) {
  int ret = 0;
  for (; x < MXN; x += x & -x) {
    for (pii p : ttmp[x]) if (l <= p.X && p.X <= r) ret += p.Y;
    int lit = lower_bound(all(tree[x]), pii{l, -2}) - begin(tree[x]);
    int rit = upper_bound(all(tree[x]), pii{r, +2}) - begin(tree[x]);
    if (lit != tree[x].size()) ret += csum[x][lit];
    if (rit != tree[x].size()) ret -= csum[x][rit];
  }
  return ret;
}

void rebuild() {
  for (int i = 1; i < MXN; ++i) {
    if (ttmp[i].empty()) continue;
    sort(all(ttmp[i]));
    vector<pii> tmp(ttmp[i].size() + tree[i].size());
    merge(all(tree[i]), all(ttmp[i]), begin(tmp));
    csum[i].resize(tmp.size());
    csum[i].back() = tmp.back().Y;
    for (int j = tmp.size() - 2; j >= 0; --j) {
      csum[i][j] = tmp[j].Y + csum[i][j + 1];
    }
    swap(tree[i], tmp);
    ttmp[i].clear();
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  int n, m; cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i]; pa[a[i]] = i;
  }
  for (int i = 1; i <= n; ++i) {
    cin >> b[i]; pb[b[i]] = i;
    upd(pa[b[i]], {i, 1});
  }
  rebuild();
  for (int i = 1; i <= m; ++i) {
    int t; cin >> t;
    if (t == 1) {
      int la, ra, lb, rb;
      cin >> la >> ra >> lb >> rb;
      cout << get(la, lb, rb) - get(ra + 1, lb, rb) << '\n';
    } else {
      int x, y;
      cin >> x >> y;
      upd(pa[b[x]], {x, -1});
      upd(pa[b[y]], {y, -1});
      swap(b[x], b[y]);
      upd(pa[b[x]], {x, +1});
      upd(pa[b[y]], {y, +1});
    }
    if (i % 600 == 0) rebuild();
  }
}