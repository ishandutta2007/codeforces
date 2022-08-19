/**
 *    author:  tourist
 *    created: 22.07.2021 18:40:27       
**/
#include <bits/stdc++.h>

using namespace std;

struct Segment {
  int pref;
  vector<int> mn;
  vector<int> mx;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  vector<Segment> s(n);
  for (int i = 0; i < n; i++) {
    Segment& seg = s[i];
    seg.pref = a[i];
    seg.mn.assign(1, a[i]);
    seg.mx.assign(1, a[i]);
  }
  vector<int> res(1 << k, (int) 1e9);
  for (int bit = 0; bit < k; bit++) {
    vector<int> cur(1 << (bit + 1), (int) 1e9);
    vector<Segment> new_s;
    for (int it = 0; it < (int) s.size(); it++) {
      if (it + 1 < (int) s.size() && (s[it].pref ^ s[it + 1].pref) == 1) {
        for (int x = 0; x < (1 << bit); x++) {
          cur[x] = min(cur[x], s[it + 1].mn[x] - s[it].mx[x]);
        }
        for (int x = (1 << bit); x < (1 << (bit + 1)); x++) {
          cur[x] = min(cur[x], s[it].mn[x ^ (1 << bit)] - s[it + 1].mx[x ^ (1 << bit)] + (1 << (bit + 1)));
        }
        new_s.emplace_back();
        Segment& seg = new_s.back();
        seg.pref = s[it].pref >> 1;
        seg.mn.resize(1 << (bit + 1));
        seg.mx.resize(1 << (bit + 1));
        for (int x = 0; x < (1 << bit); x++) {
          seg.mn[x] = s[it].mn[x];
          seg.mx[x] = s[it + 1].mx[x];
        }
        for (int x = (1 << bit); x < (1 << (bit + 1)); x++) {
          seg.mn[x] = s[it + 1].mn[x ^ (1 << bit)] ^ (1 << bit);
          seg.mx[x] = s[it].mx[x ^ (1 << bit)] ^ (1 << bit);
        }
        it++;
        continue;
      }
      new_s.emplace_back();
      Segment& seg = new_s.back();
      seg.pref = s[it].pref >> 1;
      seg.mn.resize(1 << (bit + 1));
      seg.mx.resize(1 << (bit + 1));
      for (int x = 0; x < (1 << bit); x++) {
        seg.mn[x] = s[it].mn[x];
        seg.mx[x] = s[it].mx[x];
      }
      for (int x = (1 << bit); x < (1 << (bit + 1)); x++) {
        seg.mn[x] = s[it].mn[x ^ (1 << bit)] ^ (1 << bit);
        seg.mx[x] = s[it].mx[x ^ (1 << bit)] ^ (1 << bit);
      }
    }
    swap(s, new_s);
    for (int i = 0; i < (1 << k); i++) {
      res[i] = min(res[i], cur[i & ((1 << (bit + 1)) - 1)]);
    }
  }
  for (int i = 0; i < (1 << k); i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << res[i];
  }
  cout << '\n';
  return 0;
}