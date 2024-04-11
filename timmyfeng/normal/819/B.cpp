#include <bits/stdc++.h>
using namespace std;

const int N = 1'000'000 + 1;

int event[N];
int a[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int delta = 0;
  long long sum = 0;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    --a[i];

    if (a[i] > i) {
      event[a[i] - i] += 2;
      sum += a[i] - i;
      --delta;
    } else {
      event[a[i] - i + n] += 2;
      sum += i - a[i];
      ++delta;
    }
  }

  long long ans = sum;
  int ndx = 0;

  for (int j = 1; j < n; ++j) {
    sum -= n - 1 - a[n - j];
    sum += a[n - j];

    --delta;
    sum += delta;
    --delta;

    if (sum < ans) {
      ans = sum;
      ndx = j;
    }
    delta += event[j];
  }

  cout << ans << " " << ndx << "\n";
}