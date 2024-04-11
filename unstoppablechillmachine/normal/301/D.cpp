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
int t[N];

void upd(int v) {
  for (; v < N; v += v & (-v)) {
    t[v]++;
  }
}

int get(int v) {
  int rez = 0;
  for (; v > 0; v -= v & (-v)) {
    rez += t[v];
  }
  return rez;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> pos(n + 1);
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    pos[x] = i;
  }
  vector<vector<pair<int, int>>> que(n + 1);
  for (int i = 0; i < m; i++) {
    int l, r;
    cin >> l >> r;
    que[l].pb({r, i});
  }
  vector<vector<int>> add(n + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 2 * i; j <= n; j += i) {
      int l = min(pos[i], pos[j]), r = pos[i] ^ pos[j] ^ l;
      add[l].pb(r);
    }
  }
  //cout << "OK" << endl;
  vector<int> ans(m);
  for (int l = n; l >= 1; l--) {
    for (auto it : add[l]) {
      upd(it);
    }
    for (auto it : que[l]) {
      ans[it.S] = get(it.F) + (it.F - l + 1);
    }
  }
  for (int i = 0; i < m; i++) {
    cout << ans[i] << '\n';
  }
}