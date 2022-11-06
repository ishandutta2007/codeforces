#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  string t;
  cin >> t;
  vector<pair<int, char>> s;
  vector<int> nxt(n, -1), prv(n, n + 1), pos(n, -1);
  for (int i = 0, j = 0; i < n; i = j) {
    if (t[i] == '0') {
      pos[i] = s.size();
      s.emplace_back(i, '0');
      j++;
      continue;
    }
    while (j < n && t[j] == '1') j++;
    for (int k = i; k < j; ++k) {
      nxt[k] = j;
      prv[k] = i - 1;
    }
    if ((j - i) & 1) s.emplace_back(i, '1');
  }

  vector<int> pref(n + 1);
  for (int i = 0; i < n; ++i) pref[i + 1] = pref[i] + (t[i] == '1');
  
  constexpr int kP1 = 1'000'000'000 + 87;
  constexpr int kQ1 = 7122;
  constexpr int kP2 = 1'000'000'000 + 123;
  constexpr int kQ2 = 131;

  vector<int> hv1(s.size()), pw1(s.size() + 1, 1);
  vector<int> hv2(s.size()), pw2(s.size() + 1, 1);
  if (!s.empty()) {
    hv1[0] = hv2[0] = s[0].second;
    for (int i = 1; i < s.size(); ++i) {
      hv1[i] = (1LL * hv1[i - 1] * kQ1 + s[i].second) % kP1;
      hv2[i] = (1LL * hv2[i - 1] * kQ2 + s[i].second) % kP2;
    }
  }
  for (int i = 1; i <= s.size(); ++i) {
    pw1[i] = 1LL * pw1[i - 1] * kQ1 % kP1;
    pw2[i] = 1LL * pw2[i - 1] * kQ2 % kP2;
  }

  auto Query = [&](int l, int r) {
    if (l == 0) return make_pair(hv1[r], hv2[r]);
    int a = (hv1[r] + kP1 - 1LL * hv1[l - 1] * pw1[r - l + 1] % kP1) % kP1;
    int b = (hv2[r] + kP2 - 1LL * hv2[l - 1] * pw2[r - l + 1] % kP2) % kP2;
    return make_pair(a, b);
  };

  auto GetHash = [&](int l, int r) {
    if (t[l] == '1' && t[r] == '1' && nxt[l] == nxt[r]) {
      if ((r - l + 1) & 1) return make_pair(int('1'), int('1'));
      return make_pair(0, 0);
    }
    int tl = l, tr = r;
    if (t[l] == '1') tl = nxt[l];
    if (t[r] == '1') tr = prv[r];
    pair<int, int> h(0, 0);
    int len = 0;
    if (tl <= tr) {
      assert(t[tl] == '0' && t[tr] == '0');
      h = Query(pos[tl], pos[tr]);
      len = pos[tr] - pos[tl] + 1;
    }
    if (t[l] == '1') {
      int dist = tl - l;
      if (dist & 1) {
        h.first = (1LL * int('1') * pw1[len] + h.first) % kP1;
        h.second = (1LL * int('1') * pw2[len] + h.second) % kP2;
      }
    }
    if (t[r] == '1') {
      int dist = r - tr;
      if (dist & 1) {
        h.first = (1LL * h.first * kQ1 + int('1')) % kP1;
        h.second = (1LL * h.second * kQ2 + int('1')) % kP2;
      }
    }
    return h;
  };

  int q;
  cin >> q;
  while (q--) {
    int l, r, k;
    cin >> l >> r >> k;
    l--, r--;
    if ((pref[l + k] - pref[l]) == (pref[r + k] - pref[r]) && GetHash(l, l + k - 1) == GetHash(r, r + k - 1)) cout << "Yes\n";
    else cout << "No\n";
  }
}