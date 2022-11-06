#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;

  int N = s.size();
  int ans = 0;
  vector<int> width(N, -1);
  // vector<int> bad_row(N);
  for (int i = 0; i < N; ++i) {
    int j = i;
    while (j + 1 < N && (s[j] == 'R' && s[j + 1] == 'L')) {
      j += 2;
    }
    if (j == N) {
      // RLRLRLRLRL
      ans += (N - i) / 2;
      continue;
    }
    ans += (j - i) / 2;
    if (s[j] == 'U' || s[j] == 'L') {
      // RLRLRLU
      // RLRLRLL
      continue;
    }
    int k = j;
    while (k < N && s[k] != 'U') {
      k++;
    }
    if (k == N) {
      continue;
    }
    if (s[j] == 'R') {
      width[i] = k - j;
    } else {
      assert(s[j] == 'D');
      if (s[j + 1] != 'L') {
        width[i] = k - j;
      } else {
        int t = j + 1;
        while (t + 1 < N && s[t + 1] == 'L') {
          t++;
        }
        assert(k > t);
        width[i] = k - t;
      }
    }
  }

  vector<vector<int>> wd(N + 1);
  for (int i = 0; i < N; ++i) {
    if (width[i] != -1) {
      wd[width[i]].push_back(i);
    }
  }

  constexpr int kU = 0;
  constexpr int kD = 1;
  constexpr int kL = 2;
  constexpr int kR = 3;

  for (int i = 0; i < N; ++i) {
    if (s[i] == 'U') s[i] = kU;
    else if (s[i] == 'D') s[i] = kD;
    else if (s[i] == 'L') s[i] = kL;
    else if (s[i] == 'R') s[i] = kR;
  }

  vector<vector<int>> cnt(4, vector<int>(N + 1));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < 4; ++j) {
      cnt[j][i + 1] = cnt[j][i];
    }
    cnt[s[i]][i + 1]++;
  }

  vector<vector<int>> rg(N), lt(N);
  vector<int> pref(N + 1);
  vector<int> top(N + 1);
  vector<int> bot(N + 1);
  for (int m = 2; m <= N; ++m) {
    if (wd[m].empty()) {
      continue;
    }
    for (int i = 0; i < N; ++i) {
      if (s[i] == kR) {
        rg[i % m].push_back(i);
      } 
      if (s[i] == kL) {
        lt[i % m].push_back(i);
      }
    }
    for (int i = 0; i < N; ++i) {
      pref[i + 1] = pref[i];
      top[i + 1] = top[i];
      bot[i + 1] = bot[i];
      if (i >= m && i + m < N) {
        int cnt = (s[i - m] == kD) + (s[i + m] == kU) + (s[i - 1] == kR) + (s[i + 1] == kL);
        if (cnt == 1) {
          pref[i + 1]++;
        }
      }
      if (i + m < N && i > 0 && i + 1 < N) {
        int cnt = (s[i + m] == kU) + (s[i - 1] == kR) + (s[i + 1] == kL);
        if (cnt == 1) {
          top[i + 1]++;
        }
      }
      if (i >= m && i > 0 && i + 1 < N) {
        int cnt = (s[i - m] == kD) + (s[i - 1] == kR) + (s[i + 1] == kL);
        if (cnt == 1) {
          bot[i + 1]++;
        }
      }
    }

    auto CheckLeft = [&](int k) {
      if (k >= m && k + m < N) {
        return (s[k - m] == kD) + (s[k + m] == kU) + (s[k + 1] == kL) == 1;
      }
      return false;
    };

    auto CheckRight = [&](int k) {
      if (k >= m && k + m < N) {
        return (s[k - m] == kD) + (s[k + m] == kU) + (s[k - 1] == kR) == 1;
      }
      return false;
    };

    for (int l : wd[m]) {
      auto riter = lower_bound(rg[(l + m - 1) % m].begin(), rg[(l + m - 1) % m].end(), l);
      auto liter = lower_bound(lt[l % m].begin(), lt[l % m].end(), l);
      int R = N;
      if (riter != rg[(l + m - 1) % m].end()) {
        R = min(R, *riter);
      }
      if (liter != lt[l % m].end()) {
        R = min(R, *liter);
      }
      int sum = 0;
      int left = 0;
      int right = 0;
      for (int r = l + m; r <= N; r += m) {
        if (r > R) {
          break;
        }
        sum += pref[r - 1] - pref[r - m + 1];
        left += CheckLeft(r - m);
        right += CheckRight(r - 1);
        if (cnt[kU][l + m] > cnt[kU][l]) {
          continue;
        }
        if (cnt[kD][r] > cnt[kD][r - m]) {
          continue;
        }
        if (r > l + m) {
          if ((s[l + 1] == kL) + (s[l + m] == kU) == 1 && (s[l + m - 1 - 1] == kR) + (s[l + m - 1 + m] == kU) == 1 &&
              (s[r - m + 1] == kL) + (s[r - m - m] == kD) == 1 && (s[r - 2] == kR) + (s[r - 1 - m] == kD) == 1) {
            if (sum - (pref[l + m - 1] - pref[l + 1]) - (pref[r - 1] - pref[r - m + 1]) == r - l - 2 * m - 2 * (r - l) / m + 4) {
              int t = (r - l) / m - 2;
              if (top[l + m - 1] - top[l + 1] == m - 2 && bot[r - 1] - bot[r - m + 1] == m - 2) {
                if (left - CheckLeft(l) - CheckLeft(r - m) == t &&
                    right - CheckRight(l + m - 1) - CheckRight(r - 1) == t) {
                  if (cnt[kR][r] - cnt[kR][l] + cnt[kL][r] - cnt[kL][l] < r - l) {
                    ans++;
                  }
                }
              }
            }    
          }
        }
      }
    }
    for (int i = 0; i < m; ++i) {
      rg[i].clear();
      lt[i].clear();
    }
  }
  for (int i = 0; i < N; ++i) {
    int j = i;
    while (j + 1 < N && s[j] == kD && s[j + 1] == kU) {
      j += 2;
    }
    ans += (j - i) / 2;
  }
  cout << ans << "\n";
  return 0;
}