#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int n;
  cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  map<vector<int>, int> cnt;
  for (ll i = 0; i < (1 << 15); i++) {
    vector<int> c(n);
    for (ll j = 0; j < n; j++) {
      ll br = (a[j] & ((1 << 15) - 1)) ^ i;
      for (ll l = 0; l < 30; l++) {
        if (br & (1LL << l)) {
          c[j]++;
        }
      }
    }
    vector<int> v;
    for (int j = 1; j < n; j++) {
      v.push_back(c[0] - c[j]);
    }
    cnt[v] = i;
  }
  for (ll i = 0; i < (1 << 15); i++) {
    vector<int> c(n, 30);
    for (ll j = 0; j < n; j++) {
      ll br = (a[j] >> 15) ^ i;
      for (ll l = 0; l < 30; l++) {
        if (br & (1LL << l)) {
          c[j]--;
        }
      }
    }
    vector<int> v;
    for (int j = 1; j < n; j++) {
      v.push_back(c[0] - c[j]);
    }
    if (cnt.count(v)) {
      cout << (cnt[v] ^ (i << 15)) << '\n';
      return 0;
    }
  }
  cout << -1 << '\n';
}