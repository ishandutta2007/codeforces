#include <bits/stdc++.h>
using namespace std;

using matrix = vector<vector<int>>;

const int N = 100;
const int M = 1e9 + 7;

int points[N];
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

int mod_inv(int a) {
  if (a == 1) {
    return 1;
  }
  return sub(M, mul(M / a, mod_inv(M % a)));
}

int determinant(matrix a) {
  int res = 1;
  int n = a.size();

  for (int i = 0; i < n; ++i) {
    bool ok = false;
    for (int j = i; j < n; ++j) {
      if (a[j][i] != 0) {
        if (j != i) {
          swap(a[i], a[j]);
          res = sub(0, res);
        }
        ok = true;
        break;
      }
    }

    if (!ok) {
      return 0;
    }

    res = mul(res, a[i][i]);
    int inv = mod_inv(a[i][i]);
    for (int j = i; j < n; ++j) {
      a[i][j] = mul(a[i][j], inv);
    }

    for (int j = i + 1; j < n; ++j) {
      for (int k = n - 1; k >= i; --k) {
        a[j][k] = sub(a[j][k], mul(a[j][i], a[i][k]));
      }
    }
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<array<int, 2>> edges;
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    edges.push_back({u - 1, v - 1});
  }

  matrix laplacian(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      laplacian[i][j] = (i == j ? n - 1 : sub(0, 1));
    }
  }

  for (int i = 1; i <= n; ++i) {
    matrix minor = laplacian;
    minor.pop_back();
    for (auto& j : minor) {
      j.pop_back();
    }
    points[i] = determinant(minor);

    for (auto [u, v] : edges) {
      for (int k = 0; k < 2; ++k) {
        laplacian[u][u] = add(laplacian[u][u], 1);
        laplacian[u][v] = sub(laplacian[u][v], 1);
        swap(u, v);
      }
    }
  }

  for (int i = 1; i <= n; ++i) {
    int coefficient = 1;
    vector<int> numerator = {1};
    for (int j = 1; j <= n; ++j) {
      if (i != j) {
        coefficient = mul(coefficient, sub(i, j));
        numerator.insert(numerator.begin(), 0);
        for (int k = 0; k < int(numerator.size()) - 1; ++k) {
          numerator[k] = sub(numerator[k], mul(j, numerator[k + 1]));
        }
      }
    }
    coefficient = mul(points[i], mod_inv(coefficient));

    for (int j = 0; j < n; ++j) {
      ans[j] = add(ans[j], mul(coefficient, numerator[j]));
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << ans[i] << " ";
  }
  cout << "\n";
}