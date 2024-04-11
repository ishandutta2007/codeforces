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
 
const int iter = 30;
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int n, m, p;
  cin >> n >> m >> p;
  vector<int> vl(n);
  vector<vector<int>> bt(n, vector<int>(p));
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    int ones = 0;
    for (int j = 0; j < m; j++) {
      if (s[j] == '1') {
        vl[i] |= 1ll << j;
        bt[i][ones++] = 1ll << j;
      }
    }  
  }
  pair<int, int> best = {0, 0};
  vector<int> sum(1 << p);
  for (int i = 0; i < iter; i++) {
    int id = rnd() % n;
    fill(all(sum), 0);
    //cout << "NEW_ITERATION " << id << '\n';
    for (int j = 0; j < n; j++) {
      int cur_vl = (vl[id] & vl[j]), mask = 0;
      for (int bit = 0; bit < p; bit++) {
        if (cur_vl & bt[id][bit]) {
          mask |= 1 << bit;
        }
      }
      //cout << j << ' ' << mask << '\n';
      sum[mask]++;
    }
    for (int bit = 0; bit < p; bit++) {
      for (int mask = 0; mask < (1 << p); mask++) {
        if (!((mask >> bit) & 1)) {
          sum[mask] += sum[mask ^ (1 << bit)];
        }
      }
    }
    for (int mask = 0; mask < (1 << p); mask++) {
      if (sum[mask] >= (n + 1) / 2 && __builtin_popcount(mask) > best.first) {
        //cout << id << ' ' << mask << ' ' << sum[mask] << '\n';
        best.first = __builtin_popcount(mask);
        best.second = 0;
        for (int bit = 0; bit < p; bit++) {
          if ((mask >> bit) & 1) {
            best.second |= bt[id][bit];
          }
        }
      }
    } 
  }
  for (int i = 0; i < m; i++) {
    cout << ((best.second >> i) & 1);
  }
  cout << '\n';
}