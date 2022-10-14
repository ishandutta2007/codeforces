#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<int> left(26, -1);
  vector<int> right(26, -1);
  for (int i = 0; i < n; i++) {
    int x = (int) s[i] - 'A';
    if (left[x] == -1) {
      left[x] = i;
    }
    right[x] = i;
  }
  vector<pair<int, int>> v;
  for (int i = 0; i < 26; i++) {
    if (left[i] == -1) {
      continue;
    }
    v.emplace_back(left[i], 1);
    v.emplace_back(right[i], -1);
  }
  sort(v.begin(), v.end());
  int t = 0, ans = 0;
  for (int i = 0; i < (int) v.size(); i++) {
    if (i != (int) v.size() - 1 && v[i].first == v[i + 1].first) {
      swap(v[i], v[i + 1]);  
    }     
    t += v[i].second;
    ans = max(ans, t); 
  }
  if (ans > k) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  return 0;   
}