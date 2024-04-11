// Author: wlzhouzhuan
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
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
vector<int> ch[N];
int a[N], l[N], n, m;

int ans[N];

void work() {
    n = read(), m = read();
    for (int i = 1; i <= m; i++) ans[i] = 0;
    for (int i = 1; i <= n; i++) a[i] = 0;
    for (int i = 1; i <= m; i++) {
        l[i] = read();
        ch[i].clear();
        for (int j = 0; j < l[i]; j++) {
            int t = read();
            a[t]++;
            ch[i].pb(t);
        }
    }
    int x = 0;
    for (int i = 1; i <= n; i++) if (a[i] > (m + 1) / 2) x = i;
//    fprintf(stderr, "x = %d\n", x);
    int can = (m + 1) / 2;
    if (!x) {
        puts("YES");
        for (int i = 1; i <= m; i++) {
            printf("%d ", ch[i][0]);
        }
        puts("");
        return ;
    } 
    for (int i = 1; i <= m; i++) {
        int find = 0;
        for (auto v: ch[i]) {
            if (v == x) find = 1;
        }
        if (!find) {
            ans[i] = ch[i][0]; 
        } else {
            for (auto v: ch[i]) {
                if (v != x) {
                    ans[i] = v;
                    break;
                }
            }
            if (!ans[i]) ans[i] = x, can--;
        }
    }
    if (can < 0) {
        puts("NO");
        return ;
    }

    for (int i = 1; i <= m && can; i++) {
        if (ans[i] != x) {
            int find = 0;
            for (auto v: ch[i]) {
                if (v == x) find = 1;
            }
            if (find) ans[i] = x, can--;
        }
    }
    puts("YES");
    for (int i = 1; i <= m; i++) {
        printf("%d ", ans[i]);
    }
    puts("");
}
int main() {
    int T = read();
    while (T--) work();
    return 0;
}