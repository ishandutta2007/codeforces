#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1;
const int M = (119 << 23) + 1;

int ans[N];

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
  return mod_pow(a, M - 2);
}

void ntt(vector<int>& a) {
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

  int base = mod_pow(3, (M - 1) / n);
  for (int len = 2; len <= n; len *= 2) {
    int root = mod_pow(base, n / len);
    for (int i = 0; i < n; i += len) {
      int cur = 1;
      for (int j = 0; j < len / 2; ++j) {
        int l = a[i + j];
        int r = mul(a[i + j + len / 2], cur);
        a[i + j] = add(l, r);
        a[i + j + len / 2] = sub(l, r);
        cur = mul(cur, root);
      }
    }
  }
}

vector<int> mul(const vector<int>& u, const vector<int>& v) {
  int n = 1;
  while (n < int(u.size() + v.size())) {
    n *= 2;
  }

  vector<int> a(u.begin(), u.end());
  vector<int> b(v.begin(), v.end());
  a.resize(n);
  b.resize(n);
  ntt(a);
  ntt(b);

  vector<int> c(n);
  for (int i = 0; i < n; ++i) {
    c[i] = mul(a[i], b[i]);
  }
  ntt(c);

  int inv = mod_inv(n);
  for (int& i : c) {
    i = mul(i, inv);
  }
  reverse(c.begin() + 1, c.end());
  return c;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, x, y;
  cin >> n >> x >> y;
  vector<int> u(x + 1);
  vector<int> v(x + 1);
  for (int i = 0; i < n + 1; ++i) {
    int a;
    cin >> a;
    u[a] = 1;
    v[x - a] = 1;
  }
  vector<int> possible = mul(u, v);

  memset(ans, -1, sizeof ans);
  for (int i = 1; i <= x; ++i) {
    if (possible[x - i] != 0) {
      int len = 2 * y + 2 * i;
      for (int j = len; j < N; j += len) {
        ans[j] = len;
      }
    }
  }

  int q;
  cin >> q;
  while (q--) {
    int l;
    cin >> l;
    cout << ans[l] << " ";
  }
  cout << "\n";
}