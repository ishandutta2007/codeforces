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
  vector<vector<char>> arr(n, vector<char>(m));
  int minx = INF, miny = INF, maxx = -INF, maxy = -INF;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
      if (arr[i][j] == 'w') {
        minx = min(minx, j);
        maxx = max(maxx, j);
        miny = min(miny, i);
        maxy = max(maxy, i);
      }
    }
  }
  if (maxy - miny + 1 > m || maxx - minx + 1 > n) {
    cout << -1;
    exit(0);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (arr[i][j] == 'w') {
        if (i > miny && i < maxy && j > minx && j < maxx) {
          cout << -1;
          exit(0);
        }
      }
    }
  }
  vector<bool> kek(4);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (arr[i][j] == 'w') {
        if (j == minx && i != miny && i != maxy) {
          kek[0] = true;
        }
        if (j == maxx && i != miny && i != maxy) {
          kek[1] = true;
        }
        if (i == miny && j != minx && j != maxx) {
          kek[2] = true;
        }
        if (i == maxy && j != minx && j != maxx) {
          kek[3] = true;
        }
      }
    }
  }
  bool was1 = (maxx == minx), was2 = (miny == maxy);
  if (maxy - miny > maxx - minx) {
    if (was1) {
      if (maxx >= maxy - miny) {
        while (maxx - minx < maxy - miny) {
          minx--;
        }
      }
      else if (m - 1 - minx >= maxy - miny) {
        while (maxx - minx < maxy - miny) {
          maxx++;
        }
      }
    }
    while (maxy - miny > maxx - minx) {
      if (minx > 0 && !kek[0]) {
        minx--;
      }
      else if (maxx + 1 < m && !kek[1]) {
        maxx++;
      }
      else {
        cout << -1;
        exit(0);
      }
    }
  }
  if (maxy - miny < maxx - minx) {
    if (was2) {
      if (maxy >= maxx - minx) {
        while (maxy - miny < maxx - minx) {
          miny--;
        }
      }
      else if (n - 1 - miny >= maxx - minx) {
        while (maxy - miny < maxx - minx) {
          maxy++;
        }
      }
    }
    while (maxy - miny < maxx - minx) {
      if (miny > 0 && !kek[2]) {
        miny--;
      }
      else if (maxy + 1 < n && !kek[3]) {
        maxy++;
      }
      else {
        cout << -1;
        exit(0);
      }
    }
  }
  for (int i = miny; i <= maxy; i++) {
    if (arr[i][minx] != 'w') {
      arr[i][minx] = '+';
    }
    if (arr[i][maxx] != 'w') {
      arr[i][maxx] = '+';
    }
  }
  for (int j = minx; j <= maxx; j++ ) {
    if (arr[miny][j] != 'w') {
      arr[miny][j] = '+';
    }
    if (arr[maxy][j] != 'w') {
      arr[maxy][j] = '+';
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << arr[i][j];
    }
    cout << '\n';
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