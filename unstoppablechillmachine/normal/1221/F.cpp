#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll
#define F first
#define S second

struct Node {
  int sum;
  pair<int, int> mx_suf;
  Node() {};
  Node(int sum, pair<int, int> mx_suf) : sum(sum), mx_suf(mx_suf) {};
};

Node merge(Node a, Node b) {
  if (a.mx_suf.F == -1) {
    return b;
  }
  if (b.mx_suf.F == -1) {
    return a;
  }
  return Node(a.sum + b.sum, max(make_pair(b.sum + a.mx_suf.F, a.mx_suf.S), b.mx_suf));
}

const int N = 1e6 + 10;
const int INF = 1e9 + 10;
Node t[4 * N];

void update(int v, int l, int r, int need, int delta) {
  if (l == r) {
    t[v].sum += delta;
    if (t[v].sum > 0) {
      t[v].mx_suf = {t[v].sum, l};
    }
    else {
      t[v].mx_suf = {0, l + 1};
    }
    return;
  }
  int mid = (l + r) / 2;
  if (need <= mid) {
    update(2 * v, l, mid, need, delta);
  }
  else {
    update(2 * v + 1, mid + 1, r, need, delta);
  }
  t[v] = merge(t[2 * v], t[2 * v + 1]);
}

Node get(int v, int l, int r, int a, int b) {
  if (l > b || r < a) {
    return Node(0ll, make_pair(-1ll, 0ll));
  }
  if (l >= a && r <= b) {
    return t[v];
  }
  int mid = (l + r) / 2;
  return merge(get(2 * v, l, mid, a, b), get(2 * v + 1, mid + 1, r, a, b));
}

void dfs(int v, int l, int r) {
  cout << v << ' ' << l << ' ' << r << ' ' << t[v].sum << ' ' << t[v].mx_suf.F << ' ' << t[v].mx_suf.S << '\n';
  if (l == r) {
    return;
  }
  int mid = (l + r) / 2;
  dfs(2 * v, l, mid);
  dfs(2 * v + 1, mid + 1, r);
}  

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  vector<int> srt;
  vector<pair<int, pair<int, int>>> upds;
  cin >> n;
    for (int i = 0; i < n; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    srt.pb(min(a, b));
    srt.pb(max(a, b));
    upds.pb(make_pair(max(a, b), make_pair(min(a, b), c)));
  }
  sort(all(srt));
  srt.resize(unique(all(srt)) - srt.begin());
  unordered_map<int, int> to;
  for (int i = 1; i < SZ(srt); i++) {
    upds.pb(make_pair(srt[i], make_pair(srt[i - 1], srt[i - 1] - srt[i])));
  }
  for (int i = 0; i < SZ(srt); i++) {
    to[srt[i]] = i + 1;
  }
  pair<int, pair<int, int>> ans = make_pair(0, make_pair(INF, INF));
  sort(upds.rbegin(), upds.rend());
  for (int i = 0; i < SZ(srt); i++) {
    while (!upds.empty() && upds.back().F == srt[i]) {
      update(1, 1, SZ(srt), to[upds.back().S.F], upds.back().S.S);
      /*cout << "NEW UPDATE: " << srt[i] << ' ' << ' ' << upds.back().S.F << ' ' << to[upds.back().S.F] << ' ' << upds.back().S.S << '\n';
      for (int j = 1; j <= i + 1; j++) {
        cout << get(1, 1, SZ(srt), j, j).sum << ' ';
      }
      cout << '\n' << '\n';
      dfs(1, 1, SZ(srt));
      cout << '\n' << '\n';*/
      upds.pop_back();
    }
    pair<int, int> res = get(1, 1, SZ(srt), 1, i + 1).mx_suf;
    if (res.F > 0) {
      ans = max(ans, make_pair(res.F, make_pair(srt[res.S - 1], srt[i])));
    }
  }
  cout << ans.F << '\n' << ans.S.F << ' ' << ans.S.F << ' ' << ans.S.S << ' ' << ans.S.S << '\n';
}