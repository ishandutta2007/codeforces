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
        int i, j, n, x, y;
        scanf("%d", &n);
        int mx_x = INT_MIN, mn_x = INT_MAX, mx_y = INT_MIN, mn_y = INT_MAX;
        for(i = 0; i < n; i++) {
                scanf("%d %d", &x, &y);
                mx_x = max(mx_x, x);
                mx_y = max(mx_y, y);
                mn_x = min(mn_x, x);
                mn_y = min(mn_y, y);
        }
        if(mx_x <= mn_x || mx_y <= mn_y) puts("-1");
        else printf("%d\n", (mx_x - mn_x) * (mx_y - mn_y));
}