#include <set>
#include <map>
#include <queue>
#include <stack>
#include <ctime>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define maxn 200005
#define maxm 
#define M 
#define INF 2000000005
#define bit 
#define LL long long int
#define lowbit(x) x & -x
#define pll pair<LL, LL>
#define pii pair<int, int>
#define rep(i, l, r) for (register int i = l; i <= r; i++) 
#define per(i, r, l) for (register int i = r; i >= l; i--) 
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
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

int n, d;
int a[maxn];
int low[maxn];
int up[maxn];

int c[maxn];
void add(int p, int v){
    while (p) {
        c[p] = min(c[p], v);
        p -= lowbit(p);
    }
}
int get(int p){
    if (!p) return 0;
    int ans = INF;
    while (p <= n){
        ans = min(ans, c[p]);
        p += lowbit(p);
    }
    return ans;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("card.in", "r", stdin);
    #endif
    int x, now = 0;

    read(n), read(d);
    rep(i, 1, n) {
        if (now > d) {
            printf("-1");
            return 0;
        }
        read(a[i]);
        if (a[i] == 0) { if (now < 0) now = 0; }
        else now += a[i];
    }
    if (now > d) {
        printf("-1");
        return 0;
    }

    now = 0;
    rep(i, 1, n) {
        now += a[i];
        up[i] = d - now;
        if (a[i] == 0) low[i] = -now;
        else low[i] = -INF;
    }
    rep(i, 1, n) c[i] = INF;
    rep(i, 1, n) add(i, up[i]);
    int ans = 0;
    rep(i, 0, n){
        int next = get(i);
        while (i <= n && low[i] <= next) i++; 
        if (next) ans++;
        if (i == n + 1) break;
        i--;
    }
    printf("%d", ans);
    return 0;
}