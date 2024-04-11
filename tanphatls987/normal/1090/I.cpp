#include <bits/stdc++.h>

using namespace std;

const int N = 1e7 + 10;
int n;
unsigned int b[N];
long long a[N];

void prepare() {
    long long l, r;
    unsigned int x, y, z;
    cin >> n >> l >> r >> x >> y >> z >> b[1] >> b[2];

    for(int i = 3; i <= n; i++) b[i] = b[i - 2] * x + b[i - 1] * y + z;

    long long len = r - l + 1;
    for(int i = 1; i <= n; i++) a[i] = 1LL * b[i] % len + l; 
}
const long long linf = 0x7fffffffffffffff;
const int inf = 2e9 + 10;
void solve() {
    long long ans = linf;
    long long maxv = a[n];
    for(int i = n - 1; i >= 1; i--) {
        if (a[i] < maxv)
            ans = min(ans, a[i] * maxv);
        maxv = max(maxv, a[i]);
    }

    if (ans > 0) {
        long long maxneg = -inf;
        
        long long minpos = inf;
        for(int i = 1; i <= n; i++) {
            if (a[i] >= 0) {
                if (a[i] > minpos) ans = min(ans, minpos * a[i]);
                minpos = min(minpos, a[i]);
            }
        }
        
        for(int i = n; i >= 1; i--){
            if (a[i] <= 0){
                if (a[i] < maxneg) 
                    ans = min(ans, a[i] * maxneg);
                maxneg = max(maxneg, a[i]);
            }
        }
    }
    if (ans == linf) cout << "IMPOSSIBLE\n";
    else cout << ans << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int test;
    cin >> test;
    while (test--) {
        prepare();
        solve();
    }
}