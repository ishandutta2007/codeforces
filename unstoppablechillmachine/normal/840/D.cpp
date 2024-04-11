#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops,Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
using namespace std;
typedef long long ll;
//#define int ll
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
#define pii pair<int, int>
const int INF = 1e9 + 10;

mt19937 Random((int)time(0));

struct query {
  int L, R, k, num;
  query() {};
  query(int _L, int _R, int _k, int _num) : L(_L), R(_R), k(_k), num(_num) {};
};
const int SZ = (int)sqrt(3e5);
  
bool cmp(query a, query b) {
  return (a.L / SZ != b.L / SZ ? a.L / SZ < b.L / SZ : a.R < b.R);
}

const int M = 3e5 + 10;
const int MAGIC = 150;
int ans[M], a[M], cnt[M];
inline int get(int l, int r, int need) {
  int len = r - l + 1, res = INF;
  for (int i = 0; i < MAGIC; i++) {
    int x = a[l + Random() % len];
    if (cnt[x] >= need) {
      res = min(res, x);
    }
  }
  return (res == INF ? -1 : res);
}
void source() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<query> q;
  for (int i = 0; i < m; i++) {
    int l, r, k;
    cin >> l >> r >> k;
    q.emplace_back(l, r, k, i);
  }
  sort(all(q), cmp);
  for (int i = q[0].L; i <= q[0].R; i++) {
    cnt[a[i]]++;
  }
  ans[q[0].num] = get(q[0].L, q[0].R, (q[0].R - q[0].L + 1) / q[0].k + 1);
  for (int i = 1; i < m; i++) {
    while (q[i].R > q[i - 1].R) {
      cnt[a[++q[i - 1].R]]++;
    }
    while (q[i].R < q[i - 1].R) {
      cnt[a[q[i - 1].R--]]--;
    }
    while (q[i].L < q[i - 1].L) {
      cnt[a[--q[i - 1].L]]++;
    }
    while (q[i].L > q[i - 1].L) {
      cnt[a[q[i - 1].L++]]--;
    }
    ans[q[i].num] = get(q[i].L, q[i].R, (q[i].R - q[i].L + 1) / q[i].k + 1);
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