#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int a, b;
  cin >> a >> b;

  int lo = 0;
  int hi = 1e6;
  vector<int> ans_p;
  vector<int> ans_q;
  while (lo <= hi) {
    int mi = (lo + hi) / 2;

    int cur_a = a;
    int cur_b = b;
    vector<int> p;
    vector<int> q;
    bool ok = true;
    for (int i = mi; i > 0; --i) {
      if (max(cur_a, cur_b) < i) {
        ok = false;
        break;
      }
      if (cur_a > cur_b) {
        p.push_back(i);
        cur_a -= i;
      } else {
        q.push_back(i);
        cur_b -= i;
      }
    }

    if (ok) {
      lo = mi + 1;
      swap(ans_p, p);
      swap(ans_q, q);
    } else {
      hi = mi - 1;
    }
  }

  cout << ans_p.size() << "\n";
  for (int i : ans_p) {
    cout << i << " ";
  }
  cout << "\n";
  cout << ans_q.size() << "\n";
  for (int i : ans_q) {
    cout << i << " ";
  }
  cout << "\n";
}