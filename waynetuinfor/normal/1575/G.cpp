#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  vector<int> A(N + 1);
  for (int i = 1; i <= N; ++i) {
    cin >> A[i];
  }
  constexpr int kP = 1'000'000'000 + 7;
  constexpr int kC = 100'000;
  vector<int> dp(kC + 1);
  vector<int> cnt(kC + 1);
  vector<vector<int>> dv(kC + 1);
  vector<bool> used(kC + 1);
  vector<vector<pair<int, int>>> res(kC + 1);
  for (int i = 1; i <= kC; ++i) {
    for (int j = i; j <= kC; j += i) {
      dv[j].push_back(i);
    }
  }
  vector<int> vec;
  vector<int> dvec;
  vector<int> vc(kC + 1);

  auto Phi = [&](int x) {
    int phi = 1;
    for (int p = 2; p * p <= x; ++p) {
      if (x % p == 0) {
        while (x % p == 0) {
          x /= p;
          phi *= p;
        }
        phi /= p;
        phi *= (p - 1);
      }
    }
    if (x > 1) {
      phi *= (x - 1);
    }
    return phi;
  };

  for (int i = 1; i <= N; ++i) {
    for (int j = i; j <= N; j += i) {
      if (cnt[A[j]]++ == 0) {
        vec.push_back(A[j]);
      }
    }
    for (int u : vec) {
      for (int d : dv[u]) {
        dp[d] += cnt[u];
        if (!used[d]) {
          used[d] = true;
          dvec.push_back(d);
        }
      }
    }
    int phi = Phi(i);
    for (int d : dvec) {
      vc[d] += 1LL * dp[d] * dp[d] % kP * phi % kP;
      vc[d] %= kP;
      used[d] = false;
      dp[d] = 0;
      cnt[d] = 0;
    }
    vec.clear();
    dvec.clear();
  }
  for (int i = kC; i > 0; --i) {
    for (int j = i + i; j <= kC; j += i) {
      vc[i] += kP - vc[j];
      vc[i] %= kP;
    }
  }
  int ans = 0;
  for (int i = 1; i <= kC; ++i) {
    ans += 1LL * i * vc[i] % kP;
    ans %= kP;
  }
  cout << ans << "\n";
  return 0;
}