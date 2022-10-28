#include <bits/stdc++.h>
using namespace std;

const int N = 200000;

int freq[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, s;
  cin >> n >> s;
  --s;

  int offset = 0;
  int free = 0;

  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;

    if ((i == s) ^ (a == 0)) {
      if (a == 0) {
        ++free;
      } else {
        ++offset;
        ++freq[0];
      }
    } else {
      ++freq[a];
    }
  }

  if (n == 1) {
    cout << offset << "\n";
    exit(0);
  }

  int skipped = count(freq, freq + n, 0);
  int ans = n;

  for (int i = n - 1; i > 0; --i) {
    ans = min(ans, free + max(0, skipped - free));
    skipped -= freq[i] == 0;
    free += freq[i];
  }

  cout << ans + offset << "\n";
}