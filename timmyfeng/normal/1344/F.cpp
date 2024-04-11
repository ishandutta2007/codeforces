#include <bits/stdc++.h>
using namespace std;

const int N = 2000;

int a[N][2][2], value[N], ans[N], n;
bitset<N> mask[2], basis[N];

void update(bitset<N> v, int x) {
  for (int i = 0; i < 2 * n; ++i) {
    if (v[i]) {
      if (basis[i].any()) {
        v ^= basis[i];
        x ^= value[i];
      } else {
        basis[i] = v;
        value[i] = x;
        return;
      }
    }
  }

  if (x != 0) {
    cout << "NO\n";
    exit(0);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int k;
  cin >> n >> k;

  for (int i = 0; i < n; ++i) {
    a[i][0][0] = a[i][1][1] = 1;
  }

  for (int i = 0; i < k; ++i) {
    int m;
    string type;
    cin >> type >> m;
    vector<int> j(m);
    for (auto &l : j) {
      cin >> l;
      --l;
    }

    if (type == "mix") {
      char c;
      cin >> c;

      mask[0].reset(), mask[1].reset();
      for (auto l : j) {
        for (int u = 0; u < 2; ++u) {
          for (int v = 0; v < 2; ++v) {
            mask[u][2 * l + v] = a[l][u][v];
          }
        }
      }

      update(mask[0], c == 'R' || c == 'B');
      update(mask[1], c == 'Y' || c == 'B');
    } else {
      if (type == "RY") {
        for (auto l : j) {
          swap(a[l][0][0], a[l][1][0]);
          swap(a[l][0][1], a[l][1][1]);
        }
      } else if (type == "RB") {
        for (auto l : j) {
          a[l][1][0] ^= a[l][0][0];
          a[l][1][1] ^= a[l][0][1];
        }
      } else {
        for (auto l : j) {
          a[l][0][0] ^= a[l][1][0];
          a[l][0][1] ^= a[l][1][1];
        }
      }
    }
  }

  for (int i = 2 * n - 1; i >= 0; --i) {
    for (int j = 0; j < i; ++j) {
      if (basis[j][i]) {
        basis[j] ^= basis[i];
        value[j] ^= value[i];
      }
    }
    ans[i] = value[i];
  }

  cout << "YES\n";
  for (int i = 0; i < n; ++i) {
    if (ans[2 * i + 1] == 0) {
      cout << (ans[2 * i] == 0 ? '.' : 'R');
    } else {
      cout << (ans[2 * i] == 0 ? 'Y' : 'B');
    }
  }
  cout << "\n";
}