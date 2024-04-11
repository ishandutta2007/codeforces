/**
 *    author:  wxhtzdy
 *    created: 07.07.2022 17:05:31
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int m;
  cin >> m;
  vector<int> op(m);
  vector<int> x(m);
  vector<int> l(m);
  vector<int> c(m);
  for (int i = 0; i < m; i++) {
    cin >> op[i];
    if (op[i] == 1) {
      cin >> x[i];
    } else {
      cin >> l[i] >> c[i];
    }
  }
  vector<int> seq;
  const int MAX = 1e5;
  for (int i = 0; i < m && (int) seq.size() < MAX; i++) {
    if (op[i] == 1) {
      seq.push_back(x[i]);
    } else {
      for (int it = 0; it < c[i]; it++) {
        for (int j = 0; j < l[i] && (int) seq.size() < MAX; j++) {
          seq.push_back(seq[j]);
        }
      }
    }
  }
  vector<long long> len(1, 0);
  for (int i = 0; i < m; i++) {
    int d = (op[i] == 1 ? 1 : l[i] * c[i]);
    len.push_back(len.back() + d);
  }
  int n;
  cin >> n;
  int ptr = 0;
  for (int i = 0; i < n; i++) {
    long long a;
    cin >> a;
    while (len[ptr + 1] < a) {
      ptr += 1;
    }               
    if (op[ptr] == 1) {
      cout << x[ptr] << " ";      
      continue;
    }
    int p = a - len[ptr] - 1;
    assert(p >= 0);
    assert(l[ptr] <= (int) seq.size());
    cout << seq[p % l[ptr]] << " ";    
  }
  return 0;
}