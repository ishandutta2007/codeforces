#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  deque<int> q;
  map<int, int> was;
  for (int i = 0; i < n; i++) {
    if (!was[a[i]]) {
      q.push_back(a[i]);
      was[a[i]] = 1;
      if ((int) q.size() > k) {
        was[q[0]] = 0;
        q.pop_front();
      }
    }
  }
  cout << q.size() << '\n';
  reverse(q.begin(), q.end());
  for (int c : q) {
    cout << c << " ";
  }
  return 0;
}