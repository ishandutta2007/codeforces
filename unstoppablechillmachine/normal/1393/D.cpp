#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back  
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll    

#define left left_suka
#define right right_suka

const int N = 2010;
char c[N][N];
int to_left[N][N], to_right[N][N], to_up[N][N], to_down[N][N];
int left[N][N], right[N][N], down[N][N], up[N][N];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> c[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (c[i][j] == c[i][j - 1]) {
        to_left[i][j] = to_left[i][j - 1] + 1;
      }
      else {
        to_left[i][j] = 0;
      }
    }
    for (int j = m; j >= 1; j--) {
      if (c[i][j] == c[i][j + 1]) {
        to_right[i][j] = to_right[i][j + 1] + 1;
      }
      else {
        to_right[i][j] = 0;
      }
    }
  }
  for (int j = 1; j <= m; j++) {
    for (int i = 1; i <= n; i++) {
      if (c[i][j] == c[i - 1][j]) {
        to_up[i][j] = to_up[i - 1][j] + 1;
      }
      else {
        to_up[i][j] = 0;
      }
    }
    for (int i = n; i >= 1; i--) {
      if (c[i][j] == c[i + 1][j]) {
        to_down[i][j] = to_down[i + 1][j] + 1;
      }
      else {
        to_down[i][j] = 0;
      }
    }
  }

  //fuckfuckfuck

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (c[i][j] != c[i][j - 1]) {
        left[i][j] = 1;
      }
      else {
        left[i][j] = min({left[i][j - 1], to_up[i][j], to_down[i][j]}) + 1;
      }
    }

    for (int j = m; j >= 1; j--) {
      if (c[i][j] != c[i][j + 1]) {
        right[i][j] = 1;
      }
      else {
        right[i][j] = min({right[i][j + 1], to_up[i][j], to_down[i][j]}) + 1;
      }
    }
  }  

  for (int j = 1; j <= m; j++) {
    for (int i = 1; i <= n; i++) {
      if (c[i][j] != c[i - 1][j]) {
        up[i][j] = 1;
      }
      else {
        up[i][j] = min({up[i - 1][j], to_right[i][j], to_left[i][j]}) + 1;
      }
    }

    for (int i = n; i >= 1; i--) {
      if (c[i][j] != c[i + 1][j]) {
        down[i][j] = 1;
      }
      else {
        down[i][j] = min({down[i + 1][j], to_right[i][j], to_left[i][j]}) + 1;
      }
    }
  }

  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      ans += min({down[i][j], up[i][j], right[i][j], left[i][j]});
    }
  }
  cout << ans << '\n';
}