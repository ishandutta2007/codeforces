#include <bits/stdc++.h>

using namespace std;

void run_case() {

  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  long long ans = 0;
  map<int, int> cnt;
  for (int i = 0; i < N; i++) {
    ans += cnt[A[i] - i];
    cnt[A[i] - i]++;
  }
  cout << ans << '\n';
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