//13E
#include<cstdio>
#include<cmath>

int n, m, ratio, group[100005], power[100005], sign, x, t1, t2, t3, zipped_count[100005], zipped_jump[100005], zipped_space[100005];

void renew(const int head, const int tail) {
  for (int i = head; i >= tail; i--) {
    zipped_count[i] = 1;
    zipped_jump[i] = i + power[i];
    if (zipped_jump[i] > n) {
      zipped_jump[i] = n + 1;
      zipped_space[i] = i;
    } else {
      zipped_space[i] = zipped_space[zipped_jump[i]];
    }
    if (group[zipped_jump[i]] == group[i] && zipped_jump[i] <= n) {
      zipped_count[i] += zipped_count[zipped_jump[i]];
      zipped_space[i] = zipped_space[zipped_jump[i]];
      zipped_jump[i] = zipped_jump[zipped_jump[i]];
    }
  }
}

int main() {
  scanf("%d %d", &n, &m);
  ratio = (int)sqrt(n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &power[i]);
    group[i] = i / ratio;
  }
  renew(n, 1);
  for (; m--;) {
    scanf("%d", &sign);
    if (sign) {
      scanf("%d", &x);
      t1 = x; t2 = 0; t3 = x;
      while (t1 <= n) {
        t2 = t2 + zipped_count[t1];
        t3 = t1;
        t1 = zipped_jump[t1];
      }
      printf("%d %d\n", zipped_space[t3], t2);
    } else {
      scanf("%d %d", &x, &t1);
      power[x] = t1;
      renew(x, x - x % ratio);
    }
  }
  return 0;
}