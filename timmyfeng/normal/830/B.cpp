#include <bits/stdc++.h>
using namespace std;

const int N = 100'000;

vector<int> pos[N];
bool taken[N];
int a[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    pos[--a[i]].push_back(i);
  }

  int cur = 0;
  int back = 0;
  long long ans = n;

  for (int i = 0; i < N; ++i) {
    auto it = lower_bound(pos[i].begin(), pos[i].end(), cur);
    for (int j = 0; j < int(pos[i].size()); ++j) {
      if (it == pos[i].end()) {
        it = pos[i].begin();
      }
      back += (*it < cur);
      ans += back;
      cur = *it;
      ++it;
    }
  }

  cout << ans << "\n";
}