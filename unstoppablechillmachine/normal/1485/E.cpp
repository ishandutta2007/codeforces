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
vector<int> g[N];
vector<int> have[N];
int mx;
int pr[N];
 
void dfs(int v, int p = 0, int h = 1) {
  assert(h < N);
  have[h].pb(v);
  mx = max(mx, h);
  pr[v] = p;
  for (auto u : g[v]) {
    if (u != p) {
      dfs(u, v, h + 1);
    }
  }
}

int a[N];

bool cmp(int A, int B) {
  return a[A] < a[B];
}

mt19937 rnd(time(0));

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int T = 1;
  cin >> T;
  while (T--) {
    int n = 2e5;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      g[i] = have[i] = {};  
    }
    mx = 0;
    for (int i = 2; i <= n; i++) {
      int x = rnd() % (i - 1) + 1;
      cin >> x; 
      g[i].pb(x);
      g[x].pb(i);
    }
    for (int i = 2; i <= n; i++) {
      cin >> a[i];
      //a[i] = rnd();
    }
    dfs(1);
    for (int h = 1; h <= mx; h++) {
      sort(all(have[h]), cmp);
    }
    vector<int> dp(n + 1), pref(n + 2), suf(n + 2);
    auto recalc = [&](int i) {
      pref[0] = dp[have[i][0]] - a[have[i][0]];
      for (int j = 1; j < SZ(have[i]); j++) {
        pref[j] = max(pref[j - 1], dp[have[i][j]] - a[have[i][j]]);
      }
      suf[SZ(have[i]) - 1] = dp[have[i][SZ(have[i]) - 1]] + a[have[i][SZ(have[i]) - 1]];
      for (int j = SZ(have[i]) - 2; j >= 0; j--) {
        suf[j] = max(suf[j + 1], dp[have[i][j]] + a[have[i][j]]);
      }
    };
    recalc(mx);
    for (int i = mx - 1; i >= 1; i--) {
      //cout << i << endl;
      for (int v : have[i]) {
        for (auto u : g[v]) {
          if (u == pr[v]) {
            continue;
          }
          //cout << u << endl;
          dp[v] = max(dp[v], dp[u] + max(abs(a[have[i + 1].back()] - a[u]), abs(a[have[i + 1][0]] - a[u])));
          dp[v] = max(dp[v], suf[0] - a[u]);
          dp[v] = max(dp[v], pref[SZ(have[i + 1]) - 1] + a[u]);
          /*int l = -1, r = SZ(have[i + 1]);
          while (r - l > 1) {
            int mid = (l + r);
            if (a[have[i + 1][mid]] < a[u]) {
              l = mid;
            }
            else {
              r = mid;
            }
          }
          if (l + 1 < SZ(have[i + 1])) {
            dp[v] = max(dp[v], suf[l + 1] - a[u]);
          }
          if (l >= 0) {
            dp[v] = max(dp[v], pref[l] + a[u]);
          }*/
        }
      }
      recalc(i);
      //assert(clock() * 1.0 / CLOCKS_PER_SEC < 1.5);
    }
    //cout << "OK" << endl;
    cout << dp[1] << '\n';
  }
  cerr << "TIME :: " << clock() * 1.0 / CLOCKS_PER_SEC << '\n';
}