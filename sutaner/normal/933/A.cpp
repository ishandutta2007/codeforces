#include <cstdlib>
#include <cstdio>
#include <algorithm>
#define maxn 3005
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxn, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

char *p1, *p2;
char buffer[maxn];
template <class T> void read(T& x){
    char ch = gc(); x = 0; bool f = 1;
    while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
    if (ch == '-') f = 0, ch = gc();
    while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
    if (!f) x = -x;
}

int n;
int a[maxn];
int pre[maxn];
int suf[maxn];
int dp[maxn][maxn][2];

int main(){
    #ifndef ONLINE_JUDGE
        freopen("A.in", "r", stdin);
    #endif
    read(n);
    rep(i, 1, n) read(a[i]);
    rep(l, 1, n){
        rep(r, l, n) {
            dp[l][r][1] = dp[l][r - 1][1] + (a[r] == 2);
            dp[l][r][0] = max(dp[l][r - 1][0], dp[l][r - 1][1]) + (a[r] == 1);
        }
    }
    rep(i, 1, n) pre[i] = pre[i - 1] + (a[i] == 1);
    per(i, n, 1) suf[i] = suf[i + 1] + (a[i] == 2);

    int ans = 0;
    rep(l, 1, n){
        rep(r, l, n){
            ans = max(ans, pre[l - 1] + suf[r + 1] + max(dp[l][r][0], dp[l][r][1]));
        }
    }
    printf("%d", ans);
    return 0;
}