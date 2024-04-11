#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

set < pair <int, int> > s[7];
int p[N], a[N], b[N];
bool alive[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", p + i);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", b + i);
  }
  for (int i = 0; i < n; i++) {
    s[a[i]].insert(make_pair(p[i], i));
    s[b[i]].insert(make_pair(p[i], i));
    alive[i] = true;
  }
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int c;
    scanf("%d", &c);
    int ans = -1;
    while (!s[c].empty()) {
      int x = (*(s[c].begin())).second;
      s[c].erase(s[c].begin());
      if (!alive[x]) {
        continue;
      }
      alive[x] = false;
      ans = p[x];
      break;
    }
    printf("%d ", ans);
  }
  puts("");
  return 0;
}