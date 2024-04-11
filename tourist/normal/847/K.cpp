/**
 *    author:  tourist
 *    created: 18.09.2017 17:12:53       
**/
#include <bits/stdc++.h>

using namespace std;

int from[1234567];
int to[1234567];

int main() {
  int n, a, b, k, f;
  scanf("%d %d %d %d %d", &n, &a, &b, &k, &f);
  map <string, int> names;
  for (int i = 0; i < n; i++) {
    string sfrom, sto;
    cin >> sfrom >> sto;
    if (names.find(sfrom) == names.end()) {
      int id = names.size();
      names[sfrom] = id;
    }
    if (names.find(sto) == names.end()) {
      int id = names.size();
      names[sto] = id;
    }
    from[i] = names[sfrom];
    to[i] = names[sto];
  }
  map < pair <int, int>, int > total;
  for (int i = 0; i < n; i++) {
    int cost;
    if (i == 0 || from[i] != to[i - 1]) {
      cost = a;
    } else {
      cost = b;
    }
    total[make_pair(min(from[i], to[i]), max(from[i], to[i]))] += cost;
  }
  vector<int> all;
  for (auto &p : total) {
    all.push_back(p.second);
  }
  sort(all.rbegin(), all.rend());
  int ans = 0;
  for (int i = 0; i < (int) all.size(); i++) {
    if (i < k) {
      ans += min(all[i], f);
    } else {
      ans += all[i];
    }
  }
  printf("%d\n", ans);
  return 0;
}