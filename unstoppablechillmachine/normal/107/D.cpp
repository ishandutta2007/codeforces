//author: extraterrestrial_
#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,avx,tune=native")
using namespace std;
#define int ll
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define _ inline
#define pb push_back
#define F first
#define S second
#define MP make_pair
#define SZ(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pw(x) (1 << (x))
#ifdef extraterrestrial_
#define debug(x) cerr << #x << ": " << x << '\n';
#else
#define debug(x)
#endif
const int INF = 1e9 + 10;
const ll BINF = 1e18 + 10;

vector<int> one;
int lim = 1;
map<vector<int>, int> gt;
vector<int> f[210];
int md[26];

int sum(vector<int> a, vector<int> b) {
  vector<int> c;
  for (int i = 0; i < SZ(a); i++) {
    c.pb((a[i] + b[i]) % md[i]);
  }
  return gt[c];
}

vector<int> mult(vector<int> a, vector<int> b, int mod) {
  vector<int> res(SZ(a));
  for (int i = 0; i < lim; i++) {
    for (int j = 0; j < lim; j++) {
      int to = sum(f[i], f[j]);
      res[to] = (res[to] + a[i] * b[j]) % mod;
    }
  }
  return res;
}

vector<int> b_pow(int n, int mod) {
  if (n == 1) {
    return one;
  }
  if (n & 1) {
    return mult(one, b_pow(n - 1, mod), mod);
  }
  vector<int> mt = b_pow(n / 2, mod);
  return mult(mt, mt, mod);
}

vector<int> have(26);
vector<vector<int>> lol(26);
int ff = 0;

void gen(int ind, vector<int> &cur) {
  if (ind == 26) {
    f[ff] = cur;
    gt[cur] = ff;
    one.pb(0);
    ff++;
    return;
  }
  if (lol[ind].empty()) {
    gen(ind + 1, cur);
  }
  for (int i = 0; i < have[ind]; i++) {
    cur.pb(i);
    gen(ind + 1, cur);
    cur.pop_back();
  }
}

bool correct(vector<int> x) {
  int pnt = 0;
  for (auto it : x) {
    while (lol[pnt].empty()) {
      pnt++;
    }
    bool ok = false;
    for (auto it2 : lol[pnt]) {
      if (it % it2 == 0) {
        ok = true;
        break;
      }
    }
    if (!ok) {
      return false;
    }
    pnt++;
  }
  return true;
}

void source() {
  int n, m;
  cin >> n >> m;
  if (n == 0) {
    cout << 1;
    exit(0);
  }
  if (m == 0) {
    cout << 0;
    exit(0);
  }
  for (int i = 0; i < m; i++) {
    char c;
    int val;
    cin >> c >> val;
    lim *= val;
    if (!have[c - 'A']) {
      have[c - 'A'] = val;
    }
    else {
      have[c - 'A'] *= val;
    }
    lol[c - 'A'].pb(val);
  }
  int cc = 0;
  for (int i = 0; i < 26; i++) {
    if (!lol[i].empty()) {
      md[cc++] = have[i];
    }
  }
  vector<int> em = {};
  gen(0, em);
  for (int i = 0; i < cc; i++) {
    vector<int> curr(cc);
    curr[i] = 1 % md[i];
    one[gt[curr]]++;
  }
  vector<int> res = b_pow(n, 12345);
  int ans = 0;
  for (int i = 0; i < ff; i++) {
    if (correct(f[i])) {
      ans = (ans + res[i]) % 12345;
    }
  }
  cout << ans;
}

signed main() {
#ifdef extraterrestrial_
  assert(freopen("input.txt", "r", stdin));
  //assert(freopen("output.txt", "w", stdout));
#else
#define TASK ""
  //assert(freopen(TASK".in", "r", stdin));
  //assert(freopen(TASK".out", "w", stdout));
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  source();
#ifdef extraterrestrial_
  cerr << "\n\nTIME :: " << clock() * 1.0 / CLOCKS_PER_SEC;
#endif
  return 0;
}