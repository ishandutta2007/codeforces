/**
 *    author:  tourist
 *    created: 30.12.2018 17:50:52
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> d(n);
  for (int i = 0; i < n; i++) {
    cin >> d[i];
  }
  sort(d.begin(), d.end());
  vector<long long> pref(n + 1);
  for (int i = 0; i < n; i++) {
    pref[i + 1] = pref[i] + d[i];
  }
  vector<int> bal(n + 2);
  int j = 0;
  for (int k = 1; k <= n; k++) {
    long long L = pref[n] - pref[n - k];
    long long R = (long long) k * (k - 1);
    while (j < n && d[j] < k) {
      j++;
    }
    int up = min(n - k, j);
    R += pref[up] + (long long) k * ((n - k) - up);
    int bound = d[n - k];
    { // <= bound
      long long diff = L - R;
      if (diff <= k && diff <= bound) {
        bal[max(diff, 0LL)]++;
        bal[bound + 1]--;
      }
    }
    { // > bound
      L -= d[n - k];
      R += min(d[n - k], k);
      long long diff = R - L;
      if (diff >= bound + 1) {
        bal[bound + 1]++;
        bal[min(diff + 1, n + 1LL)]--;
      }
    }
  }
  vector<int> res;
  int B = 0;
  for (int i = 0; i <= n; i++) {
    B += bal[i];
    if (B == n) {
      if ((pref[n] + i) % 2 == 0) {
        res.push_back(i);
      }
    }
  }
  if (res.empty()) {
    cout << -1 << '\n';
  } else {
    int sz = (int) res.size();
    for (int i = 0; i < sz; i++) {
      if (i > 0) {
        cout << " ";
      }
      cout << res[i];
    }
    cout << '\n';
  }
  return 0;
}