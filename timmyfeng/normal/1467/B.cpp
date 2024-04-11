#include <bits/stdc++.h>
using namespace std;

const int N = 300000;

int a[N];
int n, sum;

void update(int i, int k) {
  if (i > 0 && i < n - 1) {
    if ((a[i - 1] < a[i] && a[i] > a[i + 1]) || (a[i - 1] > a[i] && a[i] < a[i + 1])) {
      sum += k;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }

    sum = 0;
    for (int i = 0; i < n; ++i) {
      update(i, 1);
    }

    int ans = sum;
    for (int i = 1; i < n; ++i) {
      int prv_a = a[i], prv_s = sum;
      for (int j = i - 1; j <= i + 1; ++j) {
        update(j, -1);
      }
      a[i] = a[i - 1];
      for (int j = i - 1; j <= i + 1; ++j) {
        update(j, 1);
      }
      ans = min(ans, sum);
      a[i] = prv_a;
      sum = prv_s;
    }

    for (int i = 0; i < n - 1; ++i) {
      int prv_a = a[i], prv_s = sum;
      for (int j = i - 1; j <= i + 1; ++j) {
        update(j, -1);
      }
      a[i] = a[i + 1];
      for (int j = i - 1; j <= i + 1; ++j) {
        update(j, 1);
      }
      ans = min(ans, sum);
      a[i] = prv_a;
      sum = prv_s;
    }

    cout << ans << "\n";
  }
}