#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

pair <int, int> a[N];
int p[N];
bool was[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i].first);
    a[i].second = i;
  }
  sort(a, a + n);
  for (int i = 0; i < n; i++) {
    p[i] = a[i].second;
  }
  vector < vector <int> > res;
  for (int i = 0; i < n; i++) {
    if (was[i]) {
      continue;
    }
    int x = i;
    vector <int> cycle;
    while (!was[x]) {
      was[x] = true;
      cycle.push_back(x);
      x = p[x];
    }
    res.push_back(cycle);
  }
  int cnt = res.size();
  printf("%d\n", cnt);
  for (int i = 0; i < cnt; i++) {
    int cc = res[i].size();
    printf("%d", cc);
    for (int j = 0; j < cc; j++) {
      printf(" %d", res[i][j] + 1);
    }
    printf("\n");
  }
  return 0;
}