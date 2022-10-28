#include <bits/stdc++.h>
using namespace std;

const long long Q = 5'000'000'000'000'000'000LL;
const int L = 62;

vector<array<long long, 3>> ans;

void generate(long long a) {
  while (a <= Q / 2) {
    ans.push_back({1, a, a});
    a *= 2;
  }
}

void make(long long a, long long b) {
  long long cur = 0;
  for (int i = 0; i < L; ++i) {
    if ((b & (1LL << i)) > 0) {
      ans.push_back({1, cur, a << i});
      cur += a << i;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  long long x;
  cin >> x;

  ans.push_back({2, x, x});
  generate(x);

  long long k = 2;
  while (__gcd(x, x ^ (k * x)) != 1) {
    ++k;
  }

  make(x, k);
  long long y = x ^ (k * x);
  ans.push_back({2, x, k * x});
  generate(y);

  for (long long i = 0; i < x; ++i) {
    if ((y * i + 1) % x == 0) {
      long long j = (y * i + 1) / x;

      make(x, j);
      make(y, i);

      if (y * i % 2 == 0) {
        ans.push_back({2, y * i, x * j});
      } else {
        ans.push_back({1, y * i, x});
        ans.push_back({1, x * j, x});
        ans.push_back({2, y * i + x, x * j + x});
      }

      break;
    }
  }

  cout << ans.size() << "\n";
  for (auto [t, x, y] : ans) {
    if (t == 1) {
      cout << x << " + " << y << "\n";
    } else {
      cout << x << " ^ " << y << "\n";
    }
  }
}