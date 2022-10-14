#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> x[2][2];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<char> c(n);
    for (int i = 0; i < n; i++) {
      cin >> c[i];
      x[a[i] % 2][(c[i] == 'L' ? 0 : 1)].push_back(i);
    }
    vector<int> ans(n, -1);
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        sort(x[i][j].begin(), x[i][j].begin(), [&](int id1, int id2) {
          return a[id1] < a[id2];
        });
      }
      vector<pair<int, int>> ev;
      for (int j = 0; j < (int) x[i][0].size(); j++) {
        ev.emplace_back(x[i][0][j], 0);
      }
      for (int j = 0; j < (int) x[i][1].size(); j++) {
        ev.emplace_back(x[i][1][j], 1);
      }
      sort(ev.begin(), ev.end(), [&](pair<int, int> X, pair<int, int> Y) {
        return a[X.first] < a[Y.first];
      });
      stack<int> st;
      for (auto& p : ev) {
        if (p.second == 1) {
          st.push(p.first);
          continue;
        }
        if (st.empty()) {
          continue;
        }
        int diff = abs(a[p.first] - a[st.top()]) / 2;
        ans[p.first] = ans[st.top()] = diff;
        st.pop();
      }
      vector<int> pp[2];
      for (int j = 0; j < n; j++) {
        if (ans[j] == -1 && a[j] % 2 == i) {
          pp[(c[j] == 'L' ? 0 : 1)].push_back(j);
        }
      }
      sort(pp[0].begin(), pp[0].end(), [&](int A, int B){return a[A] < a[B];});
      sort(pp[1].begin(), pp[1].end(), [&](int A, int B){return a[A] > a[B];});
      for (int j = 0; j < (int) pp[0].size(); j += 2) {
        if (j == (int) pp[0].size() - 1) {
          continue;
        }
        int X = a[pp[0][j]];
        int Y = a[pp[0][j + 1]];
        int diff = min(X, Y) + (max(X, Y) - min(X, Y)) / 2;
        ans[pp[0][j]] = ans[pp[0][j + 1]] = diff;
      }
      for (int j = 0; j < (int) pp[1].size(); j += 2) {
        if (j == (int) pp[1].size() - 1) {
          continue;
        }
        int X = a[pp[1][j]];
        int Y = a[pp[1][j + 1]];
        int diff = m - max(X, Y) + (m - min(X, Y) - (m - max(X, Y))) / 2;
        ans[pp[1][j]] = ans[pp[1][j + 1]] = diff;
      }
      vector<int> b[2];
      for (int j = 0; j < n; j++) {
        if (ans[j] == -1 && a[j] % 2 == i) {
          b[(c[j] == 'L' ? 0 : 1)].push_back(j);
        }
      }
      sort(b[1].rbegin(), b[1].rend());
      for (int j = 0; j < min((int) b[0].size(), (int) b[1].size()); j++) {
        int X = a[b[0][j]];
        int Y = a[b[1][j]];
        int diff = min(X, m - Y);
        X -= diff;
        Y += diff;
        diff += max(X, m - Y);
        diff += (Y - X) / 2;
        ans[b[0][j]] = ans[b[1][j]] = diff;
      }
    }
    for (int i = 0; i < n; i++) {
      cout << ans[i] << " ";
    }
    cout << '\n';
  }
  return 0;
}