/**
 *    author:  tourist
 *    created: 10.10.2020 18:25:40       
**/
#include <bits/stdc++.h>

using namespace std;

vector<vector<vector<int>>> Solve(vector<int> a) {
  int n = (int) a.size();
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (a[i] == a[j] + 1) {
        vector<vector<int>> op;
        if (i > 0) {
          vector<int> part;
          for (int k = 0; k < i; k++) {
            part.push_back(a[k]);
          }
          op.push_back(part);
        }
        {
          vector<int> part;
          for (int k = i; k <= i; k++) {
            part.push_back(a[k]);
          }
          op.push_back(part);
        }
        {
          vector<int> part;
          for (int k = i + 1; k <= j; k++) {
            part.push_back(a[k]);
          }
          op.push_back(part);
        }
        if (j < n - 1) {
          vector<int> part;
          for (int k = j + 1; k < n; k++) {
            part.push_back(a[k]);
          }
          op.push_back(part);
        }
        vector<int> b;
        for (auto& part : vector<vector<int>>(op.rbegin(), op.rend())) {
          for (int x : part) {
            b.push_back(x);
          }
        }
        vector<int> c;
        for (int x : b) {
          if (x == a[i]) {
            continue;
          }
          if (x > a[i]) {
            c.push_back(x - 1);
          } else {
            c.push_back(x);
          }
        }
        auto aux = Solve(c);
        vector<vector<vector<int>>> ret;
        ret.push_back(op);
        for (auto& po : aux) {
          vector<vector<int>> new_op;
          for (auto& v : po) {
            vector<int> u;
            for (int x : v) {
              if (x > a[j]) {
                u.push_back(x + 1);
              }
              if (x == a[j]) {
                u.push_back(x);
                u.push_back(x + 1);
              }
              if (x < a[j]) {
                u.push_back(x);
              }
            }
            new_op.push_back(u);
          }
          ret.push_back(new_op);
        }
        return ret;
      }
    }
  }
  return {};
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  auto res = Solve(a);
  cout << res.size() << '\n';
  for (auto& v : res) {
    cout << v.size();
    for (auto& u : v) {
      cout << " " << u.size();
    }
    cout << '\n';
  }
  return 0;
}