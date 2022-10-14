/**
 *    author:  milos
 *    created: 23.02.2021 10:17:00       
**/
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  string s, t;
  cin >> s >> t;
  vector<vector<int>> pos(26);
  for (int i = 0; i < n; i++) {
    pos[(int) (s[i] - 'a')].push_back(i);
  }
  /*int bot = 0, top = n, ans = 0;
  auto Can = [&](int x) {
    
  };
  while (bot <= top) {
    int mid = bot + top >> 1;
    if (Can(mid)) {
      ans = mid;    
      bot = mid - 1;
    } else {
      top = mid - 1;
    }
  } */
  vector<int> pref(m), suff(m);
  int curr = -1;
  vector<int> cnt(26, 0);
  for (int i = 0; i < m; i++) {
    int c = (int) (t[i] - 'a');
    while (curr > pos[c][cnt[c]]) {
      cnt[c]++;  
    }
    curr = pos[c][cnt[c]];
    cnt[c]++;
    pref[i] = curr;
  } 
  for (int i = 0; i < 26; i++) {
    cnt[i] = (int) pos[i].size() - 1;
  }
  curr = n;
  for (int i = m - 1; i >= 0; i--) {
    int c = (int) (t[i] - 'a');
    while (curr < pos[c][cnt[c]]) {
      cnt[c]--;
    }
    curr = pos[c][cnt[c]];
    cnt[c]--;
    suff[i] = curr;
  }
  int ans = 0;
  for (int i = 1; i < m; i++) {
    ans = max(ans, suff[i] - pref[i - 1]);  
  }
  cout << ans << '\n';  
  return 0;
}