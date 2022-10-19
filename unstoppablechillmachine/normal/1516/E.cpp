#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back  
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll

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

/*map<vector<int>, int> used;

void go(vector<int> perm, int cur, int mx) {
  if (used.count(perm) && used[perm] % 2 != cur % 2) {
    cout << used[perm] << ' ' << cur << endl;
    assert(false);
  }
  else {
    used[perm] = cur;
  }
  if (cur == mx) {
    return;
  }
  for (int i = 0; i < SZ(perm); i++) {
    for (int j = 0; j < SZ(perm); j++) {
      if (i == j) continue;
      swap(perm[i], perm[j]);
      go(perm, cur + 1, mx);
      swap(perm[i], perm[j]);
    }
  }
}*/

const int N = 1010;
int dp[N][N], C[N][N], ans[N], f[N], calc[N][N], inv_f[N];
 
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i <= 4 * k; i++) {
    f[i] = (i ? mult(f[i - 1], i) : 1);
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; j++) {
      C[i][j] = sum(C[i - 1][j], C[i - 1][j - 1]);
    }
  }
  vector<int> ans(k + 1);
  for (int i = 0; i <= k; i += 2) {
    ans[i] = 1;
  }
  vector<int> inv_p(2 * k + 1);
  for (int i = 1; i <= 2 * k; i++) {
    inv_p[i] = inv(i);
    inv_f[i] = inv(f[i]);
  }
  dp[0][0] = 1;
  for (int len = 2; len <= min(n, 2 * k); len++) {
    for (int last_len = 2; last_len <= len; last_len++) {
      if (n - (len - last_len) < last_len) {
        calc[len][last_len] = 0;
        continue;
      }
      calc[len][last_len] = 1;
      for (int i = n - len + last_len; i > n - len; i--) {
        calc[len][last_len] = mult(calc[len][last_len], i);
      }
      //cout << len << ' ' << last_len << ' ' << calc[len][last_len] << '\n';
      for (int i = 1; i <= last_len; i++) {
        calc[len][last_len] = mult(calc[len][last_len], inv_p[i]);
      }
      //cout << len << ' ' << last_len << ' ' << calc[len][last_len] << '\n';
    }
  }
  for (int cnt_cycles = 1; cnt_cycles <= k; cnt_cycles++) {
    for (int len = cnt_cycles * 2; len <= min(n, 2 * k); len++) {
      for (int last_len = 2; len - last_len >= 2 * (cnt_cycles - 1); last_len++) {
        add(dp[cnt_cycles][len], mult(f[last_len - 1], mult(dp[cnt_cycles - 1][len - last_len], calc[len][last_len])));
      }
      //cout << cnt_cycles << ' ' << len << ' ' << dp[cnt_cycles][len] << '\n';
      int kek = len - cnt_cycles;
      for (int i = kek; i <= k; i += 2) {
        add(ans[i], mult(dp[cnt_cycles][len], inv_f[cnt_cycles]));
      }
    }
  }
  for (int i = 1; i <= k; i++) {
    cout << ans[i] << ' ';
  }
  cout << '\n';
}