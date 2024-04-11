#include <bits/stdc++.h>
using namespace std;

int64_t Solve() {
  int N, M;
  cin >> N >> M;
  vector<int> p(N);
  for (int i = 0; i < N; ++i) {
    cin >> p[i];
  }
  sort(p.begin(), p.end());
  vector<int> l(M), r(M);
  for (int i = 0; i < M; ++i) {
    cin >> l[i] >> r[i];
  }
  vector<int> order(M);
  iota(order.begin(), order.end(), 0);
  sort(order.begin(), order.end(), [&](int i, int j) {
    if (r[i] != r[j]) {
      return r[i] < r[j];
    }
    return r[i] - l[i] < r[j] - l[j];
  });

  vector<int> segs;
  int rightmost = -1E9 - 1;
  int j = 0;
  for (int i : order) {
    while (j < N && p[j] <= r[i]) {
      rightmost = max(rightmost, p[j]);
      j++;
    }
    if (rightmost < l[i]) {
      segs.push_back(i);
    }
    rightmost = max(rightmost, l[i]);
  }
  if (segs.empty()) {
    return 0;
  }
  int K = segs.size();
  if (*min_element(p.begin(), p.end()) > r[segs[K - 1]]) {
    return *min_element(p.begin(), p.end()) - r[segs[0]];
  }
  if (*max_element(p.begin(), p.end()) < l[segs[0]]) {
    return l[segs[K - 1]] - *max_element(p.begin(), p.end());
  }

  constexpr int64_t kInf = 1'000'000'000'000'000'000;
  vector<int> upto(N);

  for (int i = 0, j = 0; i < N; ++i) {
    while (j < K && r[segs[j]] < p[i]) j++;
    upto[i] = j - 1;
  }

  vector<int64_t> dp_move_left(N, kInf);
  vector<int64_t> dp_move_right(N, kInf);
  vector<int64_t> dp_not_move(N, kInf);
  for (int i = 0; i < N; ++i) {
    if (p[i] < l[segs[0]]) {
      dp_not_move[i] = 0;
    }
  }
  vector<int64_t> dp1(K, kInf);
  vector<int64_t> dp2(K, kInf);
  vector<int64_t> dp(K, kInf);

  for (int i = 0, j = -1, ptr = 0; i < K; ++i) {
    while (j + 1 < N && p[j + 1] <= r[segs[i]]) j++;
    if (j >= 0) {
      dp_not_move[j] = min(dp_not_move[j], dp1[upto[j]]);
      if (j > 0 && upto[j] == upto[j - 1]) {
        dp_not_move[j] = min(dp_not_move[j], dp[upto[j]]);
      }
    }
    if (j >= 0) {
      // case 1: visited by the p[j]
      dp1[i] = min(dp1[i], dp_not_move[j] + l[segs[i]] - p[j]);
      // case 2: p[j] moves left first, and then visit segs[i]
      dp1[i] = min(dp1[i], dp_move_left[j] + l[segs[i]]);
      // case 3: p[j] visit segs[i] first, and then move left
      dp1[i] = min(dp1[i], dp_move_right[j] + l[segs[i]] + l[segs[i]] - p[j]);
    }
    if (j + 1 < N) {
      // case 4: visited by the p[j + 1]
      dp2[upto[j + 1]] = min(dp2[upto[j + 1]], (i > 0 ? dp[i - 1] : 0) + p[j + 1] - r[segs[i]]);
    }
    dp[i] = min(dp1[i], dp2[i]);
    if (i + 1 < K) {
      if (j + 1 < N) {
        if (p[j + 1] < r[segs[i + 1]]) {
          dp_not_move[j + 1] = min(dp_not_move[j + 1], dp1[i]);
        } else {
          dp_move_left[j + 1] = min(dp_move_left[j + 1], dp[i] + p[j + 1] - r[segs[i + 1]] - r[segs[i + 1]]);
          dp_move_right[j + 1] = min(dp_move_right[j + 1], dp[i] - r[segs[i + 1]]);
        }
        if (j == -1 || i == 0 || r[segs[i - 1]] < p[j]) {
          int64_t d = (i == 0 ? 0 : dp[i - 1]);
          dp_move_left[j + 1] = min(dp_move_left[j + 1], d + p[j + 1] - r[segs[i]] - r[segs[i]]);
          dp_move_right[j + 1] = min(dp_move_right[j + 1], d - r[segs[i]]);
        }
      }
    }
  }
  return dp[K - 1];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cout << Solve() << "\n";
  }
  return 0;
}