#include <bits/stdc++.h>
using namespace std;

const int N = 100000;

int saved[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<array<int, 3>> events;
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    events.push_back({a - b, 0, i});
    events.push_back({a, 1, i});
  }
  sort(events.begin(), events.end());

  int prv = 0;
  for (auto [x, t, i] : events) {
    if (t == 0) {
      saved[i] = prv + 1;
    } else {
      prv = saved[i];
    }
  }

  cout << n - *max_element(saved, saved + n) << "\n";
}