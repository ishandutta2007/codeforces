#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,avx2")
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

const int INF = 1e9 + 10;
const int N = 35010;
const int K = 110;
int a[N], dp[N][K], lst[N];

deque<int> have[N];
int sum = 0;
pair<int, int> seg = {1, 0};

inline void recalc(int x, int coef) {
  if (!have[x].empty()) {
    sum += (have[x].back() - have[x].front()) * coef;
  }
}

inline void apply_changes(int x, function<void(int)> update) {
  recalc(x, -1);
  update(x);
  recalc(x, 1);
}

inline void go(pair<int, int> new_seg) {
  while (seg.S < new_seg.S) {
    apply_changes(a[++seg.S], [](int x) { have[x].push_back(seg.S); });
  }
  while (seg.F > new_seg.F) {
    apply_changes(a[--seg.F], [](int x) { have[x].push_front(seg.F); });
  }
  while (seg.S > new_seg.S) {
    apply_changes(a[seg.S--], [](int x) { have[x].pop_back(); });
  }
  while (seg.F < new_seg.F) {
    apply_changes(a[seg.F++], [](int x) { have[x].pop_front(); });
  }
}

void calc(int level, int l, int r, int optl, int optr) {
  if (l > r) {
    return;
  }
  int mid = (l + r) / 2;
  pair<int, int> best = {INF, optl - 1};
  for (int i = optl; i <= min(mid, optr); i++) {
    go({i, mid});
    best = min(best, {dp[i - 1][level - 1] + sum, i});
    if (best.F == 0) {
      break;
    }
  }
  dp[mid][level] = best.F;
  calc(level, l, mid - 1, optl, best.S);
  calc(level, mid + 1, r, best.S, optr);
}
 
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    go({1, i});
    dp[i][1] = sum;
  } 
  for (int i = 2; i <= k; i++) {
    calc(i, i, n, i - 1, n);
  }
  cout << dp[n][k] << '\n';
}