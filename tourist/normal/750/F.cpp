#include <bits/stdc++.h>

using namespace std;

const int N = 123456;

bool known[N];
vector <int> nei[N];
bool found;
int CNT;

void test(int v) {
  if (found) {
    return;
  }
  CNT++;
  if (CNT > 16) {
    printf("! %d\n", v);
    fflush(stdout);
    found = true;
    return;
  }
  printf("? %d\n", v);
  fflush(stdout);
  known[v] = true;
  int sz;
  scanf("%d", &sz);
  nei[v].resize(sz);
  for (int j = 0; j < sz; j++) {
    scanf("%d", &nei[v][j]);
  }
  if (sz == 2) {
    printf("! %d\n", v);
    fflush(stdout);
    found = true;
  }
}

int get_nei(int id, bool must_be = true) {
  int nxt = -1;
  for (int j = 0; j < (int) nei[id].size(); j++) {
    if (!known[nei[id][j]]) {
      nxt = nei[id][j];
      break;
    }
  }
  if (must_be) {
    assert(nxt != -1);
  }
  return nxt;
}

void build(vector <int> &path, int id) {
  while (true && !found) {
    test(id);
    path.push_back(id);
    if (nei[id].size() <= 2) {
      break;
    }
    id = get_nei(id);
  }
}

int main() {
  srand(8753);
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    CNT = 0;
    int h;
    scanf("%d", &h);
    for (int i = 1; i < (1 << h); i++) {
      nei[i].clear();
      known[i] = false;
    }
    found = false;
    int start = rand() % ((1 << h) - 1) + 1;
    test(start);
    if (found) {
      continue;
    }
    vector <int> path;
    path.push_back(start);
    if (nei[start].size() == 1) {
      build(path, nei[start][0]);
    } else {
      build(path, nei[start][0]);
      reverse(path.begin(), path.end());
      build(path, nei[start][1]);
    }
    if (found) {
      continue;
    }
    assert(path.size() % 2 == 1);
    while (!found) {
      int root = path[path.size() / 2];
      int half = path.size() / 2;
      while ((int) path.size() > half + 1) {
        path.pop_back();
      }
      int at = h - half;
      root = get_nei(root);
      at--;
      test(root);
      if (found) {
        break;
      }
      if (at >= 4) {
        path.push_back(root);
        int cur = root;
        while (true) {
          cur = get_nei(cur);
          test(cur);
          path.push_back(cur);
          if (found) {
            break;
          }
          if (nei[cur].size() == 1) {
            break;
          }
        }
        if (found) {
          break;
        }
        continue;
      }
      if (at == 2) {
        int cur = get_nei(root);
        test(cur);
        if (found) {
          break;
        }
        cur = get_nei(root);
        test(cur);
        break;
      }
      assert(at == 3);
      for (int rx = 0; rx < 2; rx++) {
        int cur = get_nei(root, false);
        if (cur == -1) {
          break;
        }
        test(cur);
        for (int ry = 0; ry < 2; ry++) {
          int new_cur = get_nei(cur, false);
          if (new_cur == -1) {
            break;
          }
          test(new_cur);
        }
      }
    }
    assert(found);
  }
  return 0;
}