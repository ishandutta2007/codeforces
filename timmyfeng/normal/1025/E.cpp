#include <bits/stdc++.h>
using namespace std;

const int N = 50;

array<int, 3> s[N], t[N];
int n, m;

vector<array<int, 4>> solve_x(int i, array<int, 3> *a) {
  if (i == m) {
    return {};
  }

  vector<array<int, 4>> moves;
  while (a[i][0] > i) {
    moves.push_back({a[i][0], a[i][1], a[i][0] - 1, a[i][1]});
    --a[i][0];
  }

  for (auto o : solve_x(i + 1, a)) {
    moves.push_back(o);
  }

  while (a[i][0] < i) {
    moves.push_back({a[i][0], a[i][1], a[i][0] + 1, a[i][1]});
    ++a[i][0];
  }

  return moves;
}

vector<array<int, 4>> solve_y(int i, array<int, 3> *a) {
  if (i == m) {
    return {};
  }

  vector<array<int, 4>> moves = solve_y(i + 1, a);
  while (a[i][1] != a[i][0]) {
    int d = (a[i][1] < a[i][0]) ? 1 : -1;
    moves.push_back({a[i][0], a[i][1], a[i][0], a[i][1] + d});
    a[i][1] += d;
  }

  return moves;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;

  for (int i = 0; i < m; ++i) {
    cin >> s[i][0] >> s[i][1];
    --s[i][0], --s[i][1];
    s[i][2] = i;
  }
  sort(s, s + m);

  for (int i = 0; i < m; ++i) {
    cin >> t[i][0] >> t[i][1];
    --t[i][0], --t[i][1];
    t[i][2] = i;
  }
  sort(t, t + m);

  vector<array<int, 4>> ans_l, ans_r;

  for (auto o : solve_x(0, s)) {
    ans_l.push_back(o);
  }

  for (auto o : solve_y(0, s)) {
    ans_l.push_back(o);
  }

  for (int i = 0; i < m; ++i) {
    int x = 0;
    for ( ; t[x][2] != s[i][2]; ++x);
    while (s[i][0] != x) {
      int d = (s[i][0] < x) ? 1 : -1;
      ans_l.push_back({s[i][0], s[i][1], s[i][0] + d, s[i][1]});
      s[i][0] += d;
    }
  }

  for (auto o : solve_y(0, s)) {
    ans_l.push_back(o);
  }

  for (auto o : solve_x(0, t)) {
    ans_r.push_back(o);
  }

  for (auto o : solve_y(0, t)) {
    ans_r.push_back(o);
  }

  cout << ans_l.size() + ans_r.size() << "\n";
  for (auto [x1, y1, x2, y2] : ans_l) {
    cout << x1 + 1 << " " << y1 + 1 << " " << x2 + 1 << " " << y2 + 1 << "\n";
  }

  reverse(ans_r.begin(), ans_r.end());
  for (auto [x2, y2, x1, y1] : ans_r) {
    cout << x1 + 1 << " " << y1 + 1 << " " << x2 + 1 << " " << y2 + 1 << "\n";
  }
}