#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll
#define F first
#define S second
 
const int N = 1e5 + 10;
int ans[N];

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, t;
  cin >> n >> t;
  set<pair<int, int>> st;
  set<int> events;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    st.insert({x, i});
    events.insert(x);
  }
  deque<pair<int, int>> d;
  set<int> wait;
  while (!events.empty()) {
    int cur_time = *events.begin();
    events.erase(events.begin());
    if (!d.empty() && d.front().S == cur_time) {
      ans[d.front().F] = cur_time;
      d.pop_front();
    }
    while (!st.empty() && st.begin()->F == cur_time) {
      wait.insert(st.begin()->S);
      st.erase(st.begin());
    }
    if (!wait.empty()) {
      if (d.empty() || d.back().F > *wait.begin()) {
        int pos = *wait.begin();
        wait.erase(wait.begin());
        if (!d.empty()) {
          d.pb({pos, d.back().S + t});
        }
        else {
          d.pb({pos, cur_time + t});
        }
        events.insert(d.back().S);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << ' ';
  }
  cout << '\n';
}