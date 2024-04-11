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
const int M = 5003;
int a[M], b[M];
int opo[M], lo[M], ro[M], c[M], xo[M];
int main() {
    int i, n, m, op, l, r, x, j;
    scanf("%d %d", &n, &m);
    for(i = 0; i < n; i++)
        a[i] = 1000000000;
    for(i = 0; i < m; i++) {
        scanf("%d %d %d %d", &op, &l, &r, &x);
        l--; r--;
        opo[i] = op; lo[i] = l; ro[i] = r; xo[i] = x;
        if(op == 1) {
            for(j = l; j <= r; j++)
                b[j] += x;
        } else {
            bool any = false;
            for(j = l; j <= r; j++) {
                any |= (a[j] + b[j] >= x);
                if(a[j] + b[j] > x)
                    a[j] = x - b[j];
            }
            if(!any) { puts("NO"); return 0; }
        }
    }
    for(i = 0; i < n; i++)
        if((c[i] = a[i]) < -1000000000) {
            puts("NO");
            return 0;
        }
    for(i = 0; i < m; i++) {
        if(opo[i] == 1) {
            for(j = lo[i]; j <= ro[i]; j++)
                c[j] += xo[i];
        } else {
            int mx = c[lo[i]];
            for(j = lo[i] + 1; j <= ro[i]; j++)
                mx = max(mx, c[j]);
            if(mx != xo[i]) { puts("NO"); return 0; }
        }

    }
    puts("YES");
    for(i = 0; i < n; i++)
        printf("%d ", a[i]);
    putchar('\n');
}