#include <bits/stdc++.h>

using namespace std;

void run_case() {

  int N;
  cin >> N;
  string S;
  cin >> S;
  vector<bool> was(26, false);

  bool ok = true;
  for (int i = 0; i < N; i++) {
    if (was[S[i] - 'A'] && (i > 0 && S[i - 1] != S[i])) {
      ok = false;
    }
    was[S[i] - 'A'] = true;
  }
  cout << (ok ? "YES" : "NO") << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int tests;
  cin >> tests;
  while (tests-- > 0)
    run_case();
    return 0;
}