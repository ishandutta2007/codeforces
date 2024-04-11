#include <bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;

int add(int a, int b) {
  a += b;
  if (a >= M) {
    a -= M;
  }
  return a;
}

int sub(int a, int b) {
  a -= b;
  if (a < 0) {
    a += M;
  }
  return a;
}

int mul(int a, int b) {
  return 1LL * a * b % M;
}

int mod_pow(int a, int b) {
  int res = 1;
  while (b) {
    if (b % 2) {
      res = mul(res, a);
    }
    a = mul(a, a);
    b /= 2;
  }
  return res;
}

int mod_inv(int a) {
  if (a == 1) {
    return 1;
  }
  return sub(M, mul(M / a, mod_inv(M % a)));
}

int check(vector<int> a, vector<int> b) {
  int cnt = 0;
  while (!b.empty()) {
    vector<int> c = a;
    while (c.size() >= b.size()) {
      int coefficient = mul(c.back(), mod_inv(b.back()));
      for (int i = 1; i <= int(b.size()); ++i) {
        c[int(c.size()) - i] = sub(c[int(c.size()) - i], mul(coefficient, b[int(b.size()) - i]));
      }
      while (!c.empty() && c.back() == 0) {
        c.pop_back();
      }
    }
    a = b;
    b = c;
    ++cnt;
  }
  return cnt;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> a(n + 1, 1);
  vector<int> b(n, 1);
  do {
    for (int i = 0; i < n; ++i) {
      if (rand() % 2 == 1) {
        a[i] = sub(0, a[i]);
      }
    }
    for (int i = 0; i < n - 1; ++i) {
      if (rand() % 2 == 1) {
        b[i] = sub(0, a[i]);
      }
    }
  } while (check(a, b) != n);

  cout << a.size() - 1u << "\n";
  for (auto i : a) {
    cout << (i == 1 ? 1 : -1) << " ";
  }
  cout << "\n";
  cout << b.size() - 1u << "\n";
  for (auto i : b) {
    cout << (i == 1 ? 1 : -1) << " ";
  }
  cout << "\n";
}