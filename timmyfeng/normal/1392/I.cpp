#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

using point = complex<double>;

void fft(vector<point>& a) {
  int n = a.size();
  vector<int> reverse(n);
  for (int i = 1; i < n; ++i) {
    reverse[i] = (reverse[i >> 1] >> 1) | ((i & 1) << (__lg(n) - 1));
  }

  for (int i = 0; i < n; ++i) {
    if (i < reverse[i]) {
      swap(a[i], a[reverse[i]]);
    }
  }

  for (int len = 1; len < n; len *= 2) {
    point root = polar(1.0, M_PI / len);
    for (int i = 0; i < n; i += 2 * len) {
      point cur = 1.0;
      for (int j = 0; j < len; ++j) {
        point l = a[i + j], r = a[i + j + len] * cur;
        a[i + j] = l + r;
        a[i + j + len] = l - r;
        cur *= root;
      }
    }
  }
}

vector<point> mul(vector<point> a, vector<point> b) {
  int n = 1, m = a.size() + b.size();
  while (n < m) {
    n *= 2;
  }

  a.resize(n), b.resize(n);
  fft(a), fft(b);

  for (int i = 0; i < n; ++i) {
    a[i] *= b[i];
  }
  fft(a);

  for (auto &i : a) {
    i /= n;
  }
  reverse(a.begin() + 1, a.end());

  a.resize(m - 1);
  return a;
}

const int N = 100000;

int a[N], b[N];

vector<long long> mul(vector<long long> a, vector<long long> b) {
  vector<point> c = mul(
    vector<point>(a.begin(), a.end()),
    vector<point>(b.begin(), b.end())
  );

  vector<long long> res(c.size());
  for (int i = 0; i < (int) c.size(); ++i) {
    res[i] = (long long) (c[i].real() + 0.5);
  }
  return res;
}

vector<long long> add(vector<long long> a, vector<long long> b) {
  vector<long long> res(a.size());
  for (int i = 0; i < (int) a.size(); ++i) {
    res[i] = a[i] + b[i];
  }
  return res;
}

void prefix_sum(vector<long long> &a) {
  for (int i = 1; i < (int) a.size(); ++i) {
    a[i] += a[i - 1];
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, q;
  cin >> n >> m >> q;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }

  vector<long long> freq_r(N + 1), maxi_r(N + 1), mini_r(N + 1);
  for (int i = 0; i < n; ++i) {
    if (i > 0) {
      ++maxi_r[max(a[i - 1], a[i])];
      ++mini_r[min(a[i - 1], a[i])];
    }
    ++freq_r[a[i]];
  }

  vector<long long> freq_c(N + 1), maxi_c(N + 1), mini_c(N + 1);
  for (int i = 0; i < m; ++i) {
    if (i > 0) {
      ++maxi_c[max(b[i - 1], b[i])];
      ++mini_c[min(b[i - 1], b[i])];
    }
    ++freq_c[b[i]];
  }

  vector<long long> edges_h = add(mul(mini_r, freq_c), mul(freq_r, mini_c));
  vector<long long> edges_c = add(mul(maxi_r, freq_c), mul(freq_r, maxi_c));
  vector<long long> vertices = mul(freq_r, freq_c);
  vector<long long> faces_h = mul(mini_r, mini_c);
  vector<long long> faces_c = mul(maxi_r, maxi_c);

  prefix_sum(vertices);
  prefix_sum(edges_h);
  prefix_sum(edges_c);
  prefix_sum(faces_h);
  prefix_sum(faces_c);

  while (q--) {
    int x;
    cin >> x;

    long long ans = 0;

    ans += vertices[2 * N] - vertices[x - 1];
    ans += faces_h[2 * N] - faces_h[x - 1];
    ans -= edges_h[2 * N] - edges_h[x - 1];

    ans -= vertices[x - 1];
    ans -= faces_c[x - 1];
    ans += edges_c[x - 1];

    cout << ans << "\n";
  }
}