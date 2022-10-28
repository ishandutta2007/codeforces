#include <bits/stdc++.h>
using namespace std;

const int N = 200000;

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

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (!visited[i]) {
      int j = i;
      do {
        visited[j] = true;
        j = nxt[j];
      } while (!visited[j]);
      ++ans;
    }
  }
  ans -= ans == 1;

  int parity = 1;
  for (int i = 0; i < n; ++i) {
    int b;
    cin >> b;
    parity ^= b;
  }
  ans += parity;

  cout << ans << "\n";
}