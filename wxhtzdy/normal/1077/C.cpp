#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  map<long long, int> cnt;
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cnt[(long long) a[i]] += 1;
    sum += a[i];
  }
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    long long need = (sum - a[i]) / 2;
    cnt[a[i]] -= 1;
    if (need * 2 == (sum - a[i]) && cnt[need] > 0) {
      ans.push_back(i);
    }
    cnt[a[i]] += 1;
  }
  cout << ans.size() << '\n';
  for (int i = 0; i < (int) ans.size(); i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << ans[i] + 1;
  }
  cout << '\n';
  return 0;
}