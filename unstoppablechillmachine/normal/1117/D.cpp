#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long ll;
typedef long double ld;
#define int ll
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
#define pii pair<int, int>
const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

vector<vector<int>> one;
int mod;

void add(int &a, int b) {
  a += b;
  if (a >= MOD) {
    a -= MOD;
  }
}

int mult(int a, int b) {
  return (a * b) % MOD;
}

vector<vector<int>> multiply(int len1, int len2, vector<vector<int>> &M1, vector<vector<int>> &M2) {
  vector<vector<int>> res(mod, vector<int>(mod));
  for (int l = 0; l < mod; l++) {
    for (int r = 0; r < mod; r++) {
      for (int mid = 0; mid < mod; mid++) {
        add(res[l][r], mult(M1[l][mid], M2[(mod - mid) % mod][r]));
      }
    }
  }
  for (int l = 0; l < mod; l++) {
    for (int r = 0; r < mod; r++) {
      add(res[(l + len1) % mod][r], M2[l][r]);
      add(res[l][(r + len2) % mod], M1[l][r]);
    }
  }
  return res;
}

vector<vector<int>> b_pow(int n) {
  if (n == 1) {
    return one;
  }
  if (n & 1) {
    vector<vector<int>> kek = b_pow(n - 1);
    return multiply(1, n - 1, one, kek);
  }
  vector<vector<int>> res = b_pow(n / 2);
  return multiply(n / 2, n / 2, res, res);
}

void source() {
  int n;
  cin >> n >> mod;
  one.resize(mod, vector<int>(mod));
  one[0][0] = 1;
  vector<vector<int>> ans = b_pow(n);
  add(ans[n % mod][n % mod], 1);
  cout << ans[0][0];
}

signed main() {
#ifdef extraterrestrial_
  assert(freopen("input.txt", "r", stdin));
  //assert(freopen("output.txt", "w", stdout));
#else
#define TASK ""
  //assert(freopen(TASK".in", "r", stdin));
  //assert(freopen(TASK".out", "w", stdout));
  //assert(freopen("input.txt", "r", stdin));
  //assert(freopen("output.txt", "w", stdout));
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  source();
  return 0;
}