#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

vector <int> all[N];

inline bool cmp(int x, int y) {
  return all[x] < all[y];
}

int from[N], to[N];
vector <int> nei[N];
vector <bool> used[N];
vector <int> g[N];
int rid[N];

int mask[N];
int ans[N];

void dfs(int u, int p) {
  for (int i = 0; i < (int) g[u].size(); i++) {
    int v = g[u][i];
    if (v != p) {
      dfs(v, u);
    }
  }
  int d = (1 << 20);
  int w = 20;
  while (d > 0) {
    int c = 0;
    for (int i = 0; i < (int) g[u].size(); i++) {
      int v = g[u][i];
      if (v != p && (mask[v] & d)) {
        c++;
      }
    }
    if (c > 1) {
      for (int j = w + 1; ; j++) {
        mask[u] ^= (1 << j);
        if (mask[u] & (1 << j)) {
          ans[u] = j;
          break;
        }
      }
      break;
    }
    if (c == 1) {
      mask[u] |= d;
    }
    d >>= 1;
    w--;
  }
  if (d == 0) {
    ans[u] = 0;
    for (int j = 0; ; j++) {
      mask[u] ^= (1 << j);
      if (mask[u] & (1 << j)) {
        break;
      }
      ans[u]++;
    }
  }
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d %d", from + i, to + i);
    from[i]--; to[i]--;
    nei[from[i]].push_back(to[i]);
    nei[to[i]].push_back(from[i]);
  }
  for (int i = 0; i < n; i++) {
    nei[i].push_back((i + 1) % n);
    nei[(i + 1) % n].push_back(i);
  }
  for (int i = 0; i < n; i++) {
    sort(nei[i].begin(), nei[i].end());
    used[i].resize(nei[i].size());
  }
  map < pair <int, int>, int > mp;
  int cnt = -1; 
  for (int start = 0; start < n; start++) {
    for (int id = 0; id < (int) nei[start].size(); id++) {
      if (used[start][id]) {
        continue;
      }
      vector <int> region;
      int p = start;
      int go = id;
      while (!used[p][go]) {
        region.push_back(p);
        used[p][go] = true;
        int new_p = nei[p][go];
        int new_go = lower_bound(nei[new_p].begin(), nei[new_p].end(), p) - nei[new_p].begin();
        new_go = (new_go + 1) % nei[new_p].size();
        p = new_p;
        go = new_go;
      }
      if (cnt == -1) {
        cnt++;
        continue;
      }
      int sz = region.size();
      for (int j = 0; j < sz; j++) {
        int x = region[j];
        int y = region[(j + 1) % sz];
        if (x > y) {
          swap(x, y);
        }
        pair <int, int> z = make_pair(x, y);
        if (mp.find(z) != mp.end()) {
          int other = mp[z];
          g[cnt].push_back(other);
          g[other].push_back(cnt);
        } else {
          mp[z] = cnt;
        }
      }
      sort(region.rbegin(), region.rend());
      all[cnt++] = region;
    }
  }
  for (int i = 0; i < cnt; i++) {
    rid[i] = i;
  }
  sort(rid, rid + cnt, cmp);
  dfs(0, -1);
  for (int i = 0; i < cnt; i++) {
    if (i > 0) putchar(' ');
    printf("%d", 20 - ans[rid[i]]);
  }
  printf("\n");
  return 0;
}