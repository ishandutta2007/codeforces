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

map<int, int> fstX, fstY;
const int MOD = 1e9 + 7;
void add(int &a, int b) {
  a += b;
  if (a >= MOD) {
    a -= MOD;
  }
}

int mult(int a, int b) {
  return (a * 1ll * b) % MOD;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, a, b;
  cin >> n >> b >> a;
  int cx = 0, cy = 0;
  int lx = 1, rx = a, ly = 1, ry = b, ans = 0;
  for (int i = 1; i <= n; i++) {
    char c;
    cin >> c;
    if (c == 'R') {
      cx++;
      if (fstX.find(cx) == fstX.end()) {
        fstX[cx] = i;
        if (rx + cx > a) {
          add(ans, mult(ry - ly + 1, i));
          rx--;
          if (lx > rx) {
            cout << ans << '\n';
            exit(0);
          }
        }
      }
    }
    else if (c == 'L') {
      cx--;
      if (fstX.find(cx) == fstX.end()) {
        fstX[cx] = i;
        if (lx + cx <= 0) {
          add(ans, mult(ry - ly + 1, i));
          lx++;
          if (lx > rx) {
            cout << ans << '\n';
            exit(0);
          }
        }
      }
    }
    else if (c == 'U') {
      cy--;
      if (fstY.find(cy) == fstY.end()) {
        fstY[cy] = i;
        if (ly + cy <= 0) {
          add(ans, mult(rx - lx + 1, i));
          ly++;
          if (ly > ry) {
            cout << ans << '\n';
            exit(0);
          }
        }
      }
    }
    else {
      cy++;
      if (fstY.find(cy) == fstY.end()) {
        fstY[cy] = i;
        if (ry + cy > b) {
          add(ans, mult(rx - lx + 1, i));
          ry--;
          if (ly > ry) {
            cout << ans << '\n';
            exit(0);
          }
        }
      }
    }
  }
  if (cx == 0 && cy == 0) {
    cout << -1 << '\n';
    exit(0);
  }
  vector<pair<int, int>> interesting;
  for (auto it : fstX) {
    if (it.F * 1ll * cx > 0) {
      interesting.pb({it.S, 0});
    }
  }
  for (auto it : fstY) {
    if (it.F * 1ll * cy > 0) {
      interesting.pb({it.S, 1});
    }
  }
  sort(all(interesting));
  int dx = cx, dy = cy;
  for (int i = 1;; i++) {
    cx = dx * i, cy = dy * i;
    for (auto it : interesting) {
      int ct = (i * 1ll * n + it.F) % MOD;
      if (it.S == 0) {
        if (cx > 0) {
          cx++;
          if (rx + cx > a) {
            add(ans, mult(ry - ly + 1, ct));
            rx--;
            if (lx > rx) {
              cout << ans << '\n';
              exit(0);
            }
          } 
        }
        else {
          cx--;
          if (lx + cx <= 0) {
            add(ans, mult(ry - ly + 1, ct));
            lx++;
            if (lx > rx) {
              cout << ans << '\n';
              exit(0);
            }
          }
        }
      }
      else {
        if (cy > 0) {
          cy++;
          if (ry + cy > b) {
            add(ans, mult(rx - lx + 1, ct));
            ry--;
            if (ly > ry) {
              cout << ans << '\n';
              exit(0);
            }
          }
        }
        else {
          cy--;
          if (ly + cy <= 0) {
            add(ans, mult(rx - lx + 1, ct));
            ly++;
            if (ly > ry) {
              cout << ans << '\n';
              exit(0);
            }
          }
        }
       }
    }
  }   
}