/**
 *    author:  tourist
 *    created: 27.05.2018 18:26:43       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  long long L;
  cin >> n >> L;
  vector<long long> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  for (int rot = 0; rot < 5; rot++) {
    for (int i = 0; i < n; i++) {
      a.push_back(a[i] + L * (rot + 1));
    }
    for (int i = 0; i < n; i++) {
      b.push_back(b[i] + L * (rot + 1));
    }
  }
  long long low = 0, high = L - 1;
  while (low < high) {
    long long mid = (low + high) >> 1;
    int j1 = 0, j2 = 0;
    int found = 0;
    int max_diff = (int) -1e9;
    for (int i = 2 * n; i < 4 * n; i++) {
      while (b[j1] < a[i] - mid) {
        j1++;
      }
      while (b[j2] <= a[i] + mid) {
        j2++;
      }
      max_diff = max(max_diff, j1 - i);
      if (j2 - i - 1 < max_diff) {
        found = 1;
        break;
      }
    }
    if (found) {
      low = mid + 1;
    } else {
      high = mid;
    }
  }
  cout << low << '\n';
  return 0;
}