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

void source() {
  int n, m;
  cin >> n >> m;
  vector<int> ff(n + 1, INF), cnt(n + 1);
  for (int i = 1; i <= m; i++) {
    int from, to;
    cin >> from >> to;
    cnt[from]++;
    int d;
    if (to >= from) {
      d = to - from;
    }
    else {
      d = to - from + n;
    }
    ff[from] = min(ff[from], d);
  }
  /*for (int i = 1; i <= n; i++) {
    cout << ff[i] << ' ' << cnt[i] << '\n';
  }
  cout << '\n';*/
  for (int i = 1; i <= n; i++) {
    int cur = i, res = 0, add = 0;
    do {
      if (cnt[cur] > 0) {
        res = max(res, add + n * (cnt[cur] - 1) + ff[cur]);
      }
      add++;
      cur++;
      if (cur > n) {
        cur -= n;
      }
    } while (cur != i);
    cout << res << ' ';
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
  //assert(freopenpen("input.txt", "r", stdin));
  //assert(freopen("output.txt", "w", stdout));
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  source();
  return 0;
}