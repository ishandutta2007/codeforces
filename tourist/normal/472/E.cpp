#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <cassert>

using namespace std;

const int N = 42;

int a[N][N], b[N][N];
int old_a[N][N];
int ca[N * N], cb[N * N];
int new_a[N][N], new_b[N][N];

bool FLAG;

void print(vector < pair <int, int> > &moves) {
  int cnt = moves.size();
  printf("%d\n", cnt - 1);
  for (int i = 0; i < cnt; i++) {
    if (FLAG) {
      swap(moves[i].first, moves[i].second);
    }
    printf("%d %d\n", moves[i].first + 1, moves[i].second + 1);
  }
  exit(0);
}

vector < pair <int, int> > moves;
int h, w;

void add(int x, int y) {
  assert(0 <= x && x < h && 0 <= y && y < w);
  int sz = moves.size();
  if (sz > 0) {
    int px = moves[sz - 1].first;
    int py = moves[sz - 1].second;
    swap(a[x][y], a[px][py]);
  }
  moves.push_back(make_pair(x, y));
}

int main() {
  scanf("%d %d", &h, &w);
  for (int i = 0; i < N * N; i++) {
    ca[i] = cb[i] = 0;
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      scanf("%d", a[i] + j);
      ca[a[i][j]]++;
      old_a[i][j] = a[i][j];
    }
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      scanf("%d", b[i] + j);
      cb[b[i][j]]++;
    }
  }
  for (int i = 0; i < N * N; i++) {
    if (ca[i] != cb[i]) {
      printf("%d\n", -1);
      return 0;
    }
  }
  FLAG = false;
  if (w == 1) {
    FLAG = true;
    swap(h, w);
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        new_a[i][j] = a[j][i];
        new_b[i][j] = b[j][i];
      }
    }
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        a[i][j] = new_a[i][j];
        b[i][j] = new_b[i][j];
        old_a[i][j] = a[i][j];
      }
    }
  }
  if (h == 1) {
    for (int from = 0; from < w; from++) {
      for (int to = 0; to < w; to++) {
        for (int i = 0; i < h; i++) {
          for (int j = 0; j < w; j++) {
            a[i][j] = old_a[i][j];
          }
        }
        vector < pair <int, int> > moves;
        int i = 0;
        int j = from;
        moves.push_back(make_pair(i, j));
        while (j < to) {
          swap(a[i][j], a[i][j + 1]);
          j++;
          moves.push_back(make_pair(i, j));
        }
        while (j > to) {
          swap(a[i][j], a[i][j - 1]);
          j--;
          moves.push_back(make_pair(i, j));
        }
        bool ok = true;
        for (int i = 0; i < h; i++) {
          for (int j = 0; j < w; j++) {
            if (a[i][j] != b[i][j]) {
              ok = false;
            }
          }
        }
        if (ok) {
          print(moves);
        }
      }
    }
    printf("%d\n", -1);
    return 0;
  }
  int x = -1, y = -1;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (a[i][j] == b[h - 1][w - 1]) {
        add(i, j);
        x = i;
        y = j;
        break;
      }
    }
    if (x != -1) break;
  }
  while (x > 0) {
    add(x - 1, y);
    x--;
  }
  while (y > 0) {
    add(x, y - 1);
    y--;
  }
  vector < pair <int, int> > path;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (i == h - 1 && j == w - 1) {
        continue;
      }
      int ri = -1, rj = -1;
      for (int pi = i; pi < h; pi++) {
        for (int pj = (pi > i ? 0 : j + 1); pj < w; pj++) {
          if (a[pi][pj] == b[i][j]) {
            ri = pi;
            rj = pj;
            break;
          }
        }
        if (ri != -1) break;
      }
      if (rj < j) {
        while (y > rj) {
          path.push_back(make_pair(x, y));
          add(x, y - 1);
          y--;
        }
        while (x < ri - 1) {
          path.push_back(make_pair(x, y));
          add(x + 1, y);
          x++;
        }
        while (y < j) {
          add(x + 1, y);
          add(x + 1, y + 1);
          add(x, y);
          rj++;
          path.push_back(make_pair(x, y));
          add(x, y + 1);
          y++;
        }
        for (int u = (int)path.size() - 1; u >= 0; u--) {
          add(path[u].first, path[u].second);
          x = path[u].first;
          y = path[u].second;
        }
        path.clear();
      }
      if (rj > j) {
        if (ri > i) {
          while (y < rj) {
            path.push_back(make_pair(x, y));
            add(x, y + 1);
            y++;
          }
          while (x < ri - 1) {
            path.push_back(make_pair(x, y));
            add(x + 1, y);
            x++;
          }
          while (y > j) {
            add(x + 1, y);
            add(x + 1, y - 1);
            add(x, y);
            rj--;
            path.push_back(make_pair(x, y));
            add(x, y - 1);
            y--;
          }
          for (int u = (int)path.size() - 1; u >= 0; u--) {
            add(path[u].first, path[u].second);
            x = path[u].first;
            y = path[u].second;
          }
          path.clear();
        } else {
          if (x > 0) {
            path.push_back(make_pair(x, y));
            add(x - 1, y);
            x--;
            while (y < rj) {
              path.push_back(make_pair(x, y));
              add(x, y + 1);
              y++;
            }
            while (y > j + 1) {
              add(x + 1, y);
              add(x + 1, y - 1);
              add(x, y);
              rj--;
              path.push_back(make_pair(x, y));
              add(x, y - 1);
              y--;
            }
          } else {
            path.push_back(make_pair(x, y));
            add(x + 1, y);
            x++;
            while (y < rj) {
              path.push_back(make_pair(x, y));
              add(x, y + 1);
              y++;
            }
            while (y > j + 1) {
              add(x - 1, y);
              add(x - 1, y - 1);
              add(x, y);
              rj--;
              path.push_back(make_pair(x, y));
              add(x, y - 1);
              y--;
            }
          }
          for (int u = (int)path.size() - 1; u >= 0; u--) {
            add(path[u].first, path[u].second);
            x = path[u].first;
            y = path[u].second;
          }
          path.clear();
          add(x, y + 1);
          y++;
        }
      }
      if (ri > i) {
        if (j == 0) {
          path.push_back(make_pair(x, y));
          add(x, y + 1);
          y++;
          while (x < ri) {
            path.push_back(make_pair(x, y));
            add(x + 1, y);
            x++;
          }
          while (x > i + 1) {
            add(x, y - 1);
            add(x - 1, y - 1);
            add(x, y);
            path.push_back(make_pair(x, y));
            add(x - 1, y);
            x--;
          }
          for (int u = (int)path.size() - 1; u >= 0; u--) {
            add(path[u].first, path[u].second);
            x = path[u].first;
            y = path[u].second;
          }
          path.clear();
          add(x + 1, y);
          x++;
        } else {
          path.push_back(make_pair(x, y));
          add(x, y - 1);
          y--;
          while (x < ri) {
            path.push_back(make_pair(x, y));
            add(x + 1, y);
            x++;
          }
          while (x > i + 1) {
            add(x, y + 1);
            add(x - 1, y + 1);
            add(x, y);
            path.push_back(make_pair(x, y));
            add(x - 1, y);
            x--;
          }
          for (int u = (int)path.size() - 1; u >= 0; u--) {
            add(path[u].first, path[u].second);
            x = path[u].first;
            y = path[u].second;
          }
          path.clear();
          add(x + 1, y);
          x++;
        }
        if (y < w - 1) {
          add(x - 1, y + 1);
          x--;
          y++;
        } else {
          while (y > 0) {
            add(x, y - 1);
            y--;
          }
        }
      }
    }
  }
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      assert(a[i][j] == b[i][j]);
    }
  }
  print(moves);
  return 0;
}