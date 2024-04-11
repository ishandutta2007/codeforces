/**
 *    author:  tourist
 *    created: 24.09.2017 18:31:07       
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

int TIME = 0, tin[N], tout[N];
int de[N];
vector<int> g[N];
int parent[N], type[N];
int upper_special[N];
int upper_part[N];

void dfs(int v) {
  tin[v] = ++TIME;
  for (int u : g[v]) {
    de[u] = de[v] + 1;
    dfs(u);
  }
  tout[v] = ++TIME;
}

inline bool anc(int x, int y) {
  return (tin[x] <= tin[y] && tout[y] <= tout[x]);
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", parent + i, type + i);
    if (parent[i] != -1) {
      parent[i]--;
    }
  }
  for (int i = 0; i < n; i++) {
    upper_special[i] = i;
    if (type[i] == 0) {
      upper_special[i] = upper_special[parent[i]];
    }
    upper_part[i] = i;
    if (type[i] == 1) {
      upper_part[i] = upper_part[parent[i]];
    }
  }
  for (int i = 0; i < n; i++) {
    g[parent[i]].push_back(i);
  }
  for (int i = 0; i < n; i++) {
    if (parent[i] == -1) {
      de[i] = 0;
      dfs(i);
    }
  }
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int op, x, y;
    scanf("%d %d %d", &op, &x, &y);
    x--; y--;
    if (x == y) {
      puts("NO");
      continue;
    }
    if (op == 1) {
      if (anc(x, y) && de[upper_special[y]] <= de[x]) {
        puts("YES");
      } else {
        puts("NO");
      }
    } else {
      int z = upper_part[y];
      if (y != z && anc(z, x) && de[upper_special[x]] <= de[z]) {
        puts("YES");
      } else {
        z = upper_special[x];
        if (y != z && anc(z, y) && de[upper_part[y]] <= de[z]) {
          puts("YES");
        } else {
          puts("NO");
        }
      }
    }
  }
  return 0;
}