#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);             
  int n;
  cin >> n;
  map<int, int> cnt;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  int cnt2 = 0, cnt4 = 0;
  for (int i = 1; i <= 1e5; i++) {
    cnt4 += cnt[i] / 4;
    if (cnt[i] % 4 >= 2) cnt2++;
  }
  int q;
  cin >> q;
  while (q--) {
    char c;
    int d;
    cin >> c >> d;
    if (c == '+') {
      cnt[d]++;
      if (cnt[d] == 2) cnt2++;
      if (cnt[d] % 4 == 0) cnt2--, cnt4++;
      if (cnt[d] % 4 == 2 && cnt[d] >= 6) cnt2++;
    } else {
      cnt[d]--;
      if (cnt[d] % 4 == 1 && cnt[d] >= 5) cnt2--;
      if (cnt[d] % 4 == 3) cnt4--, cnt2++;
      if (cnt[d] == 1) cnt2--;
    }
    if ((cnt4 >= 1 && cnt2 >= 2) || (cnt4 >= 2)) {
      cout << "YES" << '\n';
    } else {
      cout << "NO" << '\n';
    }
    //cout << cnt2 << " " << cnt4 << endl;
  }
  return 0;
}