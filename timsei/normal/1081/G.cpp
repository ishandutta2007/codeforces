#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, k, q, A[N], num[2], Min, mod, ans, I4;

namespace {
  int add(int x) {return (x >= mod) ? x - mod : x;}
  int sub(int x) {return (x < 0) ? x + mod : x;}
  void Add(int &x, int y) {x = add(x + y);}
  void Sub(int &x, int y) {x = sub(x - y);}
  int Pow(int x, int y = mod - 2) {
    int res = 1;
    for(; y; y >>= 1, x = 1LL * x * x % mod) {
      if(y & 1)
	res = 1LL * res * x % mod;
    }
    return res;
  }
}

vector <int> L;

void solve(int l, int r, int k) {
  if(l > r) return;
  if(k <= 1 || l == r) {
    int Len = r - l + 1;
    Min = min(Min, Len);
    L.push_back(Len);
    Add(ans, 1LL * Len * (Len - 1) % mod * I4 % mod);
    return;
  }
  int mid = (l + r) >> 1;
  solve(l, mid, k - 1);
  solve(mid + 1, r, k - 1);
}

int inv[N];

int calc(int Sum, int x, int y) {
  int L = max(Sum - y, 1), R = min(Sum - 1, x);
  return max(R - L + 1, 0);
}

int main() {
  cin >> n >> k >> mod;
  Min = 1e9;
  I4 = Pow(4);
  inv[0] = 0;
  for(int i = 1; i <= n * 2; ++ i) inv[i] = Pow(i);
  solve(1, n, k);
  for(int i = 0; i < (int) L.size(); ++ i) ++ num[L[i] - Min];
  for(int i = 1; i <= 2 * (Min + 1); ++ i) {
    int tot = 0;
    Add(tot, 1LL * num[0] * (num[0] - 1) % mod * inv[2] % mod * calc(i, Min, Min) % mod);
    Add(tot, 1LL * num[1] * (num[1] - 1) % mod * inv[2] % mod * calc(i, Min + 1, Min + 1) % mod);
    Add(tot, 1LL * num[0] * num[1] % mod * calc(i, Min + 1, Min) % mod);
    //cerr << i <<" " << tot << endl;
    Add(ans, 1LL * tot * inv[2] % mod * sub(1 - 2LL * inv[i] % mod) % mod);
  }
  printf("%d\n", ans);
}