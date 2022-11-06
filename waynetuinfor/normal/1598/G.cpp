#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

  auto IsPrime = [&](int x) {
    for (int p = 2; p * p <= x; ++p) {
      if (x % p == 0) return false;
    }
    return true;
  };
  
  auto GenPrime = [&]() {
    int p = uniform_int_distribution<int>(900'000'000, 1'000'000'000)(rng);
    while (!IsPrime(p)) p++;
    return p;
  };

  const int kP[2] = {GenPrime(), GenPrime()};
  string s;
  cin >> s;
  string x;
  cin >> x;
  int M = x.size();
  vector<int> xv[2];
  for (int it = 0; it < 2; ++it) {
    xv[it] = vector<int>(M);
    xv[it][0] = x[0] - '0';
    for (int i = 1; i < M; ++i) {
      xv[it][i] = (10LL * xv[it][i - 1] + (x[i] - '0')) % kP[it];
    }
  }
  int N = s.size();
  vector<int> hv[2], pw[2];
  for (int it = 0; it < 2; ++it) {
    hv[it] = vector<int>(N);
    hv[it][0] = s[0] - '0';
    for (int i = 1; i < N; ++i) {
      hv[it][i] = (10LL * hv[it][i - 1] + (s[i] - '0')) % kP[it];
    }
    pw[it] = vector<int>(N + 1, 1);
    for (int i = 1; i <= N; ++i) {
      pw[it][i] = 10LL * pw[it][i - 1] % kP[it];
    }
  }

  auto Query = [&](vector<int> h[2], int l, int r) {
    array<int, 2> res{};
    for (int it = 0; it < 2; ++it) {
      if (l == 0) {
        res[it] = h[it][r];
      } else {
        res[it] = (h[it][r] + kP[it] -
                   1LL * pw[it][r - l + 1] * h[it][l - 1] % kP[it]) %
                  kP[it];
      }
    }
    return res;
  };

  for (int i = 1; i < N; ++i) {
    if (i >= x.size()) {
      int lcp = 0;
      int L = i - x.size();
      for (int d = 20; d >= 0; --d) {
        if (lcp + (1 << d) <= x.size()) {
          auto x = Query(hv, L, L + lcp + (1 << d) - 1);
          auto y = Query(xv, 0, lcp + (1 << d) - 1);
          if (x == y) {
            lcp += (1 << d);
          }
        }
      }
      if (lcp < x.size()) {
        if (i + x.size() - lcp <= N) {
          auto L = Query(hv, i - x.size(), i - 1);
          auto R = Query(hv, i, i + x.size() - lcp - 1);
          bool ok = true;
          for (int it = 0; it < 2; ++it) {
            ok &= (L[it] + R[it]) % kP[it] == xv[it].back();
          }
          if (ok) {
            cout << i - x.size() + 1 << " " << i << "\n";
            cout << i + 1 << " " << i + x.size() - lcp << "\n";
            return 0;
          }
        }
        if (lcp + 1 < x.size()) {
          if (i + x.size() - lcp - 1 <= N) {
            auto L = Query(hv, i - x.size(), i - 1);
            auto R = Query(hv, i, i + x.size() - lcp - 2);
            bool ok = true;
            for (int it = 0; it < 2; ++it) {
              ok &= (L[it] + R[it]) % kP[it] == xv[it].back();
            }
            if (ok) {
              cout << i - x.size() + 1 << " " << i << "\n";
              cout << i + 1 << " " << i + x.size() - lcp - 1 << "\n";
              return 0;
            }
          }
        }
      }
    }
    if (i + x.size() <= N) {
      int lcp = 0;
      int L = i;
      for (int d = 20; d >= 0; --d) {
        if (lcp + (1 << d) <= x.size()) {
          auto x = Query(hv, L, L + lcp + (1 << d) - 1);
          auto y = Query(xv, 0, lcp + (1 << d) - 1);
          if (x == y) {
            lcp += (1 << d);
          }
        }
      }
      if (lcp < x.size()) {
        if (i - static_cast<int>(x.size() - lcp) >= 0) {
          auto L = Query(hv, i - (x.size() - lcp), i - 1);
          auto R = Query(hv, i, i + x.size() - 1);
          bool ok = true;
          for (int it = 0; it < 2; ++it) {
            ok &= (L[it] + R[it]) % kP[it] == xv[it].back();
          }
          if (ok) {
            cout << i - (x.size() - lcp) + 1 << " " << i << "\n";
            cout << i + 1 << " " << i + x.size() << "\n";
            return 0;
          }
        }
        if (lcp + 1 < x.size()) {
          if (i - static_cast<int>(x.size() - lcp - 1) >= 0) {
            auto L = Query(hv, i - (x.size() - lcp - 1), i - 1);
            auto R = Query(hv, i, i + x.size() - 1);
            bool ok = true;
            for (int it = 0; it < 2; ++it) {
              ok &= (L[it] + R[it]) % kP[it] == xv[it].back();
            }
            if (ok) {
              cout << i - (x.size() - lcp - 1) + 1 << " " << i << "\n";
              cout << i + 1 << " " << i + x.size() << "\n";
              return 0;
            }
          }
        }
      }
    }
    if (x.size() >= 2 && i >= x.size() - 1 && i + x.size() - 1 <= N) {
      auto L = Query(hv, i - (x.size() - 1), i - 1);
      auto R = Query(hv, i, i + (x.size() - 2));
      bool ok = true;
      for (int it = 0; it < 2; ++it) {
        ok &= (L[it] + R[it]) % kP[it] == xv[it].back();
      }
      if (ok) {
        cout << (i - (x.size() - 1) + 1) << " " << i << "\n";
        cout << i + 1 << " " << i + (x.size() - 2) + 1 << "\n";
        return 0;
      }
    }
  }
  return 0;
}