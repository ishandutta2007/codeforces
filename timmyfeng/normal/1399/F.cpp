#include <bits/stdc++.h>
using namespace std;

const int A = 2e5;

struct segment {
  int l, r, i;
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<segment> segments(n + 1);
    for (int i = 0; i < n; ++i) {
      cin >> segments[i].l >> segments[i].r;
      segments[i].i = i;
    }
    segments[n] = {0, A, n};

    sort(segments.begin(), segments.end(), [&](segment a, segment b) {
      return a.r - a.l < b.r - b.l;
    });

    vector<int> dp(n + 1);
    for (segment i : segments) {
      vector<segment> inside;
      for (segment j : segments) {
        if (j.i == i.i)
          break;
        if (j.l >= i.l && j.r <= i.r) {
          inside.push_back(j);
        }
      }

      sort(inside.begin(), inside.end(), [&](segment a, segment b) {
        return a.l > b.l;
      });

      map<int, int> mp;
      mp[i.r + 1] = 0;

      for (auto j : inside) {
        auto it1 = mp.upper_bound(j.r);
        auto it2 = mp.lower_bound(j.l);
        int res = it1->second + dp[j.i];
        if (res > it2->second) {
          mp[j.l] = res;
        }
      }

      dp[i.i] = mp.begin()->second + 1;
    }

    cout << dp[n] - 1 << "\n";
  }
}