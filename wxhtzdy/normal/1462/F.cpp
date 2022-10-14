/**
 *  author: milos
 *  created: 15.12.2020 16:12:28
**/
#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int, int> x, pair<int, int> y) {
  if (x.second == y.second) {
    return x.first < y.first;
  }
  return x.second < y.second;
}

const int N = 4e5 + 5;

struct fenwick{
  int bit[N];
  void clear(int mx) {
    for (int i = 0; i <= mx; i++) {
      bit[i] = 0;
    }
  }
  void modify(int x, int val) {
    for (;x < N; x += x & (-x)) {
      bit[x] += val;
    }
  }
  int get(int x) {
    int ans = 0;
    for (; x > 0; x -= x & (-x)) {
      ans += bit[x];
    }
    return ans;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    vector<int> all;
    for (int i = 0; i < n; i++) {
      cin >> a[i].first >> a[i].second;
      all.push_back(a[i].first);
      all.push_back(a[i].second);  
    }
    sort(all.begin(), all.end());
    for (int i = 0; i < n; i++) {
      a[i].first = lower_bound(all.begin(), all.end(), a[i].first) - all.begin() + 1;
      a[i].second = lower_bound(all.begin(), all.end(), a[i].second) - all.begin() + 1;
    }
    sort(a.begin(), a.end(), cmp);
    int ans = n;
    fenwick pref, suff;
    pref.clear((int) all.size() + 1);
    suff.clear((int) all.size() + 1);
    for (int i = 0; i < n; i++) {
      suff.modify(a[i].first, 1);   
    }
    for (int i = 0; i < n; i++) {
      suff.modify(a[i].first, -1);
      int cnt = (pref.get(all.size() + 1) - pref.get(a[i].first - 1)) + suff.get(a[i].second) + 1;
      //cout << pref.get(a[i].first - 1) << " " << suff.get(a[i].second) << '\n';
      ans = min(ans, n - cnt);
      pref.modify(a[i].second, 1);    
    }
    cout << ans << '\n';   
  }
  return 0;
}