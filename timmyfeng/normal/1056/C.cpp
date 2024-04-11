#include <bits/stdc++.h>
using namespace std;

const int N = 2'000;

bool chosen[N];
int indices[N];
int power[N];
int match[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < 2 * n; ++i) {
    cin >> power[i];
  }

  iota(indices, indices + 2 * n, 0);
  sort(indices, indices + 2 * n, [&](int a, int b) {
    return power[a] > power[b];
  });

  fill(match, match + 2 * n, -1);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    match[a] = b;
    match[b] = a;
  }

  int t;
  cin >> t;

  int nxt1 = 0;
  int nxt0 = 0;
  int x = -1;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 2; ++j) {
      if (t == 1) {
        while (nxt1 < 2 * n && (chosen[indices[nxt1]] || match[indices[nxt1]] == -1)) {
          ++nxt1;
        }
        while (nxt0 < 2 * n && chosen[indices[nxt0]]) {
          ++nxt0;
        }

        if (x == -1) {
          if (nxt1 < 2 * n) {
            x = indices[nxt1];
          } else {
            x = indices[nxt0];
          }
        }

        chosen[x] = true;
        cout << x + 1 << endl;
        x = -1;
      } else {
        int y;
        cin >> y;
        chosen[--y] = true;
        if (match[y] != -1 && !chosen[match[y]]) {
          x = match[y];
        }
      }

      t = 3 - t;
    }
  }
}