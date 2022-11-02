#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, ll> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

int n;
int a[200009];
pii memo[200009][2];
int seen[200009][2];
const int ok = 0, imp = 1, a1 = 2;
pii solve(int i, bool on2) {
    if(i < 0 || i >= n) return pii(ok, 0);
    if(i == 0 && on2) return pii(imp, 0);
    if(i == 0) return pii(a1, 0);
    pii &r = memo[i][on2];
    if(seen[i][on2] == 2) return r;
    if(seen[i][on2] == 1) return r = pii(imp, 0);
    seen[i][on2] = 1;
    pii x = solve(i + a[i] * (on2 * 2 - 1), !on2);
    r = x;
    if(r.fst != imp)
        r.snd += a[i];
    seen[i][on2] = 2;
    return r;
}

int main() {
    int i;
    scanf("%d", &n);
    for(i = 1; i < n; i++)
        scanf("%d", &a[i]);
    for(i = 0; i < n - 1; i++) {
        pii y = solve(i + 1, false);
        y.snd += i + 1;
        if(y.fst == a1) y.snd += i + 1;
        if(y.fst == imp) puts("-1");
        else printf("%I64d\n", y.snd);
    }

}