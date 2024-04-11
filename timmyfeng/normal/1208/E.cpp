#include <bits/stdc++.h>
using namespace std;

const int N = 1'000'000 + 1;

long long ans[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, w;
  cin >> n >> w;

  for (int i = 0; i < n; ++i) {
    int l;
    cin >> l;

    vector<array<int, 3>> events;

    events.push_back({0, 0, 0});
    events.push_back({w - l, 1, 0});
    events.push_back({l, 0, 0});
    events.push_back({w, 1, 0});

    for (int j = 0; j < l; ++j) {
      int a;
      cin >> a;
      events.push_back({j, 0, a});
      events.push_back({w - l + j + 1, 1, a});
    }

    sort(events.begin(), events.end());
    multiset<int> possible;
    int prv = 0;

    for (auto [j, t, a] : events) {
      if (j != prv) {
        assert(!possible.empty());
        ans[prv] += *(--possible.end());
        ans[j] -= *(--possible.end());
        prv = j;
      }

      if (t == 1) {
        possible.erase(possible.find(a));
      } else {
        possible.insert(a);
      }
    }
  }

  for (int i = 0; i < w; ++i) {
    if (i > 0) {
      ans[i] += ans[i - 1];
    }
    cout << ans[i] << " ";
  }
  cout << "\n";
}