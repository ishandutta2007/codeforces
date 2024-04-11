/**
 *    author:  tourist
 *    created: 13.06.2021 18:47:34       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  const int inf = (int) 1e9;
  vector<int> d(n + 1, inf);
  vector<int> pr(n + 1, -1);
  vector<int> pe(n + 1, -1);
  d[0] = 0;
  vector<bool> alive(n + 1, true);
  for (int it = 0; it <= n; it++) {
    int id = -1;
    for (int i = 0; i <= n; i++) {
      if (alive[i] && (id == -1 || d[i] < d[id])) {
        id = i;
      }
    }
    if (d[id] == inf) {
      break;
    }
    alive[id] = false;
    for (int x = 0; x <= id; x++) {
      int y = k - x;
      if (y < 0 || y > n - id) {
        continue;
      }
      int to = id - x + y;
      if (d[to] > d[id] + 1) {
        d[to] = d[id] + 1;
        pr[to] = id;
        pe[to] = x;
      }
    }
  }
  if (d[n] == inf) {
    cout << -1 << endl;
    return 0;
  }
  vector<int> seq;
  {
    int i = n;
    while (i > 0) {
      seq.push_back(pe[i]);
      i = pr[i];
    }
  }
  reverse(seq.begin(), seq.end());
  vector<bool> in(n, false);
  int ans = 0;
  for (int x : seq) {
    int y = k - x;
    vector<int> r;
    for (int i = 0; i < n; i++) {
      if (in[i] && x > 0) {
        r.push_back(i);
        in[i] = !in[i];
        --x;
      } else
      if (!in[i] && y > 0) {
        r.push_back(i);
        in[i] = !in[i];
        --y;
      }
    }
    assert((int) r.size() == k);
    cout << "?";
    for (int i : r) {
      cout << " " << i + 1;
    }
    cout << endl;
    cin >> y;
    ans ^= y;
  }
  cout << "! " << ans << endl;
  return 0;
}