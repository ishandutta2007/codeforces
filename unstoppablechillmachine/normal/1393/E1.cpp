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
const int N = 50010;
const int P = 239017;
void add(int &a, int b) {
  a += b;
  if (a >= MOD) {
    a -= MOD;
  }
}

int pl[N], p_pow[N];
vector<int> hs[N];
string s[N];

inline char get_letter(pair<int, int> a, int num) {
  if (!a.S || a.S > num) {
    return s[a.F][num - 1];
  }
  return s[a.F][num];
}

inline int get_hash(pair<int, int> a, int len) {
  if (a.S == 0 || a.S > len) {
    return hs[a.F][len] * p_pow[20000 - len];
  }
  return (hs[a.F][a.S - 1] * P + (hs[a.F][len + 1] - hs[a.F][a.S])) * p_pow[20000 - len - 1];
}

string get_s(pair<int, int> a, int len) {
  string res;
  for (int i = 0; i < SZ(s[a.F]); i++) {
    if (SZ(res) < len && i + 1 != a.S) {
      res.pb(s[a.F][i]);
    }
  }
  return res;
}

bool cmp(pair<int, int> a, pair<int, int> b) {
  int len1 = SZ(s[a.F]) - (a.S != 0), 
  len2 = SZ(s[b.F]) - (b.S != 0);
  int l = 0, r = min(len1, len2) + 1;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    if (get_hash(a, mid) == get_hash(b, mid)) {
      l = mid;
    }
    else {
      r = mid;
    }
  }
  if (l == min(len1, len2)) {
    if (len1 == len2) return a < b;
    return len1 < len2;
  }
  return get_letter(a, l + 1) < get_letter(b, l + 1);
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  p_pow[0] = 1;
  for (int i = 1; i <= 20000; i++) {
    p_pow[i] = p_pow[i - 1] * P;
  }
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    hs[i].resize(SZ(s[i]) + 1);
    for (int j = 1; j <= SZ(s[i]); j++) {
      hs[i][j] = hs[i][j - 1] + p_pow[j] * s[i][j - 1];
    }
  }
  vector<pair<int, int>> order;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= SZ(s[i]); j++) {
      order.pb({i, j});
    }
  }
  //cout << "OK" << endl;
  sort(all(order), cmp);
  /*for (auto it : order) {
    cout << it.F << ' ' << it.S << '\n';
  }*/
  vector<vector<int>> pos(n);
  for (int i = 0; i < n; i++) {
    pos[i].resize(SZ(s[i]) + 1);
  }
  for (int i = 0; i < SZ(order); i++) {
    pos[order[i].F][order[i].S] = i + 1;
  }
  vector<vector<int>> dp(n);
  for (int i = 0; i < n; i++) {
    int cs = 0;
    dp[i].resize(SZ(s[i]) + 1);
    for (int j = 0; j < SZ(order); j++) {
      add(cs, pl[j]);
      pl[j] = 0;
      if (order[j].F == i) {
        dp[i][order[j].S] = cs + (i == 0);
      }
    }
    if (i + 1 < n) {
      for (int j = 0; j <= SZ(s[i]); j++) {
        add(pl[pos[i][j]], dp[i][j]);
      }
    }
  }  
  int ans = 0;
  for (int i = 0; i <= SZ(s[n - 1]); i++) {
    add(ans, dp[n - 1][i]);
  }
  cout << ans << '\n';
}