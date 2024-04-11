#include <bits/stdc++.h>
using namespace std;

const int N = 100000;

int a[6];
int b[N];
int str[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int i = 0; i < 6; ++i) {
    cin >> a[i];
  }
  sort(a, a + 6);

  int n;
  cin >> n;

  multiset<int> frets;
  priority_queue<array<int, 2>> que;
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
    frets.insert(b[i] - a[0]);
    que.push({b[i] - a[0], i});
  }

  int ans = *(--frets.end()) - *frets.begin();
  while (!que.empty()) {
    auto [d, i] = que.top();
    que.pop();

    ++str[i];
    frets.erase(frets.find(d));
    frets.insert(b[i] - a[str[i]]);
    if (str[i] + 1 < 6) {
      que.push({b[i] - a[str[i]], i});
    }

    ans = min(ans, *(--frets.end()) - *frets.begin());
  }

  cout << ans << "\n";
}