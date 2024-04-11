#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int n, l[N], cnt = 0;
vector<int> ans[N], all[N], cur;

void Rec() {
  if (cnt == n) {
    return;
  }
  int len = (int) cur.size();
  if (!all[len].empty()) {
    ans[all[len].back()] = cur;
    all[len].pop_back();
    cnt++;
    return;
  }
  for (int i = 0; i < 2; i++) {
    cur.push_back(i);
    Rec();
    cur.pop_back();
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> l[i];
    all[l[i]].push_back(i);
  }
  Rec();
  if (cnt != n) {
    cout << "NO" << '\n';
    return 0;
  }
  cout << "YES" << '\n';
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < l[i]; j++) {
      cout << ans[i][j];
    }
    cout << '\n';
  }
  return 0;
}