//22A
#include<cstdio>

int n, t1, mini, mini2;

int main() {
  scanf("%d", &n);
  mini = mini2 = 32767;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &t1);
    if (t1 < mini) {
      mini2 = mini;
      mini = t1;
    } else if (t1 > mini && t1 < mini2) {
      mini2 = t1;
    }
  }
  if (mini2 != 32767) {
    printf("%d\n", mini2);
  } else {
    printf("NO");
  }
  return 0;
}