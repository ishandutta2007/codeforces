#include <bits/stdc++.h>
using namespace std;

const int N = 5000;

int ans[N];
int a[N];
int b[N];
int p[N];
int q[N];

int query(int i, int j) {
  cout << "? " << i << " " << j << endl;
  int res;
  cin >> res;
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    a[i] = query(i, i);
  }

  for (int i = 0; i + 1 < n; ++i) {
    b[i] = query(i + 1, i);
  }

  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    p[0] = i;
    for (int j = 0; j + 1 < n; ++j) {
      q[j] = p[j] ^ a[j];
      p[j + 1] = q[j] ^ b[j];
    }
    q[n - 1] = p[n - 1] ^ a[n - 1];

    bool ok = true;
    for (int j = 0; j < n; ++j) {
      ok &= (p[q[j]] == j);
    }

    if (ok) {
      copy(p, p + n, ans);
      ++cnt;
    }
  }

  cout << "!\n";
  cout << cnt << "\n";
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << " ";
  }
  cout << "\n";
}