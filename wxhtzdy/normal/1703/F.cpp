/**
 *    author:  wxhtzdy
 *    created: 13.07.2022 15:34:24
**/
#include <bits/stdc++.h>

using namespace std;

template <typename T>
class fenwick {
  public:
  vector<T> fenw;
  int n;
  fenwick(int _n) : n(_n) {
    fenw.resize(n);
  }
  void modify(int x, T v) {
    while (x < n) {
      fenw[x] += v;
      x |= (x + 1);
    }
  }
  T get(int x) {
    T v{};
    while (x >= 0) {
      v += fenw[x];
      x = (x & (x + 1)) - 1;
    }
    return v;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    fenwick<int> fenw(n + 1);
    long long ans = 0;
    int cnt = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (a[i] >= i + 1) {
        continue;
      }        
      ans += cnt - fenw.get(i + 1);
      fenw.modify(a[i], +1);
      cnt += 1;
    }
    cout << ans << '\n';
  }                                                                    
  return 0;
}