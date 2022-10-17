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

inline int solve_win(int from, int to) {
  if (from > to) {
    return 1;
  }
  for (;;) {
    int nto = to / 2;
    if ((to & 1) || from > nto) {
      return (to - from) & 1;
    }
    int nto2 = nto / 2 + 1;
    if (from >= nto2) {
      return 1;
    }
    to = nto2 - 1;
  }
}

inline int solve_lose(int from, int to) {
  if (from > to) {
    return 0;
  }
  if (from * 2 > to) {
    return 1;
  }
  return solve_win(from, to / 2);
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  vector<vector<int>> can_second(T, vector<int>(2)), can_first(T, vector<int>(2));
  int ptr = 0;
  //0 - win
  //1 - lose
  for (int iter = 0; iter < T; iter++) {
    int from, to;
    cin >> from >> to;
    can_first[iter][0] = solve_win(from, to);
    can_first[iter][1] = solve_lose(from, to);
    if (solve_win(from * 2ll, to) && solve_win(from + 1, to)) {
      can_second[iter][0] = 1;
    }
    if (solve_lose(from * 2ll, to) && solve_lose(from + 1, to)) {
      can_second[iter][1] = 1;
    }
  }
  vector<bool> can(2, false);
  can[0] = true;
  //cout << can_first[0][0]
  for (int iter = 0; iter < T; iter++) {
    vector<bool> ncan(2, false);
    if (can[0]) {
      if (can_first[iter][0]) {
        ncan[1] = true;
      }
      if (can_first[iter][1]) {
        ncan[0] = true;
      }
    }
    if (can[1]) {
      if (can_second[iter][0]) {
        ncan[1] = true;
      }
      if (can_second[iter][1]) {
        ncan[0] = true;
      }
    }
    can = ncan;
  }
  cout << can[1] << ' ' << can[0] << '\n';  
}