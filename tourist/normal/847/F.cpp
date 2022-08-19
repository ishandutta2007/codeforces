/**
 *    author:  tourist
 *    created: 18.09.2017 16:44:17       
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k, m, a;
  scanf("%d %d %d %d", &n, &k, &m, &a);
  vector<int> votes(n, 0);
  vector<int> last(n, -1);
  for (int i = 0; i < a; i++) {
    int foo;
    scanf("%d", &foo);
    foo--;
    votes[foo]++;
    last[foo] = i;
  }
  vector<bool> chance(n, false);
  vector<bool> sure(n, false);
  for (int i = 0; i < n; i++) {
    if (votes[i] == 0 && m == a) {
      continue;
    }
    vector< pair < pair <int, int>, int > > z(n);
    for (int j = 0; j < n; j++) {
      z[j] = make_pair(make_pair(votes[j], last[j]), j);
      if (j == i && m > a) {
        z[j].first.first += m - a;
        z[j].first.second = m - 1;
      }
      z[j].first.first = -z[j].first.first;
    }
    sort(z.begin(), z.end());
    for (int j = 0; j < k; j++) {
      chance[i] = (chance[i] | (z[j].second == i));
    }
  }
  for (int i = 0; i < n; i++) {
    if (votes[i] == 0) {
      continue;
    }
    vector<int> need;
    for (int j = 0; j < n; j++) {
      if (i == j) {
        continue;
      }
      int cur = m + 1;
      if (votes[j] > votes[i] || (votes[j] == votes[i] && last[j] < last[i])) {
        cur = 0;
      } else {
        cur = (votes[i] + 1) - votes[j];
      }
      need.push_back(cur);
    }
    need.push_back(m + 1);
    sort(need.begin(), need.end());
    int sum = 0;
    for (int j = 0; j < k; j++) {
      sum += need[j];
    }
    if (sum > m - a) {
      sure[i] = true;
    }
  }
  for (int i = 0; i < n; i++) {
    if (i > 0) putchar(' ');
    printf("%d", sure[i] ? 1 : (chance[i] ? 2 : 3));
  }
  printf("\n");
  return 0;
}