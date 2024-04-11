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
 
const int N = 1e6 + 10;
bool can[N];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  can[2020] = can[2021] = 1;
  for (int i = 2022; i < N; i++) {
    if (can[i - 2020] || can[i - 2021]) {
      can[i] = true;
    }
  }
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    cout << (can[n] ? "YES\n" : "NO\n");
  }
}