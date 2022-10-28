#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  vector<int> cnt(101);
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    ++cnt[a];
  }

  int mx = 0;
  int dish = 0;
  for (int i = 1; i <= 100; ++i) {
    mx = max(mx, (cnt[i] - 1) / k + 1);
    dish += !!cnt[i];
  }

  cout << mx * dish * k - n << "\n";
}