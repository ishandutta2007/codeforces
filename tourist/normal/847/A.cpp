/**
 *    author:  tourist
 *    created: 18.09.2017 16:13:41       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  vector<int> pr(n), ne(n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &pr[i], &ne[i]);
    pr[i]--; ne[i]--;
  }
  vector < pair <int, int> > lists;
  for (int i = 0; i < n; i++) {
    if (pr[i] == -1) {
      int p = i;
      while (ne[p] != -1) {
        p = ne[p];
      }
      lists.emplace_back(i, p);
    }
  }
  for (int i = 1; i < (int) lists.size(); i++) {
    ne[lists[i - 1].second] = lists[i].first;
    pr[lists[i].first] = lists[i - 1].second;
  }
  for (int i = 0; i < n; i++) {
    printf("%d %d\n", pr[i] + 1, ne[i] + 1);
  }
  return 0;
}