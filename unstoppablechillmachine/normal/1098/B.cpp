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

pair<int, vector<char>> solve(int n, int m, vector<vector<char>> &arr) {
  vector<char> cur = {'A', 'C', 'T', 'G'};
  sort(all(cur));
  pair<int, vector<char>> best;
  best.F = INF;
  do {
    int sum = 0;
    for (int i = 0; i < n; i++) {
      int sum1 = 0, sum2 = 0;
      for (int j = 0; j < m; j++) {
        char c1 = cur[(i & 1) * 2 + (j & 1)], c2 = cur[(i & 1) * 2 + ((j & 1) == 0)];
        sum1 += (arr[i][j] != c1);
        sum2 += (arr[i][j] != c2);
      }
      sum += min(sum1, sum2);
    }
    if (sum < best.F) {
      best = MP(sum, cur);
    }
  } while (next_permutation(all(cur)));
  return best;
}

void source() {
  int n, m;
  cin >> n >> m;
  vector<vector<char>> arr(n, vector<char>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
    }
  }
  pair<int, vector<char>> ans = solve(n, m, arr);
  vector<vector<char>> arr2(m, vector<char>(n));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      arr2[i][j] = arr[j][i];
    }
  }
  pair<int, vector<char>> ans2 = solve(m, n, arr2);
  vector<vector<char>> res(n, vector<char>(m));
  if (ans.F < ans2.F) {
    for (int i = 0; i < n; i++) {
      int sum1 = 0, sum2 = 0;
      for (int j = 0; j < m; j++) {
        char c1 = ans.S[(i & 1) * 2 + (j & 1)], c2 = ans.S[(i & 1) * 2 + ((j & 1) == 0)];
        sum1 += (arr[i][j] != c1);
        sum2 += (arr[i][j] != c2);
      }
      if (sum1 < sum2) {
        for (int j = 0; j < m; j++) {
          res[i][j] = ans.S[(i & 1) * 2 + (j & 1)];
        }
      }
      else {
        for (int j = 0; j < m; j++) {
          res[i][j] = ans.S[(i & 1) * 2 + ((j & 1) == 0)];
        }
      }
    }
  }
  else {
    for (int i = 0; i < m; i++) {
      int sum1 = 0, sum2 = 0;
      for (int j = 0; j < n; j++) {
        char c1 = ans2.S[(i & 1) * 2 + (j & 1)], c2 = ans2.S[(i & 1) * 2 + ((j & 1) == 0)];
        sum1 += (arr2[i][j] != c1);
        sum2 += (arr2[i][j] != c2);
      }
      if (sum1 < sum2) {
        for (int j = 0; j < n; j++) {
          res[j][i] = ans2.S[(i & 1) * 2 + (j & 1)];
        }
      }
      else {
        for (int j = 0; j < n; j++) {
          res[j][i] = ans2.S[(i & 1) * 2 + ((j & 1) == 0)];
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << res[i][j];
    }
    cout << '\n';
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