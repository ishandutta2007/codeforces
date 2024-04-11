#include <bits/stdc++.h>
using namespace std;

const int N = 100'000;

int neg[N];
int pos[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    long long ans = LLONG_MIN;
    int cnt_n = 0;
    int cnt_p = 0;

    for (int i = 0; i < n; ++i) {
      int a;
      cin >> a;
      if (a == 0) {
        ans = 0;
      } else if (a < 0) {
        neg[cnt_n] = -a;
        ++cnt_n;
      } else {
        pos[cnt_p] = a;
        ++cnt_p;
      }
    }

    sort(neg, neg + cnt_n);
    sort(pos, pos + cnt_p);

    for (int i = 0; i <= 5; ++i) {
      if (i > cnt_n || 5 - i > cnt_p) {
        continue;
      }

      long long product = 1;
      if (i % 2 == 0) {
        for (int j = 1; j <= i; ++j) {
          product *= neg[cnt_n - j];
        }
        for (int j = 1; j <= 5 - i; ++j) {
          product *= pos[cnt_p - j];
        }
      } else {
        product = -1;
        for (int j = 0; j < i; ++j) {
          product *= neg[j];
        }
        for (int j = 0; j < 5 - i; ++j) {
          product *= pos[j];
        }
      }

      ans = max(ans, product);
    }

    cout << ans << "\n";
  }
}