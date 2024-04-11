#include <bits/stdc++.h>

using namespace std;

template <typename T>
class fenwick {
  public:
  vector<T> fenw;
  int n;
  fenwick(int _n) : n(_n) {
    fenw.resize(n);
  }
  void modify(int x, T v) {
    while (x < n) {
      fenw[x] += v;
      x |= (x + 1);
    }
  }
  T get(int x) {
    T v{};
    while (x >= 0) {
      v += fenw[x];
      x = (x & (x + 1)) - 1;
    }
    return v;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n, m;
  cin >> n >> m;
  vector<int> cx(n);
  vector<int> cy(n);
  fenwick<int> fx(n);
  fenwick<int> fy(n);
  while (m--) {
    int foo;
    cin >> foo;
    if (foo == 1) {
      int x, y;
      cin >> x >> y;
      --x; --y;
      if (cx[x] == 0) {
        fx.modify(x, 1);
      }
      cx[x]++;
      if (cy[y] == 0) {
        fy.modify(y, 1);  
      }
      cy[y]++;
    }
    if (foo == 2) {
      int x, y;
      cin >> x >> y;
      --x; --y;
      if (cx[x] == 1) {
        fx.modify(x, -1);
      }
      cx[x]--;
      if (cy[y] == 1) {
        fy.modify(y, -1);  
      }
      cy[y]--;
    }
    if (foo == 3) {
      int x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;
      --x1; --y1; --x2; --y2;
      int sx = fx.get(x2) - fx.get(x1 - 1);
      int sy = fy.get(y2) - fy.get(y1 - 1);
      if (sx == x2 - x1 + 1 || sy == y2 - y1 + 1) {
        cout << "Yes" << '\n';
      } else {
        cout << "No" << '\n';
      }
    }
  }                                                                    
  return 0;
}