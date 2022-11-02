#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

long long octs[19], f[19][19];
int n;
char g[19][19][40], s[40];
bool b[19][19];

void getans(int i, int j) {
  if (i == 0 && j == 0 || b[i][j]) return;
  long long t1 = 0, t2 = 0;
  if (i > 0) {
    getans(i - 1, j);
    t1 = f[i - 1][j] + (s[i + j - 1] - '0') * octs[n - i];
  }
  if (j > 0) {
    getans(i, j - 1);
    t2 = f[i][j - 1] + (s[i + j - 1] - '0') * octs[n - j];
  }
  if (t1 > t2 || j == 0) {
    for (int k = 0; k <= i + j - 2; ++k) g[i][j][k] = g[i - 1][j][k];
    g[i][j][i + j - 1] = 'H';
    f[i][j] = t1;
  } else {
    for (int k = 0; k <= i + j - 2; ++k) g[i][j][k] = g[i][j - 1][k];
    g[i][j][i + j - 1] = 'M';  
    f[i][j] = t2;
  }
  b[i][j] = true;
}

int main() {
  octs[0] = 1;
  for (int i = 1; i <= 18; ++i) octs[i] = octs[i - 1] * 10;
  scanf("%d", &n);
  gets(s);
  if (s[0] < '0' || s[0] > '9') gets(s);
  getans(n, n);
  printf("%s\n", g[n][n]);
  return 0;
}