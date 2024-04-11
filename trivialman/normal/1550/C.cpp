#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define MP make_pair
#define PB push_back
typedef long long LL;
const LL P = 1e9 + 7;
const int N = 2e5 + 5;

int T, n, a[N];

int main() {
    cin >> T;
    while (T--) {
        scanf("%d", &n);
        rep(i, 1, n) scanf("%d", a + i);
        int ans = n + n - 1;
        rep(i, 1, n - 2) {
            int x = a[i], y = a[i + 1], z = a[i + 2];
            ans += (x < y && y > z || x > y && y < z);
        }
        rep(i, 1, n - 3) {
            int x = a[i], y = a[i + 1], z = a[i + 2], w = a[i + 3];
            if (y < z)
                swap(y, z);
            ans += x < y && x > z && y > w && z < w;
        }
        printf("%d\n", ans);
    }
    return 0;
}