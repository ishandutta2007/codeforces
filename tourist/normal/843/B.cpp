#include <bits/stdc++.h>

using namespace std;

inline pair <int, int> ask(int id) {
  printf("? %d\n", id);
  fflush(stdout);
  pair <int, int> p;
  scanf("%d %d", &p.first, &p.second);
  return p;
}

inline void finish(int value) {
  printf("! %d\n", value);
  fflush(stdout);
  exit(0);
}

inline int RAND(int n) {
  return abs((rand() << 15) + rand()) % n;
}

const int MAGIC = 1000;

int main() {
  int n, start, x;
  scanf("%d %d %d", &n, &start, &x);
  srand(time(0));
  set <int> all;
  all.insert(start);
  while ((int) all.size() < min(n, MAGIC)) {
    all.insert(RAND(n) + 1);
  }
  vector < pair <int, int> > v;
  for (int i : all) {
    pair <int, int> z = ask(i);
    v.emplace_back(z.first, i);
  }
  sort(v.begin(), v.end());
  int ptr = start;
  for (int i = 0; i < (int) v.size(); i++) {
    if (v[i].first < x) {
      ptr = v[i].second;
    }
  }
  while (ptr != -1) {
    pair <int, int> z = ask(ptr);
    if (z.first >= x) {
      finish(z.first);
      return 0;
    }
    ptr = z.second;
  }
  finish(-1);
  return 0;
}