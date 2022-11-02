//25E
#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int l[4], ans, h[4][100005], cmps[4][4];
string s[4];
bool g[4][4];

bool contain(const int a, const int b) {
    if (l[a] < l[b]) return false;
    int hb = 0, ha = 0, cnt = 1;
    for (int i = 0; i < l[b]; i++) {
        hb = hb * 29 + s[b][i] - 'a';
      ha = ha * 29 + s[a][i] - 'a';
    }
    for (int i = 0; i < l[b] - 1; i++) cnt *= 29;
    if (ha == hb) return true;
    for (int i = l[b]; i < l[a]; i++) {
      ha = (ha - cnt * (s[a][i - l[b]] - 'a')) * 29 + s[a][i] - 'a';
      if (ha == hb) return true;
    }
  return false;
}

int calc(const int a, const int b) {
    if (cmps[a][b] != -1) return cmps[a][b];
    int hash = 0, ret = 0, cnt = 1;
    for (int i = l[a] - 1; i >= 0; i--) {
      hash = hash * 29 + s[a][i] - 'a';
        h[a][i] = hash;
    }
    hash = 0;
    for (int i = 0; i < l[b]; i++) {
      hash = hash + (s[b][i] - 'a') * cnt;
        cnt = cnt * 29;
        h[b][i] = hash;
    }
  for (int i = l[a] - 1; i >= 0 && l[a] - i < l[b]; i--) {
        if (h[a][i] == h[b][l[a] - i - 1]) ret = l[a] - i;
    }
    return cmps[a][b] = ret;
}

int calc3(const int a, const int b, const int c) {
  int t1 = calc(a, b), t2 = calc(b, c);
    if (t1 + t2 <= l[b]) return l[a] + l[b] + l[c] - t1 - t2; else return l[a] + l[c] - (t1 + t2 - l[b]);
}

int main() {
    for (int i = 1; i <= 3; i++) {
        cin >> s[i];
        l[i] = s[i].size();
    }
    ans = l[1] + l[2] + l[3];
  for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            if (i != j) {
                g[i][j] = contain(i, j);
            }
            cmps[i][j] = -1;
        }
    }
    g[1][1] = g[2][1] || g[3][1];
    g[2][2] = g[1][2] || g[3][2];
    g[3][3] = g[1][3] || g[2][3];
    //use one
    if (g[1][2] && g[1][3]) ans = min(ans, l[1]);
    if (g[2][1] && g[2][3]) ans = min(ans, l[2]);
    if (g[3][2] && g[3][1]) ans = min(ans, l[3]);
    //use two
  if (g[1][1]) ans = min(ans, l[3] + l[2] - max(calc(3, 2), calc(2, 3)));
  if (g[2][2]) ans = min(ans, l[1] + l[3] - max(calc(1, 3), calc(3, 1)));
  if (g[3][3]) ans = min(ans, l[2] + l[1] - max(calc(2, 1), calc(1, 2)));
  //use three
  ans = min(ans, calc3(1, 2, 3));
  ans = min(ans, calc3(1, 3, 2));
  ans = min(ans, calc3(2, 1, 3));
  ans = min(ans, calc3(2, 3, 1));
  ans = min(ans, calc3(3, 1, 2));
  ans = min(ans, calc3(3, 2, 1));
    printf("%d\n", ans);
    return 0;
}