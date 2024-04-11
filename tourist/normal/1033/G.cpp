/**
 *    author:  tourist
 *    created: 07.10.2018 21:17:00       
**/
#undef _GLIBCXX_DEBUG

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<long long> V(n);
  for (int i = 0; i < n; i++) {
    cin >> V[i];
  }
  long long wa = 0, wb = 0, wf = 0, ws = 0;
  vector<int> v(n + 1);
  for (int sum = 2; sum <= 2 * m; sum++) {
    for (int i = 0; i < n; i++) {
      v[i] = (int) (V[i] % sum);
    }
    v[n] = 0;
    sort(v.rbegin(), v.rend());
    int low = 0, high = sum;
    while (low < high) {
      int mid = (low + high + 1) >> 1;
      int a = mid;
      int b = sum - mid;
      int win = -1;
      for (int i = 0; i <= n; i++) {
        if (v[i] >= 2 * a) {
          win = (i & 1) ^ 1;
          break;
        }
        if (v[i] < a) {
          win = i & 1;
          break;
        }
        swap(a, b);
      }
      if (win) {
        low = mid;
      } else {
        high = mid - 1;
      }
    }
    int len = m - abs(sum - (m + 1));
    int c = max(0, min(low - (sum <= m + 1 ? 0 : (sum - (m + 1))), len));
    if (c + c <= len) {
      wa += c;
      wb += c;
      ws += len - c - c;
    } else {
      int x = c + c - len;
      wa += c - x;
      wb += c - x;
      wf += x;
    }
  }
  cout << wa << " " << wb << " " << wf << " " << ws << '\n';
  return 0;
}