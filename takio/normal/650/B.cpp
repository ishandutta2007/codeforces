#include <bits/stdc++.h>
#define LL long long
#define pii pair <int, int>
#define piii pair <int, pii>
#define xx first
#define yy second
#define ls rt << 1
#define rs rt << 1 | 1
#define lson ls, l, m
#define rson rs, m + 1, r
using namespace std;

const int N = 500010, mod = 1e9 + 7;

char s[N];
int n, a, b, t;
LL sum[N];

int get (char c) {
    return 1 + (c == 'w' ? b : 0);
}

int main () {
//    freopen ("in.txt", "r", stdin);
    cin >> n >> a >> b >> t;
    scanf ("%s", s);
    LL now = get (s[0]);
    if (now > t) {
        cout << 0;
        return 0;
    }
    for (int i = 1; i < n; i++) {
        now += a + get (s[i]);
    }
//    cout << now << endl;
    if (now <= t) {
        cout << n;
        return 0;
    }
    int res = 1;
    for (int i = 1; i < n; i++) sum[i] = sum[i - 1] + get (s[i]);
    now = get (s[0]);
    for (int i = 1, j = n - 1; i < n; i++, j--) {
        now += a + get (s[j]);
        if (now > t) break;
        int l = 0, r = n - i;
        while (l + 1 < r) {
            int m = l + r >> 1;
            if (now + (1LL * a * (i + m)) + sum[m] <= t) l = m;
            else r = m;
        }
        res = max (res, i + l + 1);
//        cout << now << ' ' << i <<' ' << i + l + 1 << endl;
    }
//    cout << res << endl;
    for (int i = n - 1; i >= 1; i--) sum[i] = sum[i + 1] + get (s[i]);
    now = get (s[0]);
    for (int i = 1, j = n - 1; i < n; i++, j--) {
        now += a + get (s[i]);
        if (now > t) break;
        int l = 0, r = n - i;
        while (l + 1 < r) {
            int m = l + r >> 1;
            if (now + (1LL * a * (i + m)) + sum[n - m] <= t) l = m;
            else r = m;
        }
        res = max (res, i + l + 1);
//        cout << now << ' ' << i <<' ' << i + l + 1 << ' ' << s[i] << ' ' << get (s[i]) << endl;
    }
    cout << res << endl;
}