#include <bits/stdc++.h>

using namespace std;

long long a, b;
long long ans;

void dfs(long long x, int cnt) {
  if (x > b) {
    return;
  }
  if (a <= x && x <= b && cnt == 1) {
    ans++;
  }
  if (cnt == 0) {
    dfs(x * 2, cnt + 1);
  }
  dfs(x * 2 + 1, cnt);
}

int main() {
  cin >> a >> b;
  ans = 0;
  dfs(1, 0);
  cout << ans << endl;
  return 0;
}