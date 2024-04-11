#include <bits/stdc++.h>
using namespace std;

const int N = 100000 + 1;

bool parity[N], visited[N];
int perm[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 1; i <= n; ++i) {
    cin >> perm[i];

    if (i == perm[i]) {
      cout << "YES\n";
      for (int j = 1; j <= n; ++j) {
        if (i != j) {
          cout << i << " " << j << "\n";
        }
      }
      exit(0);
    }
  }

  int u = 0, v = 0;
  for (int i = 1; i <= n; ++i) {
    if (!visited[i]) {
      int j = i, length = 0;
      while (!visited[j]) {
        parity[perm[j]] = parity[j] ^ true;
        visited[j] = true;
        j = perm[j];
        ++length;
      }

      if (length == 2) {
        u = i, v = perm[i];
      } else if (length % 2 != 0) {
        cout << "NO\n";
        exit(0);
      }
    }
  }

  if (u == 0) {
    cout << "NO\n";
    exit(0);
  }

  cout << "YES\n";
  cout << u << " " << v << "\n";
  for (int i = 1; i <= n; ++i) {
    if (i != u && i != v) {
      cout << (parity[i] ? u : v) << " " << i << "\n";
    }
  }
}