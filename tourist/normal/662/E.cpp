#include <bits/stdc++.h>

using namespace std;

const int N = 5555;

int hackable[N];
int sols[N];
int pts[N][13];
int score[N];
int z[N];
int bound[N];
int cnt_hack[N];
int rgt[N];
int task[N][13];
int guys[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int j = 0; j < 3; j++) {
    hackable[j] = 0;
    sols[j] = 0;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      scanf("%d", task[i] + j);
      if (task[i][j] < 0) {
        hackable[j]++;
      }
      if (task[i][j] > 0) {
        sols[j]++;
      }
    }
  }
  int cost[3];
  int ans = n;
  for (cost[0] = 500; cost[0] <= 3000; cost[0] += 500) {
    for (cost[1] = 500; cost[1] <= 3000; cost[1] += 500) {
      for (cost[2] = 500; cost[2] <= 3000; cost[2] += 500) {
        bool err = false;
        for (int j = 0; j < 3; j++) {
          cnt_hack[j] = -1;
          for (int u = hackable[j]; u >= 0; u--) {
            int k = sols[j] + (hackable[j] - u);
            int real_cost = 500;
            int coeff = 2;
            while (coeff * k <= n && real_cost < 3000) {
              coeff *= 2;
              real_cost += 500;
            }
            if (real_cost == cost[j]) {
              cnt_hack[j] = u;
              break;
            }
          }
          if (cnt_hack[j] == -1) {
            err = true;
            break;
          }
        }
        if (err) {
          continue;
        }
        for (int i = 0; i < n; i++) {
          score[i] = 0;
          for (int j = 0; j < 3; j++) {
            int a = abs(task[i][j]);
            pts[i][j] = (a > 0 ? (cost[j] * (250 - a) / 250) : 0);
            score[i] += pts[i][j];
          }
        }
        score[0] += 100 * (cnt_hack[0] + cnt_hack[1] + cnt_hack[2]);
        int cnt = 0;
        for (int type = 0; type < 128; type++) {
          guys[type] = 0;
        }
        for (int i = 1; i < n; i++) {
          if (score[i] > score[0]) {
            int type = 0;
            for (int t = 1; t < 8; t++) {
              int dec = 0;
              for (int j = 0; j < 3; j++) {
                if (t & (1 << j)) {
                  if (task[i][j] < 0) {
                    dec += pts[i][j];
                  }
                }
              }
              if (score[i] - dec <= score[0]) {
                type |= (1 << (t - 1));
              }
            }
            guys[type]++;
            cnt++;
          }
        }
        for (int mask = 1; mask < (1 << 7); mask++) {
          rgt[mask] = 0;
          for (int type = 0; type < 128; type++) {
            if (type & mask) {
              rgt[mask] += guys[type];
            }
          }
        }
        for (int j = 0; j < 3; j++) {
          cnt_hack[j] = min(cnt_hack[j], cnt);
        }
        for (int AB = 0; AB <= cnt_hack[0]; AB++) {
          for (int AC = 0; AB + AC <= cnt_hack[0]; AC++) {
            for (int BC = 0; AB + BC <= cnt_hack[1] && AC + BC <= cnt_hack[2]; BC++) {
              for (int ABC = 0; AB + AC + ABC <= cnt_hack[0] && AB + BC + ABC <= cnt_hack[1] && AC + BC + ABC <= cnt_hack[2]; ABC++) {
                int A = cnt_hack[0] - AB - AC - ABC;
                int B = cnt_hack[1] - AB - BC - ABC;
                int C = cnt_hack[2] - AC - BC - ABC;
                z[1] = 0;
                z[2] = 0;
                z[3] = AB;
                z[4] = 0;
                z[5] = AC;
                z[6] = BC;
                z[7] = ABC;
                bound[0] = 0;
                bound[1] = A;
                bound[2] = B;
                bound[3] = A + B;
                bound[4] = C;
                bound[5] = A + C;
                bound[6] = B + C;
                bound[7] = A + B + C;
                for (int mask = 1; mask < (1 << 7); mask++) {
                  int lft = 0;
                  for (int t = 1; t < 8; t++) {
                    if (mask & (1 << (t - 1))) {
                      lft += z[t];
                    }
                  }
                  bound[mask & 7] = min(bound[mask & 7], rgt[mask] - lft);
                }
                if (bound[0] < 0) {
                  continue;
                }
                for (int realA = 0; realA <= bound[1]; realA++) {
                  int boundB = min(bound[2], bound[3] - realA);
                  int boundC = min(bound[4], bound[5] - realA);
                  int boundBC = min(bound[6], bound[7] - realA);
                  if (boundB >= 0 && boundC >= 0 && boundBC >= 0) {
                    int realBplusC = min(boundB + boundC, boundBC);
                    ans = min(ans, 1 + (cnt - realA - realBplusC - AB - AC - BC - ABC));
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}