#include <bits/stdc++.h>
#define LL long long
#define pii pair <int, int>
#define xx first
#define yy second
using namespace std;

int res[1010];

int main () {
//    freopen ("in.txt", "r", stdin);
    int n, k, p, x, y, sum = 0, a, l = 0;
    cin >> n >> k >> p >> x >> y;
    for (int i = 1; i <= k; i++) {
        scanf ("%d", &a);
        sum += a;
        if (a < y) l++;
    }
//    cout << l << ' ' << r << endl;
    int cnt1 = min (n / 2 - l, n - k),  cnt2 = n - k - cnt1;
//    cout <<cnt1 << ' ' << cnt2 << endl;
    if (cnt1 < 0 || sum + cnt1 + cnt2 * y > x) {
        cout << "-1";
        return 0;
    }
    while (cnt1-- > 0) cout << 1 << ' ';
    while (cnt2-- > 0) cout << y << ' ';
}