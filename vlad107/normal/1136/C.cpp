#include <iostream>
#include <set>
#include <vector>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<multiset<int>> a(n + m), b(n + m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int x;
      cin >> x;
      a[i+j].insert(x);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int x;
      cin >> x;
      b[i+j].insert(x);
    }
  }
  for (int i = 0; i < n + m; i++) {
    if (a[i] != b[i]) {
      puts("NO");
      return 0;
    }
  }
  puts("YES");
  return 0;
}