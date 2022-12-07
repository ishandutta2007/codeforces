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
#define INF 
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

int n, x, k;
int a[maxn];

int now;
int judge(int t){
    if (a[t] > now) return 0;
    int ans = now / x - (a[t] - 1) / x;
    if (ans > k) return 1;
    else if (ans < k) return 0;
    else return -1;
}

int work_left(int l, int r){
    if (l == r) return l;
    int mid = ((r - l) >> 1) + l;
    int d = judge(mid);
    if (d == 0 || d == -1) return work_left(l, mid);
    else return work_left(mid + 1, r); 
}

int rec;

int work_right(int l, int r){
    if (l == r) {
        if (judge(l) != -1) return rec;
        return l;
    }
    int mid = ((r - l) >> 1) + l;
    int d = judge(mid);
    if (d == 1 || d == -1) {
        if (d == -1) rec = mid;
        return work_right(mid + 1, r); 
    }
    else return work_right(l, mid);
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("xk.in", "r", stdin);
    #endif
    read(n), read(x), read(k);
    rep(i, 1, n) read(a[i]); 
    sort(a + 1, a + 1 + n);
    LL ans = 0;
    rep(i, 1, n) {
        now = a[i];
        int l = work_left(1, n);
        int r = work_right(1, n);
        if (judge(l) == -1) ans += r - l + 1;
    }
    printf("%I64d", ans);
    return 0;
}