#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long ll;
typedef long double ld;
#define int ll
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
#define pii pair<int, int>
const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

struct DSU {
  vector<int> p, sz, start, en, next;
  DSU(int n) {
    p.resize(n + 10);
    sz.resize(n + 10, 1);
    start.resize(n + 10);
    en.resize(n + 10);
    next.resize(n + 10);
    for (int i = 1; i <= n; i++) {
      p[i] = i;
      start[i] = i;
      en[i] = i;
    }
  }
  int find(int v) {
    return (p[v] == v ? v : p[v] = find(p[v]));
  }
  void merge(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) {
      return;
    }
    if (sz[a] < sz[b]) {
      swap(a, b);
    }
    p[b] = a;
    next[en[a]] = start[b];
    en[a] = en[b];
    sz[a] += sz[b];
  }
  void go(int component) {
    int x = start[component];
    while (x != 0) {
      cout << x << ' ';
      x = next[x];
    }
  }
};

void source() {
  int n;
  cin >> n;
  DSU A(n);
  for (int i = 1; i <= n; i++) {
    int a, b;
    cin >> a >> b;
    A.merge(a, b);
  }
  A.go(A.find(1));
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