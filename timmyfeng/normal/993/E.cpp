#include <bits/stdc++.h>
using namespace std;

const long double PI = atan2l(0, -1);

void fft(vector<complex<long double>>& a) {
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
    complex<long double> root = polar(1.0L, 2 * PI / len);
    for (int i = 0; i < n; i += len) {
      complex<long double> cur = 1.0;
      for (int j = 0; j < len / 2; ++j) {
        complex<long double> l = a[i + j];
        complex<long double> r = a[i + j + len / 2] * cur;
        a[i + j] = l + r;
        a[i + j + len / 2] = l - r;
        cur *= root;
      }
    }
  }
}

vector<complex<long double>> mul(const vector<int>& u, const vector<int>& v) {
  int n = 1;
  while (n < int(u.size() + v.size())) {
    n *= 2;
  }

  vector<complex<long double>> a(u.begin(), u.end());
  vector<complex<long double>> b(v.begin(), v.end());
  a.resize(n);
  b.resize(n);
  fft(a);
  fft(b);

  for (int i = 0; i < n; ++i) {
    a[i] *= b[i];
  }
  fft(a);

  for (complex<long double>& i : a) {
    i /= n;
  }
  reverse(a.begin() + 1, a.end());
  return a;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, x;
  cin >> n >> x;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    a[i] = (a[i] < x);
  }

  int ptr = 1;
  int64_t zero = 0;
  for (int i = 1; i <= n; i = ptr) {
    while (ptr <= n && a[ptr] == a[i]) {
      ++ptr;
    }
    if (a[i] == 0) {
      zero += 1LL * (ptr - i) * (ptr - i + 1) / 2;
    }
  }
  cout << zero << " ";

  vector<int> b(n + 1);
  for (int i = 0; i <= n; ++i) {
    if (i > 0) {
      a[i] += a[i - 1];
    }
    ++b[a[i]];
  }

  vector<int> c = b;
  reverse(c.begin(), c.end());

  vector<complex<long double>> ans = mul(b, c);
  for (int i = n + 1; i <= 2 * n; ++i) {
    cout << int64_t(ans[i].real() + .5L) << " ";
  }
  cout << "\n";
}