#include <bits/stdc++.h>
using namespace std;

int query(vector<int> a, vector<int> b) {
  cout << a.size() << " " << b.size() << " ";
  for (auto i : a) {
    cout << i + 1 << " ";
  }
  for (auto i : b) {
    cout << i + 1 << " ";
  }
  cout << endl;

  int res;
  cin >> res;
  return res;
}

vector<int> get(int a, int b) {
  vector<int> res;
  for (int i = a; i <= b; ++i) {
    res.push_back(i);
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    int max_dist = query({0}, get(1, n - 1));

    int lo = 1;
    int hi = n - 1;
    while (lo < hi) {
      int mid = (lo + hi) / 2;
      if (query({0}, get(lo, mid)) != max_dist) {
        lo = mid + 1;
      } else {
        hi = mid;
      }
    }

    vector<int> nodes;
    for (int i = 0; i < n; ++i) {
      if (i != lo) {
        nodes.push_back(i);
      }
    }
    int ans = query({lo}, nodes);

    cout << -1 << " " << ans << endl;
  }
}