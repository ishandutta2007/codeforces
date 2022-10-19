#include <bits/stdc++.h>
using namespace std;

const int N = 205;

string s[N], now[N], tmp[N];
int n, m, Rk[N], id[N];

bool cmp(int x, int y) {
  return tmp[x] < tmp[y];
}

int main() {
  scanf("%d%d", &n, &m);
  for(int i = 1; i <= n; ++ i) {
    cin >> s[i];
  }
  int ans  =0;
  for(int i = 1; i <= n; ++ i) id[i] = 1; 
  
  for(int j = 0; j < m; ++ j) {
    for(int k = 1; k <= n; ++ k) {
      tmp[k] = now[k] + s[k][j];
    }
    bool flag = 0;
    for(int i = 1; i < n; ++ i) {
      if(tmp[i] > tmp[i + 1]) flag = 1;
    }
    if(flag) {
      ++ ans;
    }
    else for(int i = 1; i <= n; ++ i) now[i] = now[i] + s[i][j];
  }
  cout << ans << endl;
}