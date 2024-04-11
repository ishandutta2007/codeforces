#include <bits/stdc++.h>

using namespace std;

void run_case() {

  int N;
  cin >> N;
  if (N == 1) {
    cout << 1 << '\n';
    return;
  }
  if (N == 2) {
    cout << -1 << '\n';
    return;
  }
  vector<int> all[2];
  for (int i = 1; i <= N * N; i++) {
    all[i % 2].push_back(i);
  }
  sort(all[0].begin(), all[0].end());
  sort(all[1].begin(), all[1].end());
  int cnt = 0;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cnt++;
      if (cnt <= (int) (all[0].size())) {
        cout << all[0][cnt - 1] << " ";
      } else {
        cout << all[1][cnt - (int) all[0].size() - 1] << " ";
      }
    }
    cout << '\n';
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int test;
  cin >> test;
  while (test-- > 0)
    run_case();
    return 0;
}