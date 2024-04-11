#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
      cin >> a[i];
    }
    int ans = 0;
    for (int i = 0, j = 0; i < N; i = j) {
      if (a[i] == 0) {
        j = i + 1;
      } else {
        while (j < N && a[j] > 0) j++;
        ans++;
      }
    }
    cout << min(ans, 2) << "\n";
  }
}