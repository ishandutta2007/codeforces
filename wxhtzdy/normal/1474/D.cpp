#include <bits/stdc++.h>

using namespace std;

bool Can(vector<int> a) {
  int n = (int) a.size();
  for (int i = 1; i < n; i++) {
    if (a[i] < a[i - 1]) {
      return 0;
    }
    a[i] -= a[i - 1];
  }
  return a[n - 1] == 0;
}

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
    }
    if (Can(a)) {
      cout << "YES" << '\n';
      continue;
    }
    vector<int> pref(n), suf(n);
    pref[0] = a[0];
    suf[n - 1] = a[n - 1];
    vector<bool> can_pref(n, true), can_suf(n, true);
    for (int i = 1; i < n; i++) {
      pref[i] = a[i] - pref[i - 1];
      can_pref[i] = (can_pref[i - 1] && pref[i] >= 0);
    }
    for (int i = n - 2; i >= 0; i--) {
      suf[i] = a[i] - suf[i + 1];
      can_suf[i] = (can_suf[i + 1] && suf[i] >= 0);
    }
    bool ok = false;
    for (int i = 0; i < n - 1; i++) {
      if ((i == 0 || can_pref[i - 1]) && (i == n - 2 || can_suf[i + 2])) {
        vector<int> b;
        if (i > 0) b.push_back(pref[i - 1]);
        b.push_back(a[i + 1]);
        b.push_back(a[i]);
        if (i < n - 2) b.push_back(suf[i + 2]);
        ok |= (Can(b));
      }
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
  return 0;
}