#include <bits/stdc++.h>
using namespace std;

void pre_sumify(vector<long long>& a) {
  sort(a.rbegin(), a.rend() - 1);
  for (int i = 1; i < int(a.size()); ++i) {
    a[i] += a[i - 1];
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, d, m;
  cin >> n >> d >> m;

  vector<long long> a = {0};
  vector<long long> b = {0};

  for (int i = 0; i < n; ++i) {
    int c;
    cin >> c;
    if (c > m) {
      b.push_back(c);
    } else {
      a.push_back(c);
    }
  }

  pre_sumify(a);
  pre_sumify(b);

  long long ans = 0;
  for (int i = 0; i <= (n - 1) / (d + 1) + 1 && i < int(b.size()); ++i) {
    ans = max(ans, a[min(int(a.size()) - 1, n - max(0, (i - 1) * (d + 1) + 1))] + b[i]);
  }
  cout << ans << "\n";
}