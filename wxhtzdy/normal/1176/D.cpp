/**
 *  author: milos
 *  created: 04.01.2021 11:15:37
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  const int N = 2750132;
  vector<int> prime(N, 1), id(N, 0), mx(N, 0);
  prime[0] = prime[1] = 0;
  for (int i = 2; i < N; i++) {
    mx[i] = i;
  }
  int r = 1;
  for (int i = 2; i < N; i++) {
    if (mx[i] != i) {
      mx[i] = i / mx[i];
    }
    if (prime[i]) {
      id[i] = r;
      r += 1;
      for (int j = i + i; j < N; j += i) {
        prime[j] = 0;
        mx[j] = min(mx[j], i);  
      }
    }
  }
  int n;
  cin >> n;
  vector<int> a(2 * n);
  map<int, int> cnt;
  for (int i = 0; i < 2 * n; i++) {
    cin >> a[i];    
    cnt[a[i]] += 1;
  }
  sort(a.rbegin(), a.rend());
  vector<int> ans;
  for (int i = N - 1; i >= 2; i--) {
    while (cnt[i] >= 1) {
      cnt[i] -= 1;
      if (prime[i] == 1) {
        cnt[id[i]] -= 1;
        ans.push_back(id[i]);
      } else {
        ans.push_back(i);
        cnt[mx[i]] -= 1;
      }
    }  
  }
  assert((int) ans.size() == n);  
  for (int i = 0; i < (int) ans.size(); i++) {
    cout << ans[i] << " ";
  }
  return 0;
}