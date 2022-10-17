//author: extraterrestrial_
#include <bits/stdc++.h>
//#pragma GCC optimize("O3,Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,avx,tune=native")
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
#define pw(x) (1ll << (x))
#ifdef extraterrestrial_
#define debug(x) cerr << #x << ": " << x << '\n';
#else
#define debug(x)
#endif
const int INF = 1e9 + 10;
const ll BINF = 1e18 + 10;

int n, m;
bool correct(pair<int, int> a) {
  return a.F >= 1 && a.F <= n && a.S >= 1 && a.S <= m;
}

void source() {
  cin >> n >> m;
  vector<vector<char>> arr(n + 1, vector<char>(m + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> arr[i][j];
    }
  }
  vector<vector<int>> right_diag(n + 1, vector<int>(m + 1)), left_diag(n + 1, vector<int>(m + 1));
  for (int i = 1; i <= m; i++) {
    int val = (arr[1][i] == '1' ? 1 : -INF);
    right_diag[1][i] = left_diag[1][i] = val;
  }
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (arr[i][j] == '1') {
        left_diag[i][j] = right_diag[i][j] = i;
      }
      else {
        if (j < m) {
          right_diag[i][j] = right_diag[i - 1][j + 1];
        }
        else {
          right_diag[i][j] = i - 1;
        }
        if (j > 1) {
          left_diag[i][j] = left_diag[i - 1][j - 1];
        }
        else {
          left_diag[i][j] = i - 1;
        }
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (arr[i][j] == '1') {
        continue;
      }
      pair<int, int> curA = {i, j}, curB = {i, j}, curC = {i, j}, curD = {i, j};
      bool okA = true, okB = true, okC = true, okD = true;
      for (;;) {
        if (!okA && !okB && !okC && !okD) {
          break;
        } 
        curA.S++;
        curB.F--;
        curC.S--;
        curD.F++;
        if (!correct(curA) || arr[curA.F][curA.S] == '1') {
          okA = false;
        }
        if (!correct(curB) || arr[curB.F][curB.S] == '1') {
          okB = false;
        }
        if (!correct(curC) || arr[curC.F][curC.S] == '1') {
          okC = false;
        }
        if (!correct(curD) || arr[curD.F][curD.S] == '1') {
          okD = false;
        }
        if (okA && okD && right_diag[curD.F][curD.S] < curA.F) {
          ans++;
        }
        if (okC && okD && left_diag[curD.F][curD.S] < curC.F) {
          ans++;
        }
        if (okA && okB && left_diag[curA.F][curA.S] < curB.F) {
          ans++;
        }
        if (okB && okC && right_diag[curC.F][curC.S] < curB.F) {
          ans++;
        }


        if (okA && okC && correct(curD) && right_diag[curD.F][curD.S] < curA.F && left_diag[curD.F][curD.S] < curC.F) {
          ans++;
        }

        if (okA && okC && correct(curB) && left_diag[curA.F][curA.S] < curB.F && right_diag[curC.F][curC.S] < curB.F) {
          ans++;
        }

        if (okB && okD && correct(curA) && right_diag[curD.F][curD.S] < curA.F && left_diag[curA.F][curA.S] < curB.F) {
          ans++;
        }
        
        if (okB && okD && correct(curC) && left_diag[curD.F][curD.S] < curC.F && right_diag[curC.F][curC.S] < curB.F) {
          ans++;
        }

      }
      //cout << i << ' ' << j << ' ' << ans << '\n';
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