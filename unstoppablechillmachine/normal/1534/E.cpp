#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back  
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll
 
const int inf = 1e9 + 10;
 
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> d(n + 1, inf), from(n + 1);
  queue<int> q;
  q.push(0);
  d[0] = 0;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int cnt_on = 0; cnt_on <= min(k, n - v); cnt_on++) {
      int cnt_off = k - cnt_on;
      if (cnt_off > v) {
        continue;
      }
      if (d[v + cnt_on - cnt_off] == inf) {
        d[v + cnt_on - cnt_off] = d[v] + 1;
        q.push(v + cnt_on - cnt_off);
        from[v + cnt_on - cnt_off] = v;
      }
    }
  }
  if (d[n] == inf) {
    cout << -1 << '\n';
    return 0;
  }
  vector<int> path = {n};
  while (path.back() != 0) {
    path.pb(from[path.back()]);
  }
  path.pop_back();
  reverse(all(path));
  int answer = 0;
  vector<int> is_on(n, 0);
  int lst = 0;
  auto ask = [](vector<int> guys) {
    cout << "? ";
    for (auto it : guys) {
      cout << it + 1 << ' ';
    }
    cout << endl;
    int result;
    cin >> result;
    return result;
  };
  auto guess = [](int answer) {
    cout << "! " << answer << endl;
  };
  for (int i = 0; i < SZ(path); i++) {
    int need_on = -1;
    for (int cnt_on = 0; cnt_on <= min(k, n - lst); cnt_on++) {
      int cnt_off = k - cnt_on;
      if (lst + cnt_on - cnt_off == path[i]) {
        need_on = cnt_on;
        break;
      }
    }
    //cout << need_on << endl;
    assert(need_on != -1);
    int need_off = k - need_on;
    vector<int> to_change;
    for (int j = 0; j < n; j++) {
      if (is_on[j] == 0 && need_on > 0) {
        need_on--;
        is_on[j] = 1;
        to_change.pb(j);
      } else if (is_on[j] == 1 && need_off > 0) {
        need_off--;
        is_on[j] = 0;
        to_change.pb(j);
      }
    }
    answer ^= ask(to_change);
    lst = path[i];
  }
  guess(answer);
  return 0;
}