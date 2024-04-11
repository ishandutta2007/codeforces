//17A
#include<cstdio>

int n, k, top, p[1005], t1, t2;
bool flag;

int main() {
  scanf("%d %d", &n, &k);
  top = 0;
  for (int i = 2; i <= n; i++) {
    flag = true;
    for (int j = 1; j <= top; j++) {
      if (i % p[j] == 0) {
        flag = false;
        break;
      }
    }
    if (flag) {
      p[++top] = i;
    }
  }
  
  for (int i = 1; i <= top; i++) {
    t1 = p[i] - 1;
    for (int j = 1; j < i; j++) {
      if (t1 == p[j] + p[j + 1]) {
        t2++;
      }
    }
  }
  
  if (t2 >= k) {
    puts("YES");
  } else {
    puts("NO");
  }
    
  return 0;
}