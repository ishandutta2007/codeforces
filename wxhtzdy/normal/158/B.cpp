#include <bits/stdc++.H>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> cnt(5, 0);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  int ans = cnt[4];
  ans += cnt[2] / 2;
  cnt[2] = cnt[2] % 2;
  ans += min(cnt[1], cnt[3]);
  int x = min(cnt[1], cnt[3]);
  cnt[1] -= x;
  cnt[3] -= x;
  if (cnt[1] > 0) {
    if (cnt[2] == 1) {
      ans += min(cnt[2], cnt[1]);
      cnt[2]--;
      cnt[1] -= 2;
    }
    ans += cnt[1] / 4;
    if (cnt[1] > 0 && cnt[1] % 4 != 0) {
      ans++;
    }
  } else {
    ans += cnt[3] + cnt[2];
  }
  cout << ans;
}