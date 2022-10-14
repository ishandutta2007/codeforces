/**
 *    author:  wxhtzdy
 *    created: 26.06.2022 18:30:59
**/
#include <bits/stdc++.h>

using namespace std;

int m;

vector<pair<int, long long>> Do(vector<int> a) {
  vector<pair<int, long long>> f;
  for (int i = 0; i < (int) a.size(); i++) {
    long long p = 1;
    while (a[i] % m == 0) {
      p *= m;
      a[i] /= m;
    }
    if (f.empty() || f.back().first != a[i]) {
      f.emplace_back(a[i], p);
    } else {
      f.back().second += p;
    }
  }
  return f;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }         
    int k;
    cin >> k;
    vector<int> b(k);
    for (int i = 0; i < k; i++) {
      cin >> b[i];
    }
    cout << (Do(a) == Do(b) ? "Yes" : "No") << '\n';
  }                                                                    
  return 0;
}