// Author: wlzhouzhuan
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fir first
#define sec second
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
#define mset(s, t) memset(s, t, sizeof(s))
#define mcpy(s, t) memcpy(s, t, sizeof(t))
#define poly vector<int>
#define SZ(x) (int(x.size()))
template<typename T1, typename T2> void ckmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> void ckmax(T1 &a, T2 b) { if (a < b) a = b; }
int read() {
  int x = 0, f = 0; char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
template<typename T> void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template<typename T> void print(T x, char let) {
  print(x), putchar(let);
}

const int N = 100005;
char a[N];
int cnt[26], n;

void solve() {
  scanf("%s", a + 1), n = strlen(a + 1);
  memset(cnt, 0, sizeof(cnt));
  for (int i = 1; i <= n; i++) a[i] -= 'a';
  for (int i = 1; i <= n; i++) cnt[a[i]]++;
  vector<int> qwq; int _ = -1;
  for (int i = 0; i < 26; i++) if (cnt[i]) {
    qwq.pb(i);
    if (_ == -1 && cnt[i] == 1) _ = i;
  }
  if (SZ(qwq) == 1) { //  = 1 
    for (int i = 1; i <= n; i++) printf("%c", a[i] + 'a');
    puts("");
    return ;
  }
  if (_ != -1) { //  = 1, f = 0 
    printf("%c", _ + 'a');
    for (auto v: qwq) {
      if (v == _) continue;
      while (cnt[v]--) printf("%c", v + 'a');
    } 
    puts("");
    return ;
  }
  //  >= 2, f = 1
  
  //  qwq[0]
  int oth = 0;
  for (auto v: qwq) if (v != qwq[0]) oth += cnt[v];
  if (cnt[qwq[0]] - 2 <= oth) {
    printf("%c%c", qwq[0] + 'a', qwq[0] + 'a');
    cnt[qwq[0]] -= 2;
    for (int i = 1; i < SZ(qwq); i++) {
      int v = qwq[i];
      while (cnt[v]--) {
        printf("%c", v + 'a');
        if (cnt[qwq[0]] > 0) cnt[qwq[0]]--, printf("%c", qwq[0] + 'a');
      }
    }
    puts("");
  } else {
    printf("%c", qwq[0] + 'a');
    cnt[qwq[0]]--;
    printf("%c", qwq[1] + 'a');
    cnt[qwq[1]]--;
    if (SZ(qwq) == 2) {
      while (cnt[qwq[1]]--) printf("%c", qwq[1] + 'a');
      while (cnt[qwq[0]]--) printf("%c", qwq[0] + 'a');
    } else {
      while (cnt[qwq[0]]--) printf("%c", qwq[0] + 'a');
      printf("%c", qwq[2] + 'a'), cnt[qwq[2]]--;
      for (auto v: qwq) {
        while (cnt[v]-- >= 1) printf("%c", v + 'a');
      }
    }
    puts("");
  }
}

int main() {
  int T = read();
  while (T--) solve();
  return 0;
}