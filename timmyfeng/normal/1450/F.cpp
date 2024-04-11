#include <bits/stdc++.h>
using namespace std;

const int N = 100000;

int freq[N], a[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      --a[i];
    }

    int ans = 0;
    fill(freq, freq + n, 0);
    ++freq[a[0]], ++freq[a[n - 1]];
    for (int i = 1; i < n; ++i) {
      if (a[i] == a[i - 1]) {
        freq[a[i]] += 2;
        ++ans;
      }
    }

    int big = max_element(freq, freq + n) - freq;
    for (int i = 1; i < n && freq[big] > ans + 2; ++i) {
      if (a[i] != a[i - 1] && a[i] != big && a[i - 1] != big) {
        ++ans;
      }
    }

    cout << (freq[big] > ans + 2 ? -1 : ans) << "\n";
  }
}