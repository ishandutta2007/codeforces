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
 
const int N = 2e5 + 10;
int t[4 * N], f[4 * N];

void build(int v, int l, int r, string &s) {
  if (l == r) {
    t[v] = s[l - 1] - '0';
    f[v] = -1;
    return;
  }
  int mid = (l + r) / 2;
  build(2 * v, l, mid, s);
  build(2 * v + 1, mid + 1, r, s);
  t[v] = t[2 * v] + t[2 * v + 1];
  f[v] = -1;
}

void push(int v, int len1, int len2) {
  if (f[v] != -1) {
    f[2 * v] = f[v];
    f[2 * v + 1] = f[v];
    t[2 * v] = f[v] * len1;
    t[2 * v + 1] = f[v] * len2;
    f[v] = -1;
  }
}

void set_value(int v, int l, int r, int a, int b, int vl) {
  if (l > b || r < a) {
    return;
  }
  if (l >= a && r <= b) {
    t[v] = vl * (r - l + 1);
    f[v] = vl;
    return;
  }
  int mid = (l + r) / 2;;
  push(v, mid - l + 1, r - mid);
  set_value(2 * v, l, mid, a, b, vl);
  set_value(2 * v + 1, mid + 1, r, a, b, vl);
  t[v] = t[2 * v] + t[2 * v + 1];
} 

int get_sum(int v, int l, int r, int a, int b) {
  if (l > b || r < a) {
    return 0;
  }
  if (l >= a && r <= b) {
    return t[v];
  }
  int mid = (l + r) / 2;
  push(v, mid - l + 1, r - mid);
  return get_sum(2 * v, l, mid, a, b) + get_sum(2 * v + 1, mid + 1, r, a, b);
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, q;
    cin >> n >> q;
    string s, t;
    cin >> s >> t;
    vector<pair<int, int>> que(q);
    for (auto &it : que) {
      cin >> it.F >> it.S;
    }
    reverse(all(que));
    build(1, 1, n, t);
    bool ok = true;
    for (auto it : que) {
      int rez = get_sum(1, 1, n, it.F, it.S);
      if (rez * 2 == it.S - it.F + 1) {
        ok = false;
        break;
      }
      if (rez * 2 > it.S - it.F + 1) {
        set_value(1, 1, n, it.F, it.S, 1);
      }
      else {
        set_value(1, 1, n, it.F, it.S, 0);
      }
    }
    for (int i = 1; i <= n; i++) {
      if (get_sum(1, 1, n, i, i) != s[i - 1] - '0') {
        ok = false;
      }
    }
    cout << (ok ? "YES\n" : "NO\n");
  }
}