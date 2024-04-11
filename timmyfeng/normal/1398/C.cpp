#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    string a;
    cin >> n;
    cin >> a;

    map<int, int> cnt;
    cnt[0] = 1;
    int sum = 0;
    long long ans = 0;
    for (char i : a) {
      sum += i - '0' - 1;
      ans += cnt[sum];
      ++cnt[sum];
    }

    cout << ans << "\n";
  }
}