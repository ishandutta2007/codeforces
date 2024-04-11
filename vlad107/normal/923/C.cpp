#include <bits/stdc++.h>

using namespace std;

const int N = 300300;
const int K = 31;

int g[N*K][2];
int cnt[N*K];
int cg = 1;

void add(int x) {
  int cur = 0;
  for (int i = 29; i >= 0; i--) {
    int j;
    if (x & (1 << i)) {
      j = 1;
    } else {
      j = 0;
    }
    if (g[cur][j] < 0) {
      g[cur][j] = cg++;
    }
    cur = g[cur][j];
    ++cnt[cur];
  }
}

int main() {
  //freopen("input.txt", "r", stdin);
  memset(g, -1, sizeof(g));
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &b[i]);
    add(b[i]);
  }
  for (int i = 0; i < n; i++) {
    int res = 0;
    int cur = 0;
    for (int j = 29; j >= 0; j--) {
      int u;
      if (a[i] & (1 << j)) {
        u = 1;
      } else {
        u = 0;
      }
      if ((g[cur][u] == -1) || (cnt[g[cur][u]] == 0)) {
        u = 1 - u;
      }
      res += u * (1 << j);
      cur = g[cur][u];
      --cnt[cur];
    }
    cout << (a[i] ^ res) << " ";
  }
  cout << endl;
  return 0;
}