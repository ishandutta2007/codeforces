#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n, m;
  cin >> n >> m;
  long long answer = 0;
  int remain = 0;
  for (int i = 0; i < n; ++i) {
    int now;
    cin >> now;
    int need = max((remain + m - 1) / m, (now + remain) / m);
    answer += need;
    remain = max(remain + now - need * m, 0);
  }
  if (remain) {
    ++answer;
  }
  cout << answer << endl;
  return 0;
}