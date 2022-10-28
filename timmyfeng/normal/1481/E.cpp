#include <bits/stdc++.h>
using namespace std;

const int N = 500000 + 1;

int last[N], first[N], freq[N], stay[N], suffix[N], a[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  fill(first, first + n, -1);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    last[--a[i]] = i;
    if (first[a[i]] == -1) {
      first[a[i]] = i;
    }
  }

  for (int i = n - 1; i >= 0; --i) {
    suffix[i] = max(suffix[i + 1], ++freq[a[i]]);
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    stay[i + 1] = max(stay[i + 1], stay[i]);
    if (first[a[i]] == i) {
      stay[last[a[i]] + 1] = max(stay[last[a[i]] + 1], stay[i] + freq[a[i]]);
    }
    ans = max(ans, stay[i] + suffix[i]);
  }

  cout << n - ans << "\n";
}