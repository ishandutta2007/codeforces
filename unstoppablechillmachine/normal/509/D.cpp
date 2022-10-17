//author: extraterrestrial_
#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define pb push_back
#define int ll
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
#define pii pair<int, int>
const int INF = 1e9 + 10;
const ll BINF = 1e18 + 10;

void source() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (auto &it : a) {
    for (auto &it2 : it) {
      cin >> it2;
    }
  }
  int mod = -1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][0] == a[j][0]) {
        for (int k = 1; k < m; k++) {
          if (a[i][k] != a[j][k]) {
            cout << "NO";
            exit(0);
          }
        }
      }
      else if (a[i][0] < a[j][0]) {
        for (int k = 1; k < m; k++) {
          if (a[j][k] - a[i][k] == a[j][0] - a[i][0]) {
            continue;          
          }
          else {
            int cur = (a[j][0] - a[i][0]) - a[j][k] + a[i][k];
            if (cur <= 0) {
              cout << "NO";
              exit(0);
            }
            if (mod != -1 && cur != mod) {
              cout << "NO";
              exit(0);
            }
            mod = cur;
          }
        }
      }
    }
  }
  if (mod == -1) {
    mod = 1e18;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (mod <= a[i][j]) {
        cout << "NO";
        exit(0);
      }
    }
  }
  cout << "YES\n" << mod << '\n';
  for (int i = 0; i < n; i++) {
    cout << a[i][0] << ' ';
  }
  cout << '\n';
  for (int i = 0; i < m; i++) {
    if (a[0][0] > a[0][i]) {
      cout << a[0][i] + mod - a[0][0] << ' ';
    }
    else {
      cout << a[0][i] - a[0][0] << ' ';
    }
  } 
}

signed main() {
#ifdef extraterrestrial_
  assert(freopen("input.txt", "r", stdin));
  //assert(freopen("output2.txt", "w", stdout));
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
#ifdef extraterrestrial_
  cerr << "\n\nTIME :: " << clock() * 1.0 / CLOCKS_PER_SEC;
#endif
  return 0;
}