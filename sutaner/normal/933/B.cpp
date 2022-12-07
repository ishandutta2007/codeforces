#include <cstdlib>
#include <cstdio>
#include <algorithm>
#define maxn 100005
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
    if (ch == '-') f = 0, ch = gc();
    while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
    if (!f) x = -x;
}

ll p;
int k;
int a[maxn];
int d = 0;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("B.in", "r", stdin);
    #endif
    read(p), read(k);
    int d = 0;
    while (p){
        if (d & 1) {
            if (p % k == 0) a[d++] = 0, p /= k;
            else a[d++] = k - p % k, p = p / k + 1;
        }
        else {
            a[d++] = p % k;
            p /= k;
        }
    }
    printf("%d\n", d);
    rep(i, 0, d - 1) printf("%d ", a[i]);
    return 0;
}