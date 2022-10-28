#include <bits/stdc++.h>
using namespace std;

const int N = 200000 + 1;

vector<int> queries[N];
int maxi[N], a[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  for (int i = 1; i < n; ++i) {
    queries[__gcd(i, n)].push_back(i);
  }

  long long ans = 0;
  for (int k = 1; k < n; ++k) {
    if (n % k == 0) {
      fill(maxi, maxi + k, 0);
      for (int i = 0; i < n; ++i) {
        maxi[i % k] = max(maxi[i % k], a[i]);
      }

      int sum = 0;
      vector<int> segments;
      for (int i = 0, j = 0; i < n; i = j) {
        if (a[i] < maxi[i % k]) {
          ++j;
        } else {
          for ( ; j < n && a[j] == maxi[j % k]; ++j);
          segments.push_back(j - i);
          sum += j - i;
        }
      }

      if (segments.size() == 1 && segments[0] == n) {
        ans += (long long) n * queries[k].size();
      } else {
        if (a[n - 1] == maxi[(n - 1) % k] && a[0] == maxi[0]) {
          segments[0] += segments.back();
          segments.pop_back();
        }
        sort(segments.rbegin(), segments.rend());

        for (auto i : queries[k]) {
          while (!segments.empty() && segments.back() < i) {
            sum -= segments.back();
            segments.pop_back();
          }
          ans += sum - segments.size() * (i - 1);
        }
      }
    }
  }

  cout << ans << "\n";
}