#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, a, b, c;
  cin >> n >> a >> b >> c;
  multiset<int> st;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    st.insert(x);
  } 
  if (*st.rbegin() > a + b + c) {
    cout << -1 << '\n';
    exit(0);
  }
  vector<int> guys = {a, b, c};
  sort(all(guys));
  int ans = 0;
  /*while (SZ(st) >= 3) {
    if (*st.begin() <= guys[0] && *(++st.begin()) <= guys[1] && *(++++st.begin()) <= guys[2]) {
      auto it1 = --st.upper_bound(guys[2]);
      auto it2 = it1;
      it2--;
      if (*it2 > guys[1]) {
        it2 = --st.upper_bound(guys[1]);
      }
      auto it3 = it2;
      it3--;
      if (*it3 > guys[0]) {
        it3 = --st.upper_bound(guys[0]);
      }
      int vl1 = *it1, vl2 = *it2, vl3 = *it3;
      st.erase(st.find(vl1));
      st.erase(st.find(vl2));
      st.erase(st.find(vl3));
      ans++;
    }
    else {
      break;
    }
  }*/
  vector<int> cnt(3);
  for (auto it : st) {
    for (int i = 0; i < 3; i++) {
      if (it <= guys[i]) {
        cnt[i]++;
      }
    }
  }
  vector<int> kek = {a, b, c, a + b, a + c, b + c, a + b + c};
  sort(all(kek));
  int best = 1e9;
  while (!st.empty()) {
    if (SZ(st) % 3 == 0 && cnt[0] >= SZ(st) / 3 && cnt[1] >= SZ(st) / 3 * 2 && cnt[2] == SZ(st)) {
      best = min(best, ans + SZ(st) / 3);
    }
    int vl = *st.rbegin();
    for (int i = 0; i < 3; i++) {
      if (vl <= guys[i]) {
        cnt[i]--;
      }
    }
    st.erase(st.find(vl));
    int mx = 0;
    for (auto it : kek) {
      if (it >= vl) {
        mx = a + b + c - it;
        break;
      }
    }
    auto it = st.upper_bound(mx);
    if (it != st.begin()) {
      it--;
      for (int i = 0; i < 3; i++) {
        if (*it <= guys[i]) {
          cnt[i]--;
        }
      }
      st.erase(it);
    }
    ans++;
  }
  best = min(best, ans);
  cout << best << '\n';
  //cout << ans << '\n';
}