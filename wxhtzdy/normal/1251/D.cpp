/**
 *    author:  milos
 *    created: 27.04.2021 13:12:31       
**/
#include <bits/stdc++.h>
 
using namespace std;

void solve() {
  int n;
  long long s;
  cin >> n >> s;
  vector<int> l(n), r(n);
  for (int i = 0; i < n; i++) {
    cin >> l[i] >> r[i];
  }
  auto Can = [&](int x) {
    long long t = 0;
    for (int i = 0; i < n; i++) {
      if (r[i] < x) {
        t += l[i];
      }  
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      if (l[i] > x) {
        t += l[i];
        cnt++;
      }
    }        
    vector<int> all;
    for (int i = 0; i < n; i++) {
      if (l[i] <= x && x <= r[i]) {
        all.push_back(l[i]);  
      }
    }
    sort(all.rbegin(), all.rend());
    for (int i = 0; i < (int) all.size(); i++) {
      if (cnt < (n + 1) / 2) {
        cnt++;
        t += x;
      } else {
        t += all[i];
      }
    }
    return cnt >= (n + 1) / 2 && t <= s;
  };
  int bot = 0, top = 1e9;
  while (bot <= top) {
    int mid = bot + top >> 1;
    if (Can(mid)) {
      bot = mid + 1;
    } else {
      top = mid - 1;
    }
  }
  cout << top << '\n';  
} 

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    solve();
  }
  return 0;
}