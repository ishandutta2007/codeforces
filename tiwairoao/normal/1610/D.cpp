#include <bits/stdc++.h>

typedef long long ll;

const int N = 200000;
const int P = int(1E9) + 7;

int norm(int x) {return x >= P ? x - P : x;}
int reduce(int x) {return x < 0 ? x + P : x;}
void add(int &x, int y) {if ((x += y) >= P) x -= P;}
void sub(int &x, int y) {if ((x -= y) < 0) x += P;}
int mpow(int b, int p) {
  int r = 1; for (; p; p >>= 1, b = (ll)b * b % P)
    if (p & 1) r = (ll)r * b % P;
  return r;
}

int c[35], pw2[N + 5], a[N + 5], n;
int main() {
  scanf("%d", &n), pw2[0] = 1;
  for (int i = 1, t, p; i <= n; i++) {
    scanf("%d", &a[i]), t = a[i], p = 0;
    while (!(t & 1)) t >>= 1, p++;
    c[p]++, pw2[i] = norm(pw2[i - 1] << 1);
  }
  
  int ans = 0;
  for (int j = 32, s = 0; j >= 0; j--) {
    if (j == 0) {
      add(ans, reduce(pw2[s + c[j]] - pw2[s]));
    } else {
      if (c[j] > 1) {
        add(ans, reduce(pw2[s + c[j] - 1] - pw2[s]));
      }

      s += c[j];
    }
  }
  printf("%d\n", ans);
}