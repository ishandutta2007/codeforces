#include<cstdio>
#include<algorithm>
using namespace std;

int n, m, qhead, qtail, q[(1 << 24) + 5], f[(1 << 24) + 5], l;
char map[17][17], tmp[17][17];
bool hash[1 << 25];

const int d[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};

int x[10], y[10];

int getstat() {
  int ret = 0, x[10], y[10];
  for (int i = 0; i <= 9; ++i) x[i] = y[i] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      tmp[i][j] = map[i][j];
      if (map[i][j] >= '1' && map[i][j] <= '9') {
        int t1 = map[i][j] - '1' + 1;
        x[t1] = i; y[t1] = j;
        tmp[i][j] = '.';
        l = max(l, t1);
      }
    }
  }
  ret += (x[1] << 4) + y[1];
  for (int i = 2; i <= l; ++i) {
    for (int dir = 0; dir < 4; ++dir) {
      if (x[i] + d[dir][0] == x[i - 1] && y[i] + d[dir][1] == y[i - 1]) ret += ((dir) << (8 + (i - 2) * 2));
    }
  }
  return ret;
}

void recover(const int st) {
  tmp[x[1] = ((st >> 4) % 16)][y[1] = (st % 16)] = '1';
  for (int i = 2; i <= l; ++i) {
    int dir = (st >> (8 + (i - 2) * 2)) % 4;
    x[i] = x[i - 1] - d[dir][0];
    y[i] = y[i - 1] - d[dir][1];
    tmp[x[i]][y[i]] = '0' + i;
  }
}

void remove(const int st) {
  int x[10], y[10];
  tmp[x[1] = ((st >> 4) % 16)][y[1] = (st % 16)] = '.';
  for (int i = 2; i <= l; ++i) {
    int dir = (st >> (8 + (i - 2) * 2)) % 4;
    x[i] = x[i - 1] - d[dir][0];
    y[i] = y[i - 1] - d[dir][1];
    tmp[x[i]][y[i]] = '.';
  }
}

int main() {
  scanf("%d %d", &n, &m);
  l = 0;
  for (int i = 0; i < n; ++i) scanf("%s", map[i]);
  qhead = 0; qtail = 1; q[1] = getstat(); f[1] = 0;
  hash[q[1]] = true;
  while (qhead < qtail) {
    int t1 = q[++qhead];
    //printf("%d %d\n", t1, f[qhead]);
    recover(t1);
    for (int i = 0; i < 4; ++i) {
      x[0] = x[1] + d[i][0];
      y[0] = y[1] + d[i][1];
      if (x[1] + d[i][0] >= 0 && x[1] + d[i][0] < n && y[1] + d[i][1] >= 0 && y[1] + d[i][1] < m) {
        if (tmp[x[0]][y[0]] == '@') {
          printf("%d\n", f[qhead] + 1);
          return 0;
        } else if (tmp[x[0]][y[0]] == '.' || tmp[x[0]][y[0]] == ('0' + l)) {
  int ret = 0;
  ret += (x[0] << 4) + y[0];
  for (int j = 1; j < l; ++j) {
    for (int dir = 0; dir < 4; ++dir) {
      if (x[j] + d[dir][0] == x[j - 1] && y[j] + d[dir][1] == y[j - 1]) ret += ((dir) << (8 + (j - 1) * 2));
    }
  }
  if (!hash[ret]) {
    q[++qtail] = ret;
    f[qtail] = f[qhead] + 1;
    hash[ret] = true;
  }
        }
      }
    }
    remove(t1);
  }
  printf("-1\n");
  return 0;
}