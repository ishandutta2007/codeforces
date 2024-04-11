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

const int MOD = 1e9 + 7;
 
inline void add(int &a, int b) {
  a += b;
  if (a >= MOD) {
    a -= MOD;
  }
}

inline void sub(int &a, int b) {
  a -= b;
  if (a < 0) {
    a += MOD;
  }
}

inline int sum(int a, int b) {
  add(a, b);
  return a;
}

int mult(int a, int b) {
  return (a * 1ll * b) % MOD;
}

int b_pow(int a, int b) {
  int cur = a, ans = 1;
  while (b > 0) {
    if (b & 1) {
      ans = mult(ans, cur);
    }
    b >>= 1;
    cur = mult(cur, cur);
  }  
  return ans;
}

int inv(int a) {
  return b_pow(a, MOD - 2);
}


signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<vector<int>> a(2, vector<int>(n));
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < n; j++) {
        cin >> a[i][j];
        a[i][j]--;
      }
    } 
    vector<vector<int>> g(n);   
    for (int i = 0; i < n; i++) {
      g[a[0][i]].pb(a[1][i]);
      g[a[1][i]].pb(a[0][i]);
    }
    vector<bool> used(n);
    function<void(int)> dfs = [&](int v) {
      used[v] = true;
      for (auto u : g[v]) {
        if (!used[u]) {
          dfs(u);
        }
      }
    };
    int answer = 1;
    for (int i = 0; i < n; i++) {
      if (!used[i]) {
        dfs(i);
        answer = mult(answer, 2);
      }
    }
    cout << answer << '\n';
  }
}