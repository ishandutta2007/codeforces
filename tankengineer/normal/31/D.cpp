#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;

int w, h, n, top, x1[105], x2[105], y1[105], y2[105], t1[105], t2[105], t3[105], t4[105], t5, area[10005];
queue<int> t;

int main() {
  scanf("%d %d %d", &w, &h, &n);
  top = 1;
  x1[top] = 0; x2[top] = w;
  y1[top] = 0; y2[top] = h;
  for (int i = 1; i <= n; ++i) {
    scanf("%d %d %d %d", &t1[i], &t2[i], &t3[i], &t4[i]);
    t.push(i);
  }
  bool flag = false;
  while (t.size()) {
    flag = false;
    t5 = t.front();
    t.pop();
    for (int j = 1; j <= top; ++j) {
      if (t1[t5] >= x1[j] && t3[t5] >= x1[j] && t1[t5] <= x2[j] && t3[t5] <= x2[j] && t2[t5] >= y1[j] && t4[t5] >= y1[j] && t2[t5] <= y2[j] && t4[t5] <= y2[j]) {
        if (t1[t5] == t3[t5]) {
          if (t2[t5] != y1[j] || t4[t5] != y2[j]) continue;
          ++top;
          x1[top] = t1[t5]; x2[top] = x2[j]; x2[j] = t1[t5];
          y1[top] = y1[j]; y2[top] = y2[j];
        } else {
          if (t1[t5] != x1[j] || t3[t5] != x2[j]) continue;
          ++top;
          y1[top] = t2[t5]; y2[top] = y2[j]; y2[j] = t2[t5];
          x1[top] = x1[j]; x2[top] = x2[j];
        }
        flag = true;
        break;
      }
    }
    if (!flag) {
      t.push(t5);
    }
  }
  for (int i = 1; i <= top; ++i) {
    area[(x2[i] - x1[i]) * (y2[i] - y1[i])]++;
  }
  for (int i = 1; i <= w * h; ++i) {
    while (area[i]--) {
      printf("%d ", i);
    }
  }
  return 0;
}