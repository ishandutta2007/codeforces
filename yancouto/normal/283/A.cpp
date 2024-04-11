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

int a[200009];
ll sum[200009];
int sz = 1;
ll tot = 0;
int main() {
    int i, n, t, ai, x;
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d", &t);
        if(t == 1) {
            scanf("%d %d", &ai, &x);
            sum[ai - 1] += x;
            tot += ll(x) * ll(ai);
        } else if(t == 2) {
            scanf("%d", &x);
            sum[sz] = 0;
            a[sz++] = x;
            tot += x;
        } else {
            sz--;
            tot -= a[sz];
            tot -= sum[sz];
            sum[sz-1] += sum[sz];
        }
        printf("%.15f\n", double(tot) / sz);
    }
}