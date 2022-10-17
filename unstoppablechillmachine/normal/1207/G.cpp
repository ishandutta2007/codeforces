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
 
const int N = 4e5 + 10;
const int ALPHA = 26;
const int B = (int)sqrt(N);
int mp[N][ALPHA], cnt = 1;

int add(string s) {
  int v = 1;
  for (int i = 0; i < SZ(s); i++) {
    int cc = s[i] - 'a';
    if (!mp[v][cc]) {
      mp[v][cc] = ++cnt;
    }
    v = mp[v][cc];
  }
  return v;
}

string curs;
vector<pair<int, int>> que[N];
vector<pair<string, int>> que2[N];
vector<int> g[N];
int z[2 * N];

inline int calc(string &s, string &t) {
  int n = SZ(s) + SZ(t), l = 0, r = 1;
  for (int i = 1; i < n; i++) {
    z[i] = min(z[i - l], max(r - i, 0));
    while (i + z[i] < n) {
      char c1 = (i + z[i] < SZ(t) ? t[i + z[i]] : s[i + z[i] - SZ(t)]), 
      c2 = (z[i] < SZ(t) ? t[z[i]] : s[z[i] - SZ(t)]);
      if (c1 != c2) {
        break;
      }
      z[i]++;
    }
    if (i + z[i] > r) {
      l = i;
      r = i + z[i];
    }
  }
  int rez = 0;
  for (int i = SZ(t); i < n; i++) {
    if (z[i] >= SZ(t)) {
      rez++;
    }
  }
  return rez;
}

int ans[N], res[N];
char c[N];

void dfs(int v) {
  curs.pb(c[v]);
  for (auto it : que2[v]) {
    ans[it.S] = calc(curs, it.F);
  }
  int cv = 1;
  for (int i = SZ(curs) - 1; i >= max(0, SZ(curs) - B); i--) {
    cv = mp[cv][curs[i] - 'a'];
    if (!cv) {
      break;
    }
    res[cv]++;
  }
  for (auto it : que[v]) {
    ans[it.S] = res[it.F];
  }
  for (auto u : g[v]) {
    dfs(u);
  }
  cv = 1;
  for (int i = SZ(curs) - 1; i >= max(0, SZ(curs) - B); i--) {
    cv = mp[cv][curs[i] - 'a'];
    if (!cv) {
      break;
    }
    res[cv]--;
  }
  curs.pop_back();
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> roots;
  for (int i = 1; i <= n; i++) {
    int type;
    cin >> type;
    if (type == 1) {
      cin >> c[i];
      roots.pb(i);
    }
    else {
      int p;
      cin >> p >> c[i];
      g[p].pb(i);
    }
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    string t;
    int id;
    cin >> id >> t;
    if (SZ(t) <= B) {
      reverse(all(t));
      que[id].pb({add(t), i});
    }
    else {
      que2[id].pb({t, i});
    }
  }
  for (auto it : roots) {
    dfs(it);
  }
  for (int i = 0; i < q; i++) {
    cout << ans[i] << '\n';
  } 
}