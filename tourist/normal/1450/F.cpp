/**
 *    author:  tourist
 *    created: 06.12.2020 18:07:32       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      --a[i];
    }
    vector<int> cnt(n);
    cnt[a[0]] += 1;
    cnt[a[n - 1]] += 1;
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
      if (a[i] == a[i + 1]) {
        cnt[a[i]] += 1;
        cnt[a[i + 1]] += 1;
        ++ans;
      }
    }
    int total = accumulate(cnt.begin(), cnt.end(), 0) / 2;
    int id = (int) (max_element(cnt.begin(), cnt.end()) - cnt.begin());
    for (int i = 0; i < n - 1; i++) {
      if (cnt[id] > total + 1 && a[i] != a[i + 1] && a[i] != id && a[i + 1] != id) {
        cnt[a[i]] += 1;
        cnt[a[i + 1]] += 1;
        total += 1;
        ++ans;
      }
    }
    cout << (cnt[id] > total + 1 ? -1 : ans) << '\n';
  }
  return 0;
}