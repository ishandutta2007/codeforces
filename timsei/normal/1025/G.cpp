#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 505;
const int mod = 1e9 + 7;

vector <int> G[N];

int fa[N], ans, n;

int Pow(int x, int y) {
  int res = 1;
  for(; y; y >>= 1, x = x * x % mod) {
    if(y & 1) {
      res = res * x % mod;
    }
  }
  return res;
}

main(void) {
  cin >> n;
  for(int i = 1; i <= n; ++ i) {
    cin >> fa[i];
    if(fa[i] == -1) continue;
    G[fa[i]].push_back(i);
  }
  int now = 0;
  for(int i = 1; i <= n; ++ i) {
    if(fa[i] == -1)
      now = (now + Pow(2, G[i].size()) - 1) % mod;
  }
  now = Pow(2, n - 1) - 1 - now + mod;
  now %= mod;
  cout << now << endl;
}