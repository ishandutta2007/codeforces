#include <bits/stdc++.h>
using namespace std;

vector<int> cur;
vector<int> ans;
bool found;

void solve(const set<int>& vals, int k) {
  if (vals == set<int>{0}) {
    if (!found || cur.size() < ans.size()) {
      found = true;
      ans = cur;
    }
    return;
  } else if (k >= 200'000) {
    return;
  }

  for (auto j : {-k, k}) {
    bool cost = false;
    set<int> vals_new;
    for (auto i : vals) {
      if (i % (2 * j) == 0) {
        vals_new.insert(i);
      } else {
        vals_new.insert(i - j);
        cost = true;
      }
    }

    if (cost) {
      cur.push_back(j);
      solve(vals_new, 2 * k);
      cur.pop_back();
    } else {
      solve(vals_new, 2 * k);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  set<int> vals;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    vals.insert(a);
  }

  solve(vals, 1);

  cout << ans.size() << "\n";
  for (auto i : ans) {
    cout << i << " ";
  }
  cout << "\n";
}