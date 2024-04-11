#include <bits/stdc++.h>
using namespace std;

const int N = 1'000'000;
const int L = 21;

int last[1 << L][2];
int a[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < (1 << L); ++i) {
    for (int j = 0; j < 2; ++j) {
      last[i][j] = -1;
    }
  }

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    last[a[i]][1] = last[a[i]][0];
    last[a[i]][0] = i;
  }

  for (int i = 0; i < L; ++i) {
    for (int j = 0; j < (1 << L); ++j) {
      if ((j & (1 << i)) > 0) {
        int k = j ^ (1 << i);
        if (last[j][0] > last[k][0]) {
          last[k][1] = max(last[k][0], last[j][1]);
          last[k][0] = last[j][0];
        } else {
          last[k][1] = max(last[k][1], last[j][0]);
        }
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < n - 2; ++i) {
    int mask = 0;
    for (int j = L - 1; j >= 0; --j) {
      if ((a[i] & (1 << j)) > 0) {
        continue;
      }
      mask ^= (last[mask ^ (1 << j)][1] > i) << j;
    }
    ans = max(ans, a[i] | mask);
  }

  cout << ans << "\n";
}