/**
 *    author:  wxhtzdy
 *    created: 21.09.2022 15:07:02
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  long long ans = 0;
  if (n >= 4) {
    vector<long long> sum(n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        sum[i] += a[i][j];
      }
    }    
    sort(sum.rbegin(), sum.rend());
    ans = max(ans, sum[0] + sum[1] + sum[2] + sum[3]);
  }                                              
  if (m >= 4) {
    vector<long long> sum(m);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        sum[j] += a[i][j];
      }
    }    
    sort(sum.rbegin(), sum.rend());
    ans = max(ans, sum[0] + sum[1] + sum[2] + sum[3]);
  }
  {
    vector<long long> sum(m);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        sum[j] += a[i][j];
      }
    }
    for (int i = 0; i < n; i++) {
      long long me = 0;
      multiset<long long> st;
      for (int j = 0; j < m; j++) {
        me += a[i][j];
        st.insert(sum[j] - a[i][j]);
      }      
      for (int it = 0; it < 3 && !st.empty(); it++) {
        me += *prev(st.end());
        st.erase(prev(st.end()));
      }
      ans = max(ans, me);
    }
  }
  {
    vector<long long> sum(n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        sum[i] += a[i][j];
      }
    }
    for (int j = 0; j < m; j++) {
      long long me = 0;
      multiset<long long> st;
      for (int i = 0; i < n; i++) {
        me += a[i][j];
        st.insert(sum[i] - a[i][j]);
      }      
      for (int it = 0; it < 3 && !st.empty(); it++) {
        me += *prev(st.end());
        st.erase(prev(st.end()));
      }
      ans = max(ans, me);
    }
  }
  if (n <= m) {
    vector<long long> sum(m);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        sum[j] += a[i][j];
      }
    }
    for (int i1 = 0; i1 < n; i1++) {
      for (int i2 = i1 + 1; i2 < n; i2++) { 
        long long mx = 0;
        long long mx2 = 0;
        long long d = 0;
        for (int j = 0; j < m; j++) {
          long long me = sum[j] - a[i1][j] - a[i2][j];
          if (mx < me) {
            mx = me;
          } else {
            mx2 = max(mx2, me);
          }
          d += a[i1][j];
          d += a[i2][j];
        }
        ans = max(ans, d + mx + mx2); 
      }
    }
  } else {
    vector<long long> sum(n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        sum[i] += a[i][j];
      }
    }
    for (int j1 = 0; j1 < m; j1++) {
      for (int j2 = j1 + 1; j2 < m; j2++) {
        long long mx = 0;
        long long mx2 = 0;
        long long d = 0;
        for (int i = 0; i < n; i++) {
          long long me = sum[i] - a[i][j1] - a[i][j2];
          if (mx < me) {
            mx = me;
          } else {
            mx2 = max(mx2, me);  
          }
          d += a[i][j1];
          d += a[i][j2];
        }
        ans = max(ans, d + mx + mx2);        
      }
    }
  }
  cout << ans << '\n';
  return 0;
}