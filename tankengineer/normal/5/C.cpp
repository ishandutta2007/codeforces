//CF 5C
#include<cstdio>
#include<cstring>

int ans, cnt, st[1000005], top;
char s[1000005];

int main() {
  ans = 0; cnt = 1;
  st[0] = -1;
  gets(s);
  for (int i = 0; s[i]; i++) {
    if (top && s[st[top]] == '(' && s[i] == ')') {
      if (ans < (i - st[top - 1])){
        ans = i - st[top - 1];
        cnt = 1;
      } else if (ans == (i - st[top - 1])) {
        cnt++;
      }
      top--;
    } else {
      st[++top] = i;
    }
  }
  
  printf("%d %d\n", ans, cnt);
    
  return 0;
}