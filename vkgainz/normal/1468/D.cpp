#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  ios_base::sync_with_stdio(false);
  int t; cin >> t;
  while(t--) {
    int n, m, a, b; cin >> n >> m >> a >> b;
    vector<int> s(m);
    for(int i = 0; i < m; i++)
      cin >> s[i];
    sort(s.begin(), s.end());
    int lo = 0, hi = m;
    int dist = abs(b - a);
    for(int i = 0; i < 20; i++) {
      //[lo, hi]
      int mid = (lo + hi + 1) / 2;
      bool work = false;
      if(mid >= dist) { //check the geq sign
        hi = mid;
        continue;
      }
      int mx = 0;
      for(int i = 0; i < mid; i++) {
        mx = max(mx, (i + 1) + s[mid - i - 1]);
      }
      if(a < b) {
        if(mx <= b - 1) {
          work = true;
        }
      }
      else {
        if(mx <= n - b) {
          work = true;
        }
      }
      if(work) {
        lo = mid;
      }
      else {
        hi = mid - 1;
      }
    }
    cout << lo << "\n";
  }
}