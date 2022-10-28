#include <bits/stdc++.h>
using namespace std;

const int N = 100'000;

bool open[N];
int a[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    open[i] = (a[i] > 0);
  }

  int one = 0;
  vector<array<int, 2>> ans;
  for (int i = 0; i < n; ++i) {
    one = max(one, i + 1);
    while (one < n && a[one] != 1) {
      ++one;
    }

    if (a[i] == 1) {
      ans.push_back({i, i});
    } else if (a[i] == 2) {
      if (one == n) {
        cout << -1 << "\n";
        exit(0);
      } else {
        ans.push_back({one, i});
        open[one++] = false;
      }
    }
  }

  int nxt = 0;
  for (int i = 0; i < n; ++i) {
    nxt = max(nxt, i + 1);
    while (nxt < n && !open[nxt]) {
      ++nxt;
    }

    if (a[i] == 3) {
      if (nxt == n) {
        cout << -1 << "\n";
        exit(0);
      } else {
        ans.push_back({i, i});
        ans.push_back({i, nxt++});
      }
    }
  }

  cout << ans.size() << "\n";
  for (auto [r, c] : ans) {
    cout << r + 1 << " " << c + 1 << "\n";
  }
}