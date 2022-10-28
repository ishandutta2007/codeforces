#include <bits/stdc++.h>
using namespace std;

const int B = 1000;
const double PI = acos(-1);

void fft(vector<complex<double>>& a) {
  int n = a.size();
  for (int i = 1, j = 0; i < n; ++i) {
    int k = n / 2;
    while ((j & k) > 0) {
      j ^= k;
      k /= 2;
    }
    j ^= k;

    if (i < j) {
      swap(a[i], a[j]);
    }
  }

  for (int len = 2; len <= n; len *= 2) {
    complex<double> root = polar(1.0, 2 * PI / len);
    for (int i = 0; i < n; i += len) {
      complex<double> cur = 1.0;
      for (int j = 0; j < len / 2; ++j) {
        complex<double> l = a[i + j];
        complex<double> r = a[i + j + len / 2] * cur;
        a[i + j] = l + r;
        a[i + j + len / 2] = l - r;
        cur *= root;
      }
    }
  }
}

vector<int> square(const vector<int>& u) {
  int n = 1;
  while (n < 2 * int(u.size())) {
    n *= 2;
  }

  vector<complex<double>> a(u.begin(), u.end());
  a.resize(n);
  fft(a);

  for (int i = 0; i < n; ++i) {
    a[i] *= a[i];
  }
  fft(a);

  for (complex<double>& i : a) {
    i /= n;
  }
  reverse(a.begin() + 1, a.end());

  int i = 0;
  vector<int> res;
  long long cur = 0;
  while (i < n || cur > 0) {
    if (i < n) {
      cur += a[i].real() + 0.5;
      ++i;
    }
    res.push_back(cur % B);
    cur /= B;
  }

  while (!res.empty() && res.back() == 0) {
    res.pop_back();
  }
  return res;
}

vector<int> mul(const vector<int>& a, int b) {
  int i = 0;
  int cur = 0;
  vector<int> res;
  while (i < int(a.size()) || cur > 0) {
    if (i < int(a.size())) {
      cur += a[i] * b;
      ++i;
    }
    res.push_back(cur % B);
    cur /= B;
  }
  return res;
}

bool cmp(const vector<int>& a, const vector<int>& b) {
  if (a.size() == b.size()) {
    for (int i = a.size() - 1u; i >= 0; --i) {
      if (a[i] != b[i]) {
        return a[i] < b[i];
      }
    }
  }
  return a.size() < b.size();
}

vector<int> calc(int e) {
  vector<int> res = {1};
  int i = 0;
  while ((1 << i) <= e) {
    ++i;
  }

  for (--i; i >= 0; --i) {
    res = square(res);
    if (e & (1 << i)) {
      res = mul(res, 3);
    }
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;
  int len = s.size();

  if (s == "1") {
    cout << 1 << "\n";
    exit(0);
  }

  vector<int> n;
  for (int i = len; i > 0; i -= 3) {
    int cur = 0;
    for (int j = 3; j > 0; --j) {
      if (i - j >= 0) {
        cur *= 10;
        cur += s[i - j] - '0';
      }
    }
    n.push_back(cur);
  }

  int exponent = max(0, int(len * log(10) / log(3)) - 5);
  vector<int> pow3 = calc(exponent);

  int ans = 1e8;
  for (int i = 0; i < 3; ++i) {
    int res = exponent * 3 + i * 2;
    vector<int> cur = mul(pow3, 1 << i);
    while (cmp(cur, n)) {
      cur = mul(cur, 3);
      res += 3;
    }
    ans = min(ans, res);
  }
  cout << ans << "\n";
}