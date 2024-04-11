#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll
#define F first
#define S second
 
vector<int> good[30];

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  good[1] = {1, 2};
  for (int level = 1; level <= 25; level++) {
    sort(all(good[level]));
    good[level].resize(unique(all(good[level])) - good[level].begin());
    for (auto it : good[level]) {
      for (auto it2 : good[level]) {
        if (it % 2 == 0) {
          good[level + 1].pb(it + it2 + 1);
        }
      }
    }
  }
  int n;
  cin >> n;
  bool ok = false;
  for (int i = 1; i <= 25; i++) {
    if (find(all(good[i]), n) != good[i].end()) {
      ok = true;
    }
  }  
  cout << (ok ? 1 : 0) << '\n';
}