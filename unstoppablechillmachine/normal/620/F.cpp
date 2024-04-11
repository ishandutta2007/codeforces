#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long ll;
typedef long double ld;
//#define int ll
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
#define pii pair<int, int>
const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

struct query {
  int L, R, ind;
};

const int B = 260;

bool cmp(query a, query b) {
  return (a.L / B == b.L / B ? a.R < b.R : a.L / B < b.L / B);
}

const int N = 5e4 + 10;
const int MX = 2e6 + 10;
const int root = 1;
int a[N], ans[N], pref[MX], curans, curl, curr;

struct trie {
  int go[MX][2];
  //multiset<int> have[MX];
  pair<int, int> calc[MX];
  int cnt;
  vector<int> wasV, wasC;
  vector<pair<int, int>> wasGo, wasCalc;
  trie() {
    cnt = 1;
  }
  inline void clear() {
    for (int i = 1; i <= cnt; i++) {
      go[i][0] = go[i][1] = 0;
    }
    cnt = 1;
    wasV = {};
    wasC = {};
    wasGo = {};
    wasCalc = {};
  }
  inline void add(int val, int x) {
    int v = root;
    for (int i = 20; i >= 0; i--) {
      int cc = (val >> i) & 1;
      wasV.pb(v);
      wasC.pb(cnt);
      wasCalc.pb(calc[v]);
      wasGo.pb({go[v][0], go[v][1]});
      if (!go[v][cc]) {
        go[v][cc] = ++cnt;
        calc[cnt] = {INF, -INF};
      }
      v = go[v][cc];
      calc[v].F = min(calc[v].F, x);
      calc[v].S = max(calc[v].S, x);
      //have[v].insert(x);
    }
  }
  /*inline void del(int val, int x) {
    int v = root;
    for (int i = 20; i >= 0; i--) {
      int cc = (val >> i) & 1;
      int kek = go[v][cc];
      if (SZ(have[go[v][cc]]) == 1) {
        go[v][cc] = 0;
      }
      v = kek;
      have[v].erase(have[v].find(x));
    }
  }*/
  void go_back() {
    for (int i = 0; i < 21; i++) {
      int v = wasV.back();
      wasV.pop_back();
      calc[v] = wasCalc.back();
      wasCalc.pop_back();
      go[v][0] = wasGo.back().F;
      go[v][1] = wasGo.back().S;
      wasGo.pop_back();
      cnt = wasC.back();
      wasC.pop_back();
    }
  }
  inline bool check(int v, int x, bool down) {
    /*auto it = st.lower_bound(x);
    return (down ? it != st.begin() : it != st.end());*/
    return (down ? calc[v].F < x : calc[v].S >= x);
  }
  inline int get(int x, int val, bool down) {
    int v = root, res = 0;
    for (int i = 20; i >= 0; i--) {
      int cc = ((val >> i) & 1) ^ 1;
      if (go[v][cc] && check(go[v][cc], x, down)) {
        res += 1 << i;
        v = go[v][cc];
      }
      else if (go[v][cc ^ 1] && check(go[v][cc ^ 1], x, down)) {
        v = go[v][cc ^ 1];
      }
      else {
        return 0;
      } 
    }
    return res;
  }
};

trie t1, t2; 
vector<int> rb_ans, vals;

inline void addR(int x) {
  t1.add(pref[x - 1], x - 1);
  t2.add(pref[x], x);
  curans = max(curans, t1.get(x, pref[x], 1));
  curans = max(curans, t2.get(x, pref[x - 1], 0));
}

inline void addL(int x) {
  t1.add(pref[x - 1], x - 1);
  t2.add(pref[x], x);
  rb_ans.pb(curans);
  //vals.pb(x);
  curans = max(curans, t1.get(x, pref[x], 1));
  curans = max(curans, t2.get(x, pref[x - 1], 0));
}

inline void go_back() {
  curans = rb_ans.back();
  rb_ans.pop_back();
  //t1.del(pref[vals.back() - 1], vals.back() - 1);
  //t2.del(pref[vals.back()], vals.back());
  t1.go_back();
  t2.go_back();
  //vals.pop_back();
}

void source() {
  int n, m, mx = 0;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mx = max(mx, a[i]);
  }
  for (int i = 1; i <= mx; i++) {
    pref[i] = pref[i - 1] ^ i;
  }
  vector<query> q(m);
  for (int i = 0; i < m; i++) {
    cin >> q[i].L >> q[i].R;
    q[i].L--;
    q[i].R--;
    q[i].ind = i;
  }
  sort(all(q), cmp);
  for (int i = 0; i < m; i++) {
    if (i == 0 || q[i].L / B != q[i - 1].L / B) {
      t1.clear();
      t2.clear();
      rb_ans = {};
      vals = {};
      curans = 0;
      curr = q[i].L - 1;
    }
    while (curr < q[i].R) {
      curr++;
      if (curr / B != q[i].L / B) {
        addR(a[curr]);
      }
    }
    int from;
    for (int j = q[i].L; j <= q[i].R; j++) {
      if (j / B != q[i].L / B) {
        break;
      }
      from = j;
    }
    for (int j = from; j >= q[i].L; j--) {
      addL(a[j]);
    }
    ans[q[i].ind] = curans;
    while (!rb_ans.empty()) {
      go_back();
    } 
  }
  for (int i = 0; i < m; i++) {
    cout << ans[i] << '\n';
  }
}

signed main() {
#ifdef extraterrestrial_
  assert(freopen("input.txt", "r", stdin));
  //assert(freopen("output.txt", "w", stdout));
#else
#define TASK ""
  //assert(freopen(TASK".in", "r", stdin));
  //assert(freopen(TASK".out", "w", stdout));
  //assert(freopen("input.txt", "r", stdin));
  //assert(freopen("output.txt", "w", stdout));
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  source();
  return 0;
}