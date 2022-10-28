#include <bits/stdc++.h>
using namespace std;

const int N = 200000;
const int M = 998244353;

bool save[N];
int where[N];
int b[N];

void solve() {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    where[a - 1] = i;
  }

  for (int i = 0; i < m; ++i) {
    cin >> b[i];
    b[i] = where[b[i] - 1];
    save[b[i]] = true;
  }

  int ans = 1;
  for (int i = 0; i < m; ++i) {
    int count = (b[i] > 0 && !save[b[i] - 1]) + (b[i] < n - 1 && !save[b[i] + 1]);
    save[b[i]] = false;
    ans = ans * count % M;
  }

  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }
}