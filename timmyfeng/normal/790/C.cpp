#include <bits/stdc++.h>
using namespace std;

const int N = 75 + 1;

int moves[N][N][N][2];

void check_min(int &a, int b) {
  a = min(a, b);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  string s;
  cin >> n >> s;

  for (auto &i : s) {
    if (i != 'V' && i != 'K') {
      i = 'X';
    }
  }

  int nv = count(s.begin(), s.end(), 'V');
  int nk = count(s.begin(), s.end(), 'K');
  int nx = count(s.begin(), s.end(), 'X');

  for (int v = 0; v <= nv; ++v) {
    for (int k = 0; k <= nk; ++k) {
      for (int x = 0; x <= nx; ++x) {
        for (auto b : {0, 1}) {
          moves[v][k][x][b] = INT_MAX;
        }
      }
    }
  }
  moves[0][0][0][0] = 0;

  for (int v = 0; v <= nv; ++v) {
    for (int k = 0; k <= nk; ++k) {
      for (int x = 0; x <= nx; ++x) {
        for (auto b : {0, 1}) {
          if (moves[v][k][x][b] == INT_MAX) {
            continue;
          }

          int vv = 0;
          int kk = 0;
          int xx = 0;

          for (int i = 0; i < n; ++i) {
            if (s[i] == 'V') {
              if (++vv == v + 1) {
                check_min(moves[v + 1][k][x][1], moves[v][k][x][b] + max(0, kk - k) + max(0, xx - x));
              }
            } else if (s[i] == 'K') {
              if (++kk == k + 1 && !b) {
                check_min(moves[v][k + 1][x][0], moves[v][k][x][b] + max(0, vv - v) + max(0, xx - x));
              }
            } else {
              if (++xx == x + 1) {
                check_min(moves[v][k][x + 1][0], moves[v][k][x][b] + max(0, vv - v) + max(0, kk - k));
              }
            }
          }
        }
      }
    }
  }

  cout << min(moves[nv][nk][nx][0], moves[nv][nk][nx][1]) << "\n";
}