/**
 *    author:  tourist
 *    created: 18.09.2017 16:06:40       
**/
#include <bits/stdc++.h>

using namespace std;

char s[1234567];

int main() {
  int n;
  scanf("%d", &n);
  scanf("%s", s);
  vector<int> food, pacmans;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'P') pacmans.push_back(i);
    if (s[i] == '*') food.push_back(i);
  }
  int low = 0, high = 3 * n;
  while (low < high) {
    int mid = (low + high) >> 1;
    int ptr = 0;
    for (int x : pacmans) {
      int from = x, to = x;
      while (ptr < (int) food.size()) {
        from = min(from, food[ptr]);
        to = max(to, food[ptr]);
        int need = to - from + min(to - x, x - from);
        if (need > mid) {
          break;
        }
        ptr++;
      }
    }
    if (ptr == (int) food.size()) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }
  printf("%d\n", low);
  return 0;
}