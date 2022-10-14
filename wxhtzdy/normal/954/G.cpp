/**
 *    author:  wxhtzdy
 *    created: 24.01.2022 18:52:08
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
  int n, r;
  long long k;
  cin >> n >> r >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<long long> pref(n);
  for (int i = 0; i < n; i++) {
    if (i > 0) {     
      pref[i] = pref[i - 1];
    }  
    pref[i] += a[i]; 
  }
  auto Check = [&](long long x) {
    long long _k = k;
    vector<long long> rem(n);
    long long delta = 0; 
    for (int i = 0; i < n; i++) {
      delta -= rem[i];
      long long c = pref[min(n - 1, i + r)] - (i > r ? pref[i - r - 1] : 0LL) + delta; 
      if (c >= x) {
        continue;
      }        
      long long d = x - c;
      if (_k < d) {
        return false;
      }          
      _k -= d;   
      if (i + 2 * r + 1 < n) {
        rem[i + 2 * r + 1] += d;
      }
      delta += d;     
    }
    return true;
  };
  long long low = -1, high = 2e18;
  while (low < high) {
    long long mid = (low + high + 1) >> 1;
    if (Check(mid)) {
      low = mid;    
    } else {
      high = mid - 1;
    }
  }
  cout << high << '\n';
  return 0;
}