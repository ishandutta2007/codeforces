#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long ll;
typedef long double ld;
//define int ll
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
#define pii pair<int, int>
const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

#define next nextt

const int MASK = (1 << 17) + 10;
const int N = 1e5 + 10;
const int SZ = 17;
int next[N][SZ], ff[MASK][SZ][SZ], cc[SZ];
char a[N];
bool can[SZ][SZ];
bool good[MASK];

void source() {
  int len, n;
  cin >> len >> n;
  for (int i = 1; i <= len; i++) {
    cin >> a[i];
    cc[a[i] - 'a']++;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> can[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    next[len][i] = INF;
  }
  for (int i = len - 1; i >= 1; i--) {
    for (int j = 0; j < n; j++) {
      next[i][j] = next[i + 1][j];
    }
    next[i][a[i + 1] - 'a'] = i + 1;
    /*for (int j = 0; j < 3; j++) {
      cout << next[i][j] << ' ';
    }
    cout << '\n';*/
  }
  //cout << '\n';
  for (int i = 1; i <= len; i++) {
    vector<pair<int, int>> arr;
    for (int j = 0; j < n; j++) {
      arr.pb({next[i][j], j});
    }

    sort(all(arr));
    while (!arr.empty() && arr.back().S != a[i] - 'a') {
      arr.pop_back();
    }
    while (!arr.empty() && arr.back().F == INF) {
      arr.pop_back();
    }
    /*for (auto it : arr) {
      cout << it.S << ' ';
    }
    cout << '\n';*/
    int mask = 0;
    for (auto it : arr) {
      if (!can[a[i] - 'a'][it.S]) {
        for (int j = 0; j < n; j++) {
          if ((mask >> j) & 1) {
            //cout << (mask ^ (1 << j)) << ' ' << j << ' ' << a[i] - 'a' << ' ' << it.S << '\n';
            ff[mask ^ (1 << j)][j][a[i] - 'a'] |= 1 << (it.S);
            ff[mask ^ (1 << j)][j][it.S] |= 1 << (a[i] - 'a');
          }
        }
      }
      mask |= 1 << it.S;
    }
  }
  //cout << '\n';
  int ans = len;
  good[0] = true;
  for (int mask = 0; mask < (1 << n); mask++) {
    /*if (good[mask]) {
      cout << mask << '\n';
    }*/
    if (good[mask]) {
      int sum = 0;
      for (int i = 0; i < n; i++) {
        if ((mask >> i) & 1) {
          continue;
        }
        sum += cc[i];
      }
      ans = min(ans, sum);
    }
    for (int to = 0; to < n; to++) {
      if ((mask >> to) & 1) {
        continue;
      }
      int tomask = mask | (1 << to);
      bool ok = true;
      for (int letter = 0; letter < n; letter++) {
        if ((tomask >> letter) & 1) {
          continue;
        }
        if ((tomask & ff[mask][to][letter]) != ff[mask][to][letter]) {
          ok = false;
        } 
      }
      if (good[mask] && ok) {
        good[tomask] = true;
      }
      for (int letter = 0; letter < n; letter++) {
        if ((tomask >> letter) & 1) {
          continue;
        }
        for (int letter2 = 0; letter2 < n; letter2++) {
          if ((tomask >> letter2) & 1) {
            continue;
          }
          ff[tomask][letter][letter2] |= ff[mask][letter][letter2];
        }
      }
    }
  }
  cout << ans << '\n';
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