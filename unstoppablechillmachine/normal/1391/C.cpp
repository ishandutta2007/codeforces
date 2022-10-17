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

const int mod = 1e9 + 7;

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int n;
  cin >> n;
  int fac = 1;
  for (int i = 1; i <= n; i++) {
    fac = (fac * i) % mod;
  }
  int ans = 1;
  for (int i = 1; i < n; i++) {
    ans = (ans * 2) % mod;
  }
  cout << (fac - ans + mod) % mod << '\n';
}