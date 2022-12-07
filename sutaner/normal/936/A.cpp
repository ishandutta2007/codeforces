#include <cstdlib>
#include <cstdio>
#include <algorithm>
#define maxn 1
#define ll long long int
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxn, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;


char *p1, *p2;
char buffer[maxn];
template <class T> void read(T& x){
    char ch = gc(); x = 0; bool f = 1;
    while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
    if (ch == '-') f  =0, ch = gc();
    while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
    if (!f) x = -x;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("A.in", "r", stdin);
    #endif

    ll k, d, t;
    scanf("%I64d%I64d%I64d", &k, &d, &t);
    ll x = (k - 1) / d + 1;
    ll res = k + x * d;
    t *= 2;
    ll term = t / res;
    ll rest = t - res * term;
    double ans = term * x * d;
    if (rest > 2 * k) ans += k + (rest - 2 * k); 
    else ans += rest / 2.0; 
    printf("%.9lf", ans);
    return 0;
}