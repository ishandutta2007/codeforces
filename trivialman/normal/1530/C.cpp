#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
//typedef __int128 LLL;
const LL P = 1e9 + 7;
const LL INF = 1e18;
const int N = 1e5 + 5;
mt19937 rng(time(0));

int T, n, a[N], b[N];

bool check(int x) {
    int suma = x * 100, sumb = 0;
    rep(i, (n + x) / 4 + 1, n) suma += a[i];
    int start = (n + x) / 4 <= x ? 1 : (n + x) / 4 - x + 1;
    rep(i, start, n) sumb += b[i];
    return suma >= sumb;
}

int main() {
    cin >> T;
    while (T--) {
        cin >> n;
        rep(i, 1, n) scanf("%d", a + i);
        rep(i, 1, n) scanf("%d", b + i);
        sort(a + 1, a + n + 1), sort(b + 1, b + n + 1);
        int l = 0, r = n + 1, ans;
        while (l <= r) {
            int mid = l + r >> 1;
            if (check(mid))
                r = mid - 1, ans = mid;
            else
                l = mid + 1;
        }
        cout << ans << endl;
    }
    return 0;
}