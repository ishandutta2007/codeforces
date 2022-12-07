#include <cstdlib>
#include <cstdio>
#include <algorithm>
#define maxn 1005
#define INF 2000000005
#define rep(i, l, r) for (register int i = l; i <= r; i++) 
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxn, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

char *p1, *p2;
char buffer[maxn];
template <class T> void read(T& x){
    char ch = gc(); x = 0;
    while (!('0' <= ch && ch <= '9')) ch = gc();
    while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
}

int a[maxn];
int n;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("pizza.in", "r", stdin); 
    #endif
    read(n);
    rep(i, 1, n) read(a[i]);
    rep(i, 1, n) a[i] += a[i - 1];
    int ans = INF;
    rep(i, 1, n) rep(j, 1, n){
        ans = min(ans, abs((a[j] - a[i]) - (a[n] - (a[j] - a[i]))));
    }
    printf("%d", ans);
    return 0;
}