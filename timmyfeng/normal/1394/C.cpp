#include <bits/stdc++.h>
using namespace std;

const int A = 5e5;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<array<int, 2>> points;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    int cnt = count(s.begin(), s.end(), 'B');
    points.push_back({cnt, int(s.size()) - cnt});
  }

  int ans_x = 0;
  int ans_y = 0;

  int lo = 0;
  int hi = A;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;

    int mn_x = 0;
    int mx_x = A;
    int mn_y = 0;
    int mx_y = A;
    int mn_d = -A;
    int mx_d = A;

    for (auto [x, y] : points) {
      mn_x = max(mn_x, x - mid);
      mx_x = min(mx_x, x + mid);
      mn_y = max(mn_y, y - mid);
      mx_y = min(mx_y, y + mid);
      mn_d = max(mn_d, y - x - mid);
      mx_d = min(mx_d, y - x + mid);
    }

    bool ok = false;
    for (int i = mn_x; i <= mx_x; ++i) {
      int l = max(mn_y, mn_d + i);
      int r = min(mx_y, mx_d + i);
      if (i == 0) {
        l = max(1, l);
      }

      if (l <= r) {
        ans_x = i;
        ans_y = l;
        ok = true;
        break;
      }
    }

    if (ok) {
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }

  cout << lo << "\n";
  cout << string(ans_x, 'B') << string(ans_y, 'N') << "\n";
}