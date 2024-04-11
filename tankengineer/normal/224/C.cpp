#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int l, top, st[100005], sum[100005], ans, anst, t1, f[100005], match[100005], pre[100005];
char s[100005];

int main() {
  gets(s);
  l = strlen(s);
  top = 0;
  for (int i = 0; i < l; ++i) {
    if (s[i] == '(' || s[i] == '[') {
      st[++top] = i;
    } else {
      if (top > 0 && (s[st[top]] == '(' && s[i] == ')' || s[st[top]] == '[' && s[i] == ']')) {
        match[i] = st[top];
        match[st[top]] = i;
        --top;
      } else {
        while (top > 0) {
          match[st[top]] = -1;
          --top;
        }
        match[i] = -1;
      }
    }
  }
  //for (int i = 0; i < l; ++i) printf("%d : %d\n", i, match[i]);
  sum[0] = 0;
  for (int i = 0; i < l; ++i) {
    sum[i + 1] = sum[i];
    if (s[i] == '[') sum[i + 1]++;
  }
  f[l] = 0;
  for (int i = l - 1; i >= 0; --i) {
    f[i] = 0;
    pre[i] = 0;
    if (match[i] != -1 && match[i] > i) {
      f[i] = f[match[i] + 1] + sum[match[i] + 1] - sum[i];
      pre[i] = match[i] + 1;
    }
  }
  ans = 0; anst = 0;
  for (int i = 0; i < l; ++i) {
    if (f[i] > ans) {
      ans = f[i];
      anst = i;
    }
  }
  printf("%d\n", ans);
  if (ans) {
    t1 = pre[anst];
    while (pre[t1]) t1 = pre[t1];
    for (int i = anst; i < t1; ++i) putchar(s[i]);
    printf("\n");
  }
  return 0;
}