#include <bits/stdc++.h>

using namespace std;

vector<pair<int, char>> ans;
int n, m, k, cur;

void add(int f, char c) {
  if (f == 0 || cur == k)
    return;
  f = min(f, k - cur);
  ans.push_back({f, c});
  cur += f;
}

int main() {
  scanf("%d%d%d", &n, &m, &k);
  cur = 0;

  // Run down to bottom
  add(n-1, 'D');
  
  // Exclusive move for bottom row
  for(int j = 1; j < m; ++j) {
    add(1, 'R');
    add(n-1, 'U');
    add(n-1, 'D');
  }
  add(m-1, 'L');

  // Move for row n-1 downto 1
  for(int i = n-1; i >= 1; --i) {
    add(1, 'U');
    add(m-1, 'R');
    add(m-1, 'L');
  }

  if (cur < k) {
    puts("NO");
  } else {
    puts("YES");
    printf("%d\n", ans.size());
    for(auto e: ans) 
      printf("%d %c\n", e.first, e.second);
  }

  return 0;
}