/**
 *  author: milos
 *  created: 26.09.2020 21:12:00
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long sum = n;
  vector<int> ans(n, 1);
  for (int i = 0; i < n; i++) {
    long long new_sum = a[i];
    int left_min = a[i], right_min = a[i];
    vector<int> new_ans(n);
    new_ans[i] = a[i];
    for (int j = i - 1; j >= 0; j--) {
      left_min = min(left_min, a[j]);
      new_sum += left_min;
      new_ans[j] = left_min;  
    }
    for (int j = i + 1; j < n; j++) {
      right_min = min(right_min, a[j]);
      new_sum += right_min;
      new_ans[j] = right_min;
    }                       
    if (new_sum > sum) {
      sum = new_sum;
      ans = new_ans;
    }
  }                   
  for (int i = 0; i < n; i++) {
    cout << ans[i] << ' ';
  }
  return 0;
}