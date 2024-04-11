#include <bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i;
    sum += a[i].first;
  }
  sort(a.begin() + 1, a.end());
  vector<int> v;
  v.push_back(1);
  int sum1 = a[0].first;
  for (int i = 1; i < n; i++) {
    if (a[i].first * 2 <= a[0].first) {
      v.push_back(a[i].second + 1);
      sum1 += a[i].first;
    }
  }
  if (sum1 <= sum / 2) {
    cout << 0 << '\n';
    return 0;
  }
  sort(v.begin(), v.end());
  cout << (int) v.size() << '\n';
  for (int i = 0; i < (int) v.size(); i++) {
    cout << v[i] << " ";
  }
  return 0;
}