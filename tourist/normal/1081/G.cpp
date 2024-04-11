/**
 *    author:  tourist
 *    created: 16.12.2018 19:03:30       
**/
#include <bits/stdc++.h>

using namespace std;

int md;

inline void add(int &a, int b) {
  a += b;
  if (a >= md) a -= md;
}

inline void sub(int &a, int b) {
  a -= b;
  if (a < 0) a += md;
}

inline int mul(int a, int b) {
  return (int) ((long long) a * b % md);
}

inline int power(int a, long long b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = mul(res, a);
    }
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}

inline int inv(int a) {
  a %= md;
  if (a < 0) a += md;
  int b = md, u = 0, v = 1;
  while (a) {
    int t = b / a;
    b -= t * a; swap(a, b);
    u -= t * v; swap(u, v);
  }
  assert(b == 1);
  if (u < 0) u += md;
  return u;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k >> md;
  if (k >= 20 || n <= (1 << (k - 1))) {
    cout << 0 << '\n';
    return 0;
  }
  int bc = (1 << (k - 1));
  int small_size = n / bc;
  int big_size = small_size + 1;
  int big_cnt = n % bc;
  int small_cnt = bc - big_cnt;

  vector<int> blocks(bc);
  for (int i = 0; i < n; i++) {
    blocks[i % (int) blocks.size()]++;
  }
  map<int,int> mp;
  for (int x : blocks) {
    mp[x]++;
  }

  vector<int> fact(n + 1), inv_fact(n + 1);
  fact[0] = inv_fact[0] = 1;
  for (int i = 1; i <= n; i++) {
    fact[i] = mul(fact[i - 1], i);
    inv_fact[i] = inv(fact[i]);
  }
/*  auto C = [&](int n, int k) {
    if (k < 0 || k > n) return 0;
    return mul(fact[n], mul(inv_fact[k], inv_fact[n - k]));
  };*/
  int ans = 0;
  for (int b1id = 0; b1id < bc; b1id++) {
    int b = blocks[b1id];
    add(ans, mul(mul(b, b - 1), inv(4)));
  }
  vector<int> sum_inv(n + 1);
  for (int i = 0; i < n; i++) {
    sum_inv[i + 1] = sum_inv[i];
    add(sum_inv[i + 1], inv(i + 1));
  }
  for (int b1id = 0; b1id < bc; b1id++) {
    int b1 = blocks[b1id];
    if (b1 == small_size) small_cnt--;
    else big_cnt--;
    for (int x = 2; x <= b1; x++) {
      if (small_cnt > 0) {
        int aux = sum_inv[x + small_size];
        sub(aux, sum_inv[x]);
        int prob = mul(x - 1, aux);
        add(ans, mul(small_cnt, mul(prob, inv(2))));
      }
      if (big_cnt > 0) {
        int aux = sum_inv[x + big_size];
        sub(aux, sum_inv[x]);
        int prob = mul(x - 1, aux);
        add(ans, mul(big_cnt, mul(prob, inv(2))));
      }
    }
    if (b1 == small_size) small_cnt++;
    else big_cnt++;
  }
  cout << ans << '\n';
  return 0;
}