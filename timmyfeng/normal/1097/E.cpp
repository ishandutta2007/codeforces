#include <bits/stdc++.h>
using namespace std;

const int N = 100'000 + 1;

int a[N];

vector<int> lis[N];
vector<int> ans[N];
bool used[N];
int prv[N];

void solve() {
  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    --a[i];
  }

  int f = 0;
  while ((f + 1) * (f + 2) / 2 <= n) {
    ++f;
  }

  fill(ans, ans + f, vector<int>());
  fill(used, used + n, false);

  int k = 0;
  while (count(used, used + n, true) < n) {
    fill(lis, lis + n + 1, vector<int>());
    lis[0] = {-1};

    int length = 0;
    for (int i = 0; i < n; ++i) {
      if (!used[a[i]]) {
        int lo = 0;
        int hi = length + 1;
        while (lo < hi) {
          int mid = (lo + hi) / 2;
          if (lis[mid].back() < a[i]) {
            lo = mid + 1;
          } else {
            hi = mid;
          }
        }

        lis[lo].push_back(a[i]);
        length = max(length, lo);
        prv[a[i]] = lis[lo - 1].back();
      }
    }

    if (k + length <= f) {
      for (int i = 1; i <= length; ++i) {
        ans[k++] = lis[i];
        for (auto j : lis[i]) {
          used[j] = true;
        }
      }
      break;
    }

    int i = lis[length].back();
    for (int j = 0; j < length; ++j) {
      ans[k].push_back(i);
      used[i] = true;
      i = prv[i];
    }
    reverse(ans[k].begin(), ans[k].end());
    ++k;
  }

  cout << k << "\n";
  for (int i = 0; i < k; ++i) {
    cout << ans[i].size() << " ";
    for (auto j : ans[i]) {
      cout << j + 1 << " ";
    }
    cout << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }
}