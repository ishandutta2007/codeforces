//CF 1B
#include<stdio.h>
#include<cstring>

int n, t1, t2, t3, t4, t5, pow[10];
char s[500], s2[500], ch;

int main() {
  pow[0] = 1;
  for (int i = 1; i <= 5; i++) pow[i] = pow[i - 1] * 26;
    
  scanf("%d", &n);
  for (; n; n--) {
    scanf("%s", &s);
    t1 = strlen(s);
    t2 = -1;
    for (int i = 1; i <= t1; i++) {
      if (s[i - 1] == 'C') t2 = i - 1;
    }
    if (s[0] == 'R' && s[1] >= '0' && s[1] <= '9' && t2 != -1) {
      t3 = 0;
      for (int i = t2 + 1; i < t1; i++) {
        t3 = t3 * 10 + s[i] - '0';
      }
      t4 = 0;
      t5 = t3;
      while (t5 > 0) {
        t4++;
        t5 -= pow[t4];
      }
      t5 += pow[t4]; t5--;
      for (int i = 0; i < t4; i++) {
        s2[i] = t5 % 26 + 'A';
        t5 /= 26;
      }
      t3 = 0;
      for (int i = 1; i < t2; i++) {
        t3 = t3 * 10 + s[i] - '0';
      }
      for (int i = t4 - 1; i >= 0; i--) {
        printf("%c", s2[i]);
      }
      printf("%d\n", t3);
    } else {
      t3 = 0;
      t2 = 0;
      while (s[t2] >= 'A' && s[t2] <= 'Z') t2++;
      
      for (int i = 0; i < t2; i++) {
        t3 = t3 * 26 + s[i] - 'A';
      }
      for (int i = 0; i < t2; i++) {
        t3 += pow[i];
      }
      t4 = 0;
      for (int i = t2; i < t1; i++) {
        t4 = t4 * 10 + s[i] - '0';
      }
      printf("R%dC%d\n", t4, t3);
    }
  }
  return 0;
}