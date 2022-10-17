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

const int N = 5e5 + 10;
const int M = 1 << 20;
int a[N], b[N];
map<int, int> g[M];
map<pair<int, int>, vector<int>> have;
int n;

void gen_cycle(int cnt) {
  if (cnt == 0) {
    for (int i = 0; i < n; i++) {
      cout << i * 2 + 1 << ' ' << i * 2 + 2 << ' ';
    }
    cout << '\n';
    exit(0);
  }
  int kek_mask = (1 << cnt) - 1;
  vector<int> deg(1 << cnt);
  for (int i = 0; i < n; i++) {
    a[i] &= kek_mask;
    b[i] &= kek_mask;
    g[a[i]][b[i]]++;
    g[b[i]][a[i]]++;
    deg[a[i]]++;
    deg[b[i]]++;
    have[{min(a[i], b[i]), max(a[i], b[i])}].pb(i);
  } 
  int first = 0, N = (1 << cnt);
  while (!deg[first]) ++first;
  stack<int> st;
  st.push(first);
  vector<int> res;
  while (!st.empty()) {
    int v = st.top();
    int i = N;
    if (!g[v].empty()) {
      i = g[v].begin()->F;
    }
    if (i == N)
    {
      res.push_back(v);
      st.pop();
    }
    else {
      --g[v][i];
      --g[i][v];
      if (g[v][i] == 0) {
        g[v].erase(i);
        g[i].erase(v);
      }
      st.push(i);
    }
  }
  /*for (auto it : res) {
    cout << it << ' ';
  }
  cout << '\n';*/
  vector<int> fuck;
  pair<int, int> cur = {min(res[0], res[1]), max(res[0], res[1])};
  int id = have[cur].back();
  int lst = res[1];
  if (b[id] == lst) {
    fuck.pb(2 * id + 1);
    fuck.pb(2 * id + 2);
  }
  else {
    fuck.pb(2 * id + 2);
    fuck.pb(2 * id + 1);
  }
  have[cur].pop_back();
  for (int i = 2; i < SZ(res); i++) {
    pair<int, int> cur = {min(res[i], lst), max(res[i], lst)};
    if (have[cur].empty()) {
      break;
    }
    int id = have[cur].back();
    if (a[id] == lst) {
      fuck.pb(id * 2 + 1);
      fuck.pb(id * 2 + 2);
      lst = b[id];
    }
    else {
      fuck.pb(id * 2 + 2);
      fuck.pb(id * 2 + 1);
      lst = a[id];
    }
    have[cur].pop_back();
  }
  for (auto it : fuck) {
    cout << it << ' ';
  }
  cout << '\n';
}

int suka[M], p[M], sz[M];

int find(int v) {
  return p[v] == v ? v : p[v] = find(p[v]);
}

void merge(int a, int b) {
  a = find(a), b = find(b);
  if (a == b) {
    return;
  }
  if (sz[a] < sz[b]) {
    swap(a, b);
  }
  sz[a] += sz[b];
  p[b] = a;
}

bool check(int k) {
  int kek_mask = (1 << k) - 1;
  for (int i = 0; i <= kek_mask; i++) {
    suka[i] = 0;
    p[i] = i;
    sz[i] = 1;
  }
  for (int i = 0; i < n; i++) {
    suka[a[i] & kek_mask]++;
    suka[b[i] & kek_mask]++;
    merge((a[i] & kek_mask), (b[i] & kek_mask));
  }
  int cn = 0;
  for (int i = 0; i <= kek_mask; i++) {
    if (suka[i] & 1) {
      return false;
    }
    if (suka[i] > 0) {
      cn++;
    }
  }
  int fi = 0;
  while (!suka[fi]) fi++;
  return (sz[find(fi)] == cn);
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  /*if (n == 1) {
    int x = a[0] ^ b[0], ans = 0;
    if (x == 0) {
      ans = 20;
    }
    else {
      while (x % 2 == 0) {
        ans++;
        x /= 2;
      }
    }
    cout << ans << '\n';
    cout << 1 << ' ' << 2 << '\n';
    exit(0);
  }*/
  int l = 0, r = 21;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    if (check(mid)) {
      l = mid;
    }
    else {
      r = mid;
    }
  }
  cout << l << '\n';
  gen_cycle(l);      
}