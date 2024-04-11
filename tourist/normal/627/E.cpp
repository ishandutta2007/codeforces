#include <bits/stdc++.h>

using namespace std;

const int N = 4010;

vector <int> cells[N];
int col[N], a[N];
int pr[N], ne[N];

int main() {
  int h, w, cnt, k;
  scanf("%d %d %d %d", &h, &w, &cnt, &k);
  for (int i = 1; i <= h; i++) {
    cells[i].clear();
  }
  for (int i = 0; i < cnt; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    cells[x].push_back(y);
  }
  for (int j = 1; j <= w; j++) {
    col[j] = 0;
  }
  long long ans = 0;
  for (int i1 = h; i1 >= 1; i1--) {
    for (int id = 0; id < (int) cells[i1].size(); id++) {
      int j = cells[i1][id];
      col[j]++;
    }
    int cur = 0;
    int j2 = 0;
    int sum = 0;
    for (int j = 1; j <= w; j++) {
      while (j2 + 1 <= w && sum < k) {
        j2++;
        sum += col[j2];
      }
      if (sum >= k) {
        cur += w - j2 + 1;
      }
      sum -= col[j];
    }
    for (int j = 0; j <= w + 1; j++) {
      pr[j] = j - 1;
      ne[j] = j + 1;
    }
    for (int j = 1; j <= w; j++) {
      if (col[j] == 0) {
        pr[ne[j]] = pr[j];
        ne[pr[j]] = ne[j];
      }
    }
    for (int j = 1; j <= w; j++) {
      a[j] = col[j];
    }
    for (int i2 = h; i2 >= i1; i2--) {
      ans += cur;
      for (int id = 0; id < (int) cells[i2].size(); id++) {
        int j = cells[i2][id];
        int lft = j;
        int rgt = j;
        int slft = a[j];
        int srgt = 0;
        while (ne[rgt] <= w && slft + srgt + a[ne[rgt]] <= k) {
          rgt = ne[rgt];
          srgt += a[rgt];
        }
        while (true) {
          if (slft + srgt == k) {
            cur -= (lft - pr[lft]) * (ne[rgt] - rgt);
          }
          lft = pr[lft];
          if (lft == 0) {
            break;
          }
          slft += a[lft];
          if (slft > k) {
            break;
          }
          while (slft + srgt > k) {
            srgt -= a[rgt];
            rgt = pr[rgt];
          }
        }
        a[j]--;
        if (a[j] == 0) {
          pr[ne[j]] = pr[j];
          ne[pr[j]] = ne[j];
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}