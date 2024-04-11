#include <bits/stdc++.h>
using namespace std;

const int N = 100;

bool visited[N];
int nxt[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> nxt[i];
    --nxt[i];
  }

  long long ans = 1;

  for (int i = 0; i < n; ++i) {
    if (!visited[i] && nxt[i] != i) {
      int cycle = 0;
      int j = i;

      while (!visited[j]) {
        visited[j] = true;
        j = nxt[j];
        ++cycle;
      }

      if (j != i) {
        cout << -1 << "\n";
        exit(0);
      }

      if (cycle % 2 == 0) {
        cycle /= 2;
      }

      ans *= cycle / __gcd(ans, (long long) cycle);
    }
  }

  cout << ans << "\n";
}