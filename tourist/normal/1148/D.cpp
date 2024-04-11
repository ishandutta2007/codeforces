/**
 *    author:  tourist
 *    created: 01.06.2019 18:02:25       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  vector<int> lt;
  vector<int> gt;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    if (a[i] < b[i]) {
      lt.push_back(i);
    } else {
      gt.push_back(i);
    }
  }
  vector<int> ans;
  if (lt.size() > gt.size()) {
    sort(lt.begin(), lt.end(), [&](int i, int j) {
      return b[i] > b[j];
    });
    ans = lt;
  } else {
    sort(gt.begin(), gt.end(), [&](int i, int j) {
      return a[i] < a[j];
    });
    ans = gt;
  }
  cout << ans.size() << '\n';
  for (int i = 0; i < (int) ans.size(); i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << ans[i] + 1;
  }
  cout << '\n';
  return 0;
}