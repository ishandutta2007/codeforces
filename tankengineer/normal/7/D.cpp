//CF 7D
#include<cstdio>
#include<cstring>

int ans, f, r, e, q[5000005];
char s[5000005];

int main() {
  gets(s);
  e = 1;
  for (int i = 0; s[i]; i++) {
    f = f * 5317 + s[i];
    r = r + s[i] * e; e = e * 5317;
    if (f == r) {
      q[i + 1] = q[(i + 1) / 2] + 1;
      ans += q[i + 1]; 
    }
  }
  printf("%d\n", ans);
  return 0;
}