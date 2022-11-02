//171F
#include<cstdio>

int n, top, p[500000], t1, t2;
bool flag, use[5000000];

int main() {
  scanf("%d", &n);
  for (int i = 2; i <= 5000000; i++) {
    flag = false;
    for (int j = 1; j <= top && p[j] * p[j] <= i; j++) {
      if (i % p[j] == 0) {
        flag = true;
        break;
      }
    }
    if (!flag) {
      use[i] = true;
      p[++top] = i;
    }
  }
  for (int i = 1; i <= top; i++) {
    t1 = p[i]; t2 = 0;
    while (t1) {
      t2 = t2 * 10 + t1 % 10;
      t1 = t1 / 10;
    }
    if (use[t2] && t2 != p[i]) {
      n--;
      if (n == 0) {
        printf("%d\n", p[i]);
        return 0;
      }
    }    
  }
  printf("%d\n", p[top]);
  return 0;
}