#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define f first
#define s second
using ll = long long;
const int MX = 4e5+5;

int main() {
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i], --a[i];
    vector<pair<int, int>> seg;
    int l = 0;
    for(int i=1;i<n;i++) {
      if(a[i] == a[i-1]) {
        seg.push_back({l, i-1});
        l = i;
      }
    }
    seg.push_back({l, n-1});
    int num[n];
    memset(num, 0, sizeof(num));
    for(auto &it : seg){
      ++num[a[it.f]];
      ++num[a[it.s]];
    }
    int mx = 0;
    int idxMx = 0;
    for(int i=0;i<n;i++) {
      if(num[i] > mx) {
        mx = num[i];
        idxMx = i;
      }
    }
    if(mx <= seg.size() + 1) {
      cout << seg.size() - 1 << "\n";
    }
    else {
      int numAdd = 0;
      for(auto &it : seg) {
        for(int i=it.f+1;i<=it.s;i++) {
          if(a[i] != idxMx && a[i-1] != idxMx) ++numAdd;
        }
      }
      int x = seg.size() + numAdd;
      if(mx <= x + 1) {
        cout << mx - 2 << "\n";
      }
      else cout << -1 << "\n";
    }
  }
}