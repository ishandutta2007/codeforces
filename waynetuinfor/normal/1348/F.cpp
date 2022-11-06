#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n), b(n), wh(n, -1);
  vector<vector<int>> event(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
    a[i]--;
    b[i]--;
    event[a[i]].push_back(i);
    if (b[i] + 1 < n) event[b[i] + 1].push_back(~i);
  }
  vector<int> nxt(n, -1);
  multiset<pair<int, int>> s;
  for (int i = 0; i < n; ++i) {
    for (int u : event[i]) {
      if (u >= 0) {
        s.insert(make_pair(b[u], u));
      } else {
        if (wh[~u] == -1) {
          s.erase(s.find(make_pair(b[~u], ~u)));
        }
      }
    }
    assert(!s.empty());
    auto it = s.begin();
    wh[it->second] = i;
    if (next(it) != s.end()) nxt[it->second] = next(it)->second;
    s.erase(it);
  }
  for (int i = 0; i < n; ++i) {
    if (nxt[i] != -1) {
      if (wh[nxt[i]] >= a[i] && wh[nxt[i]] <= b[i] && wh[i] >= a[nxt[i]] && wh[i] <= b[nxt[i]]) {
        cout << "NO\n";
        for (int j = 0; j < n; ++j) cout << wh[j] + 1 << " ";
        cout << "\n";
        swap(wh[i], wh[nxt[i]]);
        for (int j = 0; j < n; ++j) cout << wh[j] + 1 << " ";
        cout << "\n";
        return 0;
      }
    }
  }
  cout << "YES\n";
  for (int j = 0; j < n; ++j) cout << wh[j] + 1 << " ";
  cout << "\n";
  return 0;
}