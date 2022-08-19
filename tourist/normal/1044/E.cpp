/**
 *    author:  tourist
 *    created: 04.11.2018 22:11:34       
**/
//#undef _GLIBCXX_DEBUG

#include <bits/stdc++.h>

using namespace std;

vector<int> mp(362880, -1), pr(362880), pv(362880);

int hashh(vector<int> &a) {
  int res = 0;
  for (int i = 0; i < (int) a.size(); i++) {
    int cnt = 0;
    for (int j = i + 1; j < (int) a.size(); j++) {
      cnt += a[i] > a[j];
    }
    res = res * ((int) a.size() - i) + cnt;
  }
  return res;
}

void precalc() {
  int n = 3;
  vector<int> aa(n * n);
  iota(aa.begin(), aa.end(), 0);
  vector<int> goal = aa;
  swap(goal[0], goal[1]);
  vector<vector<int>> que(1, aa);
  mp[hashh(aa)] = 0;
  for (int b = 0; b < (int) que.size(); b++) {
    if (b % 50000 == 0) cerr << "b = " << b << ", que.size() = " << que.size() << '\n';
    int me = hashh(que[b]);
    int ft = mp[hashh(que[b])];
    for (int i = 0; i < n - 1; i++) {
      for (int j = 0; j < n - 1; j++) {
        vector<int> c = que[b];
        int tmp = c[i * n + j];
        c[i * n + j] = c[i * n + j + 1];
        c[i * n + j + 1] = c[(i + 1) * n + j + 1];
        c[(i + 1) * n + j + 1] = c[(i + 1) * n + j];
        c[(i + 1) * n + j] = tmp;
        int hh = hashh(c);
        if (mp[hh] == -1) {
          que.push_back(c);
          mp[hh] = ft + 1;
          pr[hh] = i * n + j;
          pv[hh] = me;
        }
      }
    }
    for (int i = 0; i < n - 1; i++) {
      for (int j = 0; j < n - 1; j++) {
        vector<int> c = que[b];
        int tmp = c[i * n + j];
        c[i * n + j] = c[(i + 1) * n + j];
        c[(i + 1) * n + j] = c[(i + 1) * n + j + 1];
        c[(i + 1) * n + j + 1] = c[i * n + j + 1];
        c[i * n + j + 1] = tmp;
        int hh = hashh(c);
        if (mp[hh] == -1) {
          que.push_back(c);
          mp[hh] = ft + 1;
          pr[hh] = ~(i * n + j);
          pv[hh] = me;
        }
      }
    }
  }
  cerr << "goal = " << mp[hashh(goal)] << '\n';
  cerr << "last = " << mp[hashh(que.back())] << '\n';
  cerr << "time = " << clock() << " ms" << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  precalc();
  int h, w;
  cin >> h >> w;
  vector<vector<int>> a(h, vector<int>(w));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> a[i][j];
    }
  }
  vector<vector<int>> res;
  auto make = [&](int xa, int ya, int xb, int yb, int xc, int yc, int xd, int yd) {
    res.push_back({a[xa][ya], a[xb][yb], a[xc][yc], a[xd][yd]});
    int tmp = a[xa][ya];
    a[xa][ya] = a[xd][yd];
    a[xd][yd] = a[xc][yc];
    a[xc][yc] = a[xb][yb];
    a[xb][yb] = tmp;
  };
  auto go = [&](int xa, int ya, int xb, int yb) {
    assert(abs(xa - xb) + abs(ya - yb) == 1);
    int x = max(0, max(xa, xb) - 2);
    int y = max(0, max(ya, yb) - 2);
    vector<int> goal(9);
    iota(goal.begin(), goal.end(), 0);
    int pa = (xa - x) * 3 + (ya - y);
    int pb = (xb - x) * 3 + (yb - y);
    swap(goal[pa], goal[pb]);
    int id = hashh(goal);
    while (id != 0) {
      int op = pr[id];
      if (op < 0) {
        op = (op >= 0 ? op : (~op));
        int sx = x + op / 3;
        int sy = y + op % 3;
        make(sx, sy + 1, sx, sy, sx + 1, sy, sx + 1, sy + 1);
      } else {
        op = (op >= 0 ? op : (~op));
        int sx = x + op / 3;
        int sy = y + op % 3;
        make(sx + 1, sy, sx, sy, sx, sy + 1, sx + 1, sy + 1);
      }
      id = pv[id];
    }
  };
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      int want = i * w + j + 1;
      int x = -1, y = -1;
      for (int ii = 0; ii < h; ii++) {
        for (int jj = 0; jj < w; jj++) {
          if (a[ii][jj] == want) {
            x = ii;
            y = jj;
          }
        }
      }
      while (y < j) {
        if (x + 1 < h) {
          make(x, y, x, y + 1, x + 1, y + 1, x + 1, y);
        } else {
          if (x - 1 > i) {
            make(x, y, x, y + 1, x - 1, y + 1, x - 1, y);
          } else {
            go(x, y, x, y + 1);
          }
        }
        y++;
      }
      while (y > j) {
        if (x + 1 < h) {
          make(x, y, x, y - 1, x + 1, y - 1, x + 1, y);
        } else {
          if (x - 1 > i) {
            make(x, y, x, y - 1, x - 1, y - 1, x - 1, y);
          } else {
            go(x, y, x, y - 1);
          }
        }
        y--;
      }
      while (x > i) {
        if (x - 1 > i) {
          if (y + 1 < w) {
            make(x, y, x - 1, y, x - 1, y + 1, x, y + 1);
          } else {
            make(x, y, x - 1, y, x - 1, y - 1, x, y - 1);
          }
        } else {
          go(x, y, x - 1, y);
        }
        x--;
      }
      assert(a[i][j] == want);
    }
  }
  int sz = (int) res.size();
  cout << sz << '\n';
  for (auto &v : res) {
    int ssz = (int) v.size();
    cout << ssz;
    for (int x : v) {
      cout << " " << x;
    }
    cout << '\n';
  }
  return 0;
}