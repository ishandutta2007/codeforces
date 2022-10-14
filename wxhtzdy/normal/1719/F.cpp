/**
 *    author:  wxhtzdy
 *    created: 16.08.2022 17:22:54
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  const int MAX = 200005;
  vector<vector<int>> ds(MAX);
  for (int d = 1; d < MAX; d++) {
    for (int i = d; i < MAX; i += d) {
      ds[i].push_back(d);
    }
  }
  int tt;
  cin >> tt;
  while (tt--) {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }                       
    vector<int> divs;
    vector<vector<int>> id;
    vector<vector<long long>> sum;
    multiset<long long> st;
    vector<bool> can(n + 1, true);
    for (int k = n / 2; k >= 1; k--) {
      if (n % k != 0 || !can[k]) {
        continue;
      }                 
      id.push_back(vector<int>(n));
      for (int d : ds[k]) {
        can[d] = false;
      }
      sum.push_back({});
      divs.push_back(k);      
      vector<bool> was(n);
      int T = 0;
      for (int i = 0; i < n; i++) {
        if (was[i]) {
          continue;
        }    
        sum.back().push_back(0);
        int idx = i;
        while (!was[idx]) {
          sum.back().back() += a[idx];
          id[(int) divs.size() - 1][idx] = T;          
          was[idx] = true;
          idx = (idx + k) % n;    
        }
        st.insert(sum[(int) divs.size() - 1][T] * 1LL * k);
        T += 1;
      }
    }
    cout << *prev(st.end()) << '\n';  
    while (q--) {
      int i, x;
      cin >> i >> x;
      --i;
      int diff = x - a[i];
      a[i] = x;
      for (int k = 0; k < (int) divs.size(); k++) {
        st.erase(st.find(sum[k][id[k][i]] * 1LL * divs[k]));
        sum[k][id[k][i]] += diff;
        st.insert(sum[k][id[k][i]] * 1LL * divs[k]);
      }                     
      cout << *prev(st.end()) << '\n';  
    }
  }                                                                    
  return 0;
}