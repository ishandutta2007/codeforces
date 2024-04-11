#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int main() {
  int n;
  scanf("%d", &n);
  map < int, set < pair <int, int> > > mp;
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    mp[y - x].insert(make_pair(x, y));
  }
  vector < pair <int, int> > p(n);
  for (int i = 0; i < n; i++) {
    int diff;
    scanf("%d", &diff);
    if (mp[diff].empty()) {
      puts("NO");
      return 0;
    }
    p[i] = *(mp[diff].begin());
    mp[diff].erase(mp[diff].begin());
  }
  vector <int> row(N, -1);
  vector <int> col(N, -1);
  for (int i = 0; i < n; i++) {
    int x = p[i].first;
    int y = p[i].second;
    if (row[x] != y - 1 || col[y] != x - 1) {
      puts("NO");
      return 0;
    }
    row[x]++;
    col[y]++;
  }
  puts("YES");
  for (int i = 0; i < n; i++) {
    int x = p[i].first;
    int y = p[i].second;
    printf("%d %d\n", x, y);
  }
  return 0;
}