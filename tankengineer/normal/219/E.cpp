#include<cstdio>
#include<algorithm>
using namespace std;

const int N = 200005, TN = 500005;

int l[TN], r[TN], lc[TN], rc[TN], ls[TN], rs[TN], mins[TN], minss[TN], rss[TN], top, n, m, ti, id, pos[1000005], sum;

int getlen(const int start, const int length) {
  if (start == 1 || start + length - 1 == n) return length - 1;
  return (length == 0 ? -2 : length - 1) / 2;
}

void update(const int i) {
  ls[i] = (ls[lc[i]] == (r[lc[i]] - l[lc[i]] + 1) ? ls[lc[i]] + ls[rc[i]] : ls[lc[i]]);
  rs[i] = (rs[rc[i]] == (r[rc[i]] - l[rc[i]] + 1) ? rs[rc[i]] + rs[lc[i]] : rs[rc[i]]);
  rss[i] = (rss[rc[i]] == l[rc[i]] ? rss[lc[i]] : rss[rc[i]]);
  if (getlen(minss[lc[i]], mins[lc[i]]) >= getlen(minss[rc[i]], mins[rc[i]])) {
    mins[i] = mins[lc[i]];
    minss[i] = minss[lc[i]];
  } else {
    mins[i] = mins[rc[i]];
    minss[i] = minss[rc[i]];
  }
  if (getlen(rss[lc[i]], rs[lc[i]] + ls[rc[i]]) > getlen(minss[i], mins[i]) || 
      getlen(rss[lc[i]], rs[lc[i]] + ls[rc[i]]) == getlen(minss[i], mins[i]) && rss[lc[i]] < minss[i]) {
    mins[i] = rs[lc[i]] + ls[rc[i]];
    minss[i] = rss[lc[i]];
  }
}

void buildtree(const int i, const int left, const int right) {
  l[i] = left; r[i] = right;
  if (l[i] == r[i]) {
    ls[i] = rs[i] = mins[i] = 1;
    minss[i] = rss[i] = l[i];
    return ;
  };
  int k = (l[i] + r[i]) >> 1;
  ++top; lc[i] = top;
  buildtree(lc[i], left, k);
  ++top; rc[i] = top;
  buildtree(rc[i], k + 1, right);
  
  update(i);
}

void insert(const int i, const int pos) {
  if (l[i] == pos && r[i] == pos) {
    ls[i] = rs[i] = mins[i] = 0;
    minss[i] = rss[i] = l[i] + 1;
    return;
  }
  int k = (l[i] + r[i]) >> 1;
  if (pos > k) insert(rc[i], pos); else insert(lc[i], pos);
  update(i);
}

void deleta(const int i, const int pos) {
  if (l[i] == pos && r[i] == pos) {
    ls[i] = rs[i] = mins[i] = 1;
    minss[i] = rss[i] = l[i];
    return;
  }
  int k = (l[i] + r[i]) >> 1;
  if (pos > k) deleta(rc[i], pos); else deleta(lc[i], pos);
  update(i);
}

void showtree(const int i) {
  printf("Node %d (%d, %d) ls %d rs %d mins %d minss %d rss %d\n", i, l[i], r[i], ls[i], rs[i], mins[i], minss[i], rss[i]);
  if (lc[i] != 0) showtree(lc[i]);
  if (rc[i] != 0) showtree(rc[i]);
}

int main() {
  scanf("%d %d", &n, &m);
  top = 1;
  buildtree(1, 1, n);
  for (int i = 1; i <= m; ++i) {
    scanf("%d %d", &ti, &id);
    if (ti == 1) {
      if (minss[1] == 1) {
        pos[id] = 1;
      } else if (minss[1] + mins[1] - 1 == n) {
        pos[id] = n;
      } else {
        pos[id] = minss[1] + (mins[1] - 1) / 2;
      }
      printf("%d\n", pos[id]);
      insert(1, pos[id]);
    } else {
      deleta(1, pos[id]);
    }
    //showtree(1);
  }
  return 0;
}