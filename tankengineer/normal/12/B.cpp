//CF 12B
#include<cstdio>
#include<cstring>

int t1, cnt[10];
char ch, s1[11], s2[11];

int main() {
  gets(s1);
  gets(s2);
  for (int i = 1; i < strlen(s1); i++) {
    if (s1[i] != '0' && s1[i] < s1[0]) {
      ch = s1[i]; s1[i] = s1[0]; s1[0] = ch;
    }
    cnt[s1[i] - '0']++;
  }
  t1 = 1;
  for (int i = 0 ; i <= 9 ; i++) {
    while (cnt[i]--) {
      s1[t1++] = i + '0';
    }
  }
  if (!strcmp(s1, s2)) {
    puts("OK");
  } else {
    puts("WRONG_ANSWER");
  }
  return 0;
}