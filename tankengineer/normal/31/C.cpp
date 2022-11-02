#include<cstdio>
#include<algorithm>
using namespace std;

int n, l[5005], r[5005], t1, t2;
bool flag;

bool intersect(const int i, const int j) {
  if (l[i] >= l[j] && l[i] < r[j] || r[i] > l[j] && r[i] <= r[j]) return true; else return false;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d %d", &l[i], &r[i]);
  flag = false;
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      if (intersect(i, j) || intersect(j, i)) {
        if (!flag) {
          flag = true;
          t1 = i;
          t2 = j;
        }
        if (t1 != i && t1 != j) t1 = -1;
        if (t2 != i && t2 != j) t2 = -1;
        if (t1 == -1 && t2 == -1) {
          printf("0\n");
          return 0;
        }
      }
    }
  }
  if (!flag) {
    printf("%d\n", n);
    for (int i = 1; i < n; ++i) printf("%d ", i);
    printf("%d\n", n);
  } else {
    if (t1 != -1 && t2 != -1) {
      printf("%d\n%d %d\n", 2, t1, t2);
    } else {
      if (t1 == -1) t1 = t2;
      printf("%d\n%d\n", 1, t1);
    }
  }
  return 0;
}