/**
 *    author:  tourist
 *    created: 04.01.2019 17:48:08       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    int len = (int) s.size();
    int cnt_open = 0;
    int cnt_close = 0;
    for (char c : s) {
      cnt_open += (c == '(');
      cnt_close += (c == ')');
    }
    int bal = 0;
    for (int j = 0; j < len; j++) {
      if (s[j] == '(') bal++; else {
        if (bal > 0) {
          cnt_open--;
          cnt_close--;
          bal--;
        }
      }
    }
    if (cnt_open > 0 && cnt_close > 0) {
      continue;
    }
    a.push_back(cnt_open - cnt_close);
  }
  sort(a.begin(), a.end());
  int ans = 0;
  int i = 0, j = (int) a.size() - 1;
  while (i < j) {
    if (a[i] + a[j] == 0) {
      ans++;
      i++;
      j--;
    } else {
      if (a[i] + a[j] > 0) {
        j--;
      } else {
        i++;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}