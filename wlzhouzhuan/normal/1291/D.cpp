// Author: wlzhouzhuan
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define rint register int
#define rep(i, l, r) for (rint i = l; i <= r; i++)
#define per(i, l, r) for (rint i = l; i >= r; i--)
#define mset(s, _) memset(s, _, sizeof(s))
#define pb push_back
#define pii pair <int, int>
#define mp(a, b) make_pair(a, b)

inline int read() {
  int x = 0, neg = 1; char op = getchar();
  while (!isdigit(op)) { if (op == '-') neg = -1; op = getchar(); }
  while (isdigit(op)) { x = 10 * x + op - '0'; op = getchar(); }
  return neg * x;
}
inline void print(int x) {
  if (x < 0) { putchar('-'); x = -x; }
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}

void ckmax(int &a, int b) {
  if (a < b) a = b;
}
void ckmin(int &a, int b) {
  if (a > b) a = b;
}

const int N = 200005;
char s[N];
int cnt[N][26], n, q;
int buc[26];

int main() {
  scanf("%s", s + 1); n = strlen(s + 1);
  for (rint i = 1; i <= n; i++) {
    s[i] -= 'a';
    for (rint j = 0; j < 26; j++) {
      cnt[i][j] = cnt[i - 1][j] + (s[i] == j);
    }
  }  
  q = read();
  while (q--) {
    int l = read(), r = read();
    if (l > r) swap(l, r);
    for (rint i = 0; i < 26; i++) {
      buc[i] = cnt[r][i] - cnt[l - 1][i];
    }
    if (l == r) {
      puts("Yes"); continue;
    }
    int have = 0;
    for (rint i = 0; i < 26; i++) if (buc[i]) have++;
    //printf("have = %d\n", have);
    if (have > 2) {
      puts("Yes"); continue;
    }
    if (have == 1) {
      puts("NO"); continue;
    }
    char left = s[l], right = s[r];
    if (left == right) {
      puts("No");
    } else {
      puts("Yes");
    }
  }
  return 0; 
}