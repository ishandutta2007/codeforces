#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll
#define F first
#define S second

const int INF = 1e9 + 10;
const ll BINF = 1e18 + 10;
const int MX = 4e5 + 10;
const int MOD = 1e9 + 7;
int sum(int a, int b) {
  return (a + b) % MOD;
}

pair<ll, int> merge(pair<ll, int> a, pair<ll, int> b) {
  if (a.F == b.F) {
    return {a.F, sum(a.S, b.S)};
  }
  return min(a, b);
}

struct ST {
  struct Node {
    int L, R;
    pair<ll, int> mn;
  };
  vector<Node> t;
  int cnt;
  int init(int n) {
    t.resize(n * 20);
    cnt = 0;
    return build(1, n);
  }
  int build(int l, int r) {
    if (l == r) {
      cnt++;
      t[cnt].L = t[cnt].R = 0;
      t[cnt].mn = {BINF, 1};
      return cnt;
    }
    int mid = (l + r) / 2;
    int cur = ++cnt;
    t[cur].L = build(l, mid);
    t[cur].R = build(mid + 1, r);
    t[cur].mn = merge(t[t[cur].L].mn, t[t[cur].R].mn);
    return cur;
  }
  pair<ll, int> get_sum(int v, int l, int r, int a, int b) {
    if (l > b || r < a) {
      return {BINF, 1};
    }
    if (l >= a && r <= b) {
      return t[v].mn;
    }
    int mid = (l + r) / 2;
    return merge(get_sum(t[v].L, l, mid, a, b), get_sum(t[v].R, mid + 1, r, a, b));
  }
  int update(int v, int l, int r, int need, pair<ll, int> vl) {
    if (l == r) {
      cnt++;
      t[cnt].L = t[cnt].R = 0;
      t[cnt].mn = merge(t[v].mn, vl);
      return cnt;
    }
    int cur = ++cnt, mid = (l + r) / 2;
    if (need <= mid) {
      t[cur].L = update(t[v].L, l, mid, need, vl);
      t[cur].R = t[v].R;
    }
    else {
      t[cur].R = update(t[v].R, mid + 1, r, need, vl);
      t[cur].L = t[v].L;
    }
    t[cur].mn = merge(t[t[cur].L].mn, t[t[cur].R].mn);
    return cur;
  }
};

signed main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  vector<pair<int, int>> arr(n);
  vector<int> srt;
  for (auto &it : arr) {
    cin >> it.F >> it.S;
    srt.pb(it.F);
    srt.pb(it.S);
  }
  sort(all(srt));
  srt.resize(unique(all(srt)) - srt.begin());
  unordered_map<int, int> to;
  for (int i = 0; i < SZ(srt); i++) {
    to[srt[i]] = i + 1;
  }
  for (auto &it : arr) {
    it.F = to[it.F];
    it.S = to[it.S];
  }
  sort(all(arr));
  vector<int> mx(n);
  mx[0] = arr[0].S;
  for (int i = 1; i < n; i++) {
    mx[i] = max(mx[i - 1], arr[i].S);
  }
  ST tree;
  vector<int> roots(n + 10);
  roots[0] = tree.init(MX);
  vector<pair<ll, int>> dp(n);
  for (int i = 0; i < n; i++) {
    int ind = upper_bound(all(arr), make_pair(arr[i].S, INF)) - arr.begin();
    pair<ll, int> vl;
    if (ind == 0) {
      vl = {0, 1};
    }
    else {
      ind--;
      int L = mx[ind];
      vl = tree.get_sum(roots[ind + 1], 1, MX, L + 1, arr[i].S);
    }
    vl.F += srt[arr[i].S - 1] - srt[arr[i].F - 1];
    dp[i] = {vl.F + srt[arr[i].F - 1], vl.S};
    roots[i + 1] = tree.update(roots[i], 1, MX, arr[i].F, vl);
  }
  pair<ll, int> vl = {BINF, 1};
  for (int i = 0; i < n; i++) {
    //cout << dp[i].F << ' ' << dp[i].S << '\n';
    if (mx.back() < arr[i].F) vl = merge(vl, dp[i]);
  }
  //assert(tree.cnt < MX * 20);
  cout << vl.S << '\n';
}