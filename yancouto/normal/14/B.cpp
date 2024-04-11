#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

int main() {
    int n, x0, i, a, b;
    scanf("%d %d", &n, &x0);
    int mn = 0, mx = 1000;
    for(i = 0; i < n; i++) {
        scanf("%d %d", &a, &b);
        if(a > b) swap(a, b);
        if(a > mn) mn = a;
        if(b < mx) mx = b;
    }
    if(mx < mn) puts("-1");
    else {
        if(x0 >= mn && x0 <= mx) puts("0");
        else if(x0 < mn) printf("%d\n", mn - x0);
        else printf("%d\n", x0 - mx);
    }
}