#include <bits/stdc++.h>
using namespace std;

const int M = 1000000007;

int calc(int c1, int c2) {
  return (c2 >= c1) ? c2 : c2 + 2 * (c1 - c2) / 3;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> nxt(n);
    for (auto &i : nxt) {
      cin >> i;
      --i;
    }

    int swaps = 0, ones = 0;
    vector<bool> visited(n);
    vector<int> c(3);

    for (int i = 0; i < n; ++i) {
      if (!visited[i]) {
        int j = i, length = 0;
        while (!visited[j]) {
          visited[j] = true;
          j = nxt[j];
          ++length;
        }

        swaps += (length - 1) / 3;
        ones += (length == 1);
        ++c[length % 3];
      }
    }

    if (n % 3 == 0) {
      swaps += calc(c[1], c[2]);
    } else if (n % 3 == 1) {
      swaps += min({
          (c[1] - ones > 0) ? calc(c[1] - 1, c[2]) - 1 : INT_MAX,
          (c[1] > 0 && c[0] > 0) ? calc(c[1] - 1, c[2]) + 1 : INT_MAX,
          (c[1] >= 4) ? calc(c[1] - 4, c[2]) + 2 : INT_MAX,
          (c[2] >= 2) ? calc(c[1], c[2] - 2) : INT_MAX,
          (c[1] >= 2 && c[2] > 0) ? calc(c[1] - 2, c[2] - 1) + 1 : INT_MAX
      });
    } else if (n % 3 == 2) {
      swaps += min(
          (c[2] >= 1) ? calc(c[1], c[2] - 1) : INT_MAX,
          (c[1] >= 2) ? calc(c[1] - 2, c[2]) + 1 : INT_MAX
      );
    }

    int days = 1;
    while (n > 4) {
      days = 3LL * days % M;
      n -= 3;
    }
    days = (long long) n * days % M;

    cout << days << " " << swaps << "\n";
  }
}