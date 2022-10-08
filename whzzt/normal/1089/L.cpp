#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef wxh010910
  freopen("input.txt", "r", stdin);
#endif
  int n, m;
  scanf("%d %d", &n, &m);
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i].first);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i].second);
  }
  sort(a.begin(), a.end());
  int need = m;
  vector<int> choice;
  for (int i = 0, j = 0; i < n; i = j) {
    while (j < n && a[j].first == a[i].first) {
      ++j;
    }
    for (int k = i; k + 1 < j; ++k) {
      choice.push_back(a[k].second);
    }
    --need;
  }
  sort(choice.begin(), choice.end());
  long long answer = 0;
  for (int i = 0; i < need; ++i) {
    answer += choice[i];
  }
  printf("%lld\n", answer);
  return 0;
}