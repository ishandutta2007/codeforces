#include <bits/stdc++.h>
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::string S;
  std::cin >> S;
  int N = S.size();
  int l = 0, r = N;
  std::string pref;
  while (l + 4 <= r) {
    bool taken = false;
    for (int i : {l, l + 1}) {
      if (taken) break;
      for (int j : {r - 1, r - 2}) {
        if (S[i] == S[j]) {
          pref += S[i];
          taken = true;
          break;
        }
      }
    }
    l += 2;
    r -= 2;
  }
  std::string T = pref;
  if (l < r) {
    T += S[l];
  }
  T.insert(T.end(), pref.rbegin(), pref.rend());
  std::cout << T << '\n';
  assert(T.size() >= S.size() / 2);
  exit(0);
}