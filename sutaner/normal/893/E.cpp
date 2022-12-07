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
#define maxn 1000105
#define maxm 
#define M 1000000007
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

int n, m;

int p[maxn];
bool vis[maxn];
int nex[maxn];
int cnt = 0;

void init(){
    rep(i, 2, maxn - 1){
        if (!vis[i]) p[++cnt] = i, nex[i] = cnt;
        rep(j, 1, cnt){
            if (i * p[j] >= maxn) break;
            vis[i * p[j]] = 1;
            nex[i * p[j]] = j;
            if (i % p[j] == 0) break;
        }
    }
}

LL fac[maxn];
LL ifac[maxn];
LL inv[maxn];
LL two[maxn];

void get_com(){
    fac[0] = ifac[0] = inv[1] = two[0] = 1;
    rep(i, 1, maxn - 1) two[i] = (two[i - 1] << 1) % M;
    rep(i, 1, maxn - 1) fac[i] = fac[i - 1] * i % M;
    rep(i, 2, maxn - 1) inv[i] = M - M / i * inv[M % i] % M;
    rep(i, 1, maxn - 1) ifac[i] = ifac[i - 1] * inv[i] % M;
}

LL cal(int m, int n){
    if (m < n) return 0;
    return fac[m] * ifac[n] % M * ifac[m - n] % M;
}

void work(int x, int y){
    LL ans = two[y - 1];
    while (x > 1){
        int d = nex[x];
        int ct = 0;
        while (nex[x] == d) ct++, x /= p[nex[x]];
        ans = ans * cal(ct + y - 1, y - 1) % M;
    }
    printf("%I64d\n", ans);
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("ca.in", "r", stdin);
    #endif
    init(), get_com();
    int x, y;
    read(m);
    rep(i, 1, m){
        read(x), read(y);
        work(x, y);
    }
    return 0;
}