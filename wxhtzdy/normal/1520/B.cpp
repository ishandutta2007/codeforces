#include <bits/stdc++.h>

using namespace std;

void run_case() {

  long long N;
  cin >> N;
  int ans = 0;
  for (int i = 1; i <= 9; i++) {
    long long curr = 0;
    for (int j = 1; j <= 9; j++) {
      curr = curr * 10 + i;
      ans += (curr <= N ? 1 : 0);
    }
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