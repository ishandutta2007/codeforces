#include <bits/stdc++.h>

using namespace std;

const int md = 1000000007;

inline void add(int &a, int b) {
  a += b;
  if (a >= md) a -= md;
}

inline int mul(int a, int b) {
  return (long long) a * b % md;
}

const int N = 2000010;

int n;
char s[N];

vector <long long> get(char forw, char backw, int bound) {
  vector <long long> res;
  int x = 0, xl = 0, xr = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == forw) {
      x++;
      if (x > xr) {
        xr = x;
        res.push_back(i);
      }
    }
    if (s[i] == backw) {
      x--;
      if (x < xl) {
        xl = x;
        res.push_back(i);
      }
    }
  }
  // loop ones?
  {
    vector <long long> loop;
    for (int i = 0; i < n; i++) {
      if (s[i] == forw) {
        x++;
        if (x > xr) {
          xr = x;
          loop.push_back(i);
        }
      }
      if (s[i] == backw) {
        x--;
        if (x < xl) {
          xl = x;
          loop.push_back(i);
        }
      }
    }
    if (!loop.empty()) {
      while (res.size() < bound) {
        for (int i = 0; i < (int) loop.size(); i++) {
          loop[i] += n;
          res.push_back(loop[i]);
        }
      }
    }
  }
  for (int i = 0; i < (int) res.size(); i++) {
    res[i]++;
  }
  return res;
}

int main() {
  int h, w;
  scanf("%d %d %d", &n, &h, &w);
  scanf("%s", s);
  vector <long long> xs = get('R', 'L', w);
  vector <long long> ys = get('U', 'D', h);
  int xcnt = xs.size();
  int ycnt = ys.size();
  int xptr = 0;
  int yptr = 0;
  int ans = 0;
  while (xptr < xcnt || yptr < ycnt) {
    if (h == 0 || w == 0) {
      break;
    }
    bool go_x = (yptr == ycnt || (xptr < xcnt && xs[xptr] < ys[yptr]));
    if (go_x) {
      add(ans, mul(h, xs[xptr] % md));
      xptr++;
      w--;
    } else {
      add(ans, mul(w, ys[yptr] % md));
      yptr++;
      h--;
    }
  }
  if (h > 0 && w > 0) {
    printf("%d\n", -1);
    return 0;
  }
  printf("%d\n", ans);
  return 0;
}