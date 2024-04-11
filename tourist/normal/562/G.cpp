#include <bits/stdc++.h>

using namespace std;

const int N = 400010;

int a[N], b[N], c[N];
vector <int> adj[N];
int res[N];
int cnt[N];
bool todo[N];

int main() {
  double beg = clock();
  int n;
  scanf("%d", &n);
  for (int i = 0; i < 4 * n; i++) {
    scanf("%d %d %d", a + i, b + i, c + i);
    a[i]--; b[i]--; c[i]--;
  }
  srand(787788);
  while ((clock() - beg) / CLOCKS_PER_SEC < 1.5) {
    for (int i = 0; i < n; i++) {
      adj[i].clear();
    }
    for (int i = 0; i < 4 * n; i++) {
      adj[a[i]].push_back(i);
      adj[b[i]].push_back(i);
      adj[c[i]].push_back(i);
      todo[i] = true;
    }
    for (int i = 0; i < n; i++) {
      cnt[i] = 4;
    }
    set <int> can;
    for (int i = 0; i < 4 * n; i++) {
      can.insert(i);
    }
    bool err = false;
    for (int iter = 0; iter < 4 * n; iter++) {
      if (can.empty()) {
        err = true;
        break;
      }
      int u = ((rand() << 15) + rand()) % (4 * n);
      set <int>::iterator it = can.lower_bound(u);
      if (it == can.end()) {
        it = can.begin();
      }
      int id = *it;
      can.erase(id);
      res[iter] = id + 1;
      cnt[a[id]]--;
      cnt[b[id]]++;
      cnt[c[id]]++;
      todo[id] = false;
      for (int r = 0; r < 3; r++) {
        int who = (r == 0 ? a[id] : (r == 1 ? b[id] : c[id]));
        for (int z = 0; z < (int)adj[who].size(); z++) {
          int pid = adj[who][z];
          if (!todo[pid]) {
            continue;
          }
          can.erase(pid);
          cnt[a[pid]]--;
          cnt[b[pid]]++;
          cnt[c[pid]]++;
          if (cnt[b[pid]] <= 9 && cnt[c[pid]] <= 9) {
            can.insert(pid);
          }
          cnt[a[pid]]++;
          cnt[b[pid]]--;
          cnt[c[pid]]--;
        }
      }
    }
    if (err) {
      continue;
    }
    puts("YES");
    for (int i = 0; i < 4 * n; i++) {
      if (i > 0) putchar(' ');
      printf("%d", res[i]);
    }
    printf("\n");
    return 0;
  }
  puts("NO");
  return 0;
}