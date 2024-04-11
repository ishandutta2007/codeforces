//author: extraterrestrial_
#include <bits/stdc++.h>
//#pragma GCC optimize("O3,Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,avx,tune=native")
using namespace std;
//#define int ll
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

struct ST {
  struct vertex {
    int cnt[3];
    int good[3][3][3];
  };
  vector<vertex> t;
  vector<char> arr;
  vector<pii> lol = {{1, 2}, {2, 0}, {0, 1}};
  ST(int n, vector<char> &_arr) {
    arr = _arr;
    t.resize(4 * n + 10);
    build(1, 1, n);
  }
  void relax(int v) {
    for (int i = 0; i < 3; i++) {
      for (int pref = 0; pref < 3; pref++) {
        for (int suf = 0; suf < 3; suf++) {
          t[v].good[i][pref][suf] = 0;
        }
      }
    }
    for (int i = 0; i < 3; i++) {
      t[v].cnt[i] = t[2 * v].cnt[i] + t[2 * v + 1].cnt[i];
      for (int pref = 0; pref < 3; pref++) {
        for (int suf = 0; suf < 3; suf++) {
          int tosuf, topref;
          if (suf == 2) {
            tosuf = 2;
          }
          else if (suf == 1) {
            tosuf = (t[2 * v + 1].cnt[lol[i].F] ? 2 : 1);
          }
          else {
            if (t[2 * v + 1].cnt[lol[i].F]) {
              tosuf = 2;
            }
            else {
              tosuf = (t[2 * v + 1].cnt[lol[i].S] ? 1 : 0);
            }
          }
          if (pref == 2) {
            topref = 2;
          }
          else if (pref == 1) {
            topref = (t[2 * v].cnt[lol[i].F] ? 2 : 1);
          }
          else {
            if (t[2 * v].cnt[lol[i].F]) {
              topref = 2;
            }
            else {
              topref = (t[2 * v].cnt[lol[i].S] ? 1 : 0);
            }
          }
          t[v].good[i][pref][tosuf] += t[2 * v].good[i][pref][suf];
          t[v].good[i][topref][suf] += t[2 * v + 1].good[i][pref][suf];
        }
      }
    }
  }
  void build(int v, int l, int r) {
    if (l == r) {
      if (arr[l] == 'R') {
        t[v].cnt[0]++;
        t[v].good[0][0][0]++;
      }
      if (arr[l] == 'S') {
        t[v].cnt[1]++;
        t[v].good[1][0][0]++;
      }
      if (arr[l] == 'P') {
        t[v].cnt[2]++;
        t[v].good[2][0][0]++;
      }
      return;
    }
    int mid = (l + r) / 2;
    build(2 * v, l, mid);
    build(2 * v + 1, mid + 1, r);
    relax(v);
  }
  void update(int v, int l, int r, int need, char c) {
    if (l == r) {
      for (int i = 0; i < 3; i++) {
        t[v].cnt[i] = 0;
        for (int pref = 0; pref < 3; pref++) {
          for (int suf = 0; suf < 3; suf++) {
            t[v].good[i][pref][suf] = 0;
          }
        }
      }
      if (c == 'R') {
        t[v].cnt[0]++;
        t[v].good[0][0][0]++;
      }
      if (c == 'S') {
        t[v].cnt[1]++;
        t[v].good[1][0][0]++;
      }
      if (c == 'P') {
        t[v].cnt[2]++;
        t[v].good[2][0][0]++;
      }
      return;
    }
    int mid = (l + r) / 2;
    if (need <= mid) {
      update(2 * v, l, mid, need, c);
    }
    else {
      update(2 * v + 1, mid + 1, r, need, c);
    }
    relax(v);
  }
  int calc() {
    int res = 0;
    for (int type = 0; type < 3; type++) {
      for (int i = 0; i < 3; i += 2) {
        for (int j = 0; j < 3; j += 2) {
          res += t[1].good[type][i][j];
        }
      }
    }
    return res;
  }
};

void source() {
  int n, m;
  cin >> n >> m;
  vector<char> arr(n + 1);
  for (int i = 1; i <= n; i++) {
    char c;
    cin >> c;
    arr[i] = c;
  }
  ST tree(n, arr);
  cout << tree.calc() << '\n';
  for (int i = 0; i < m; i++) {
    int pos;
    char c;
    cin >> pos >> c;
    tree.update(1, 1, n, pos, c);
    cout << tree.calc() << '\n';
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