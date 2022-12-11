#include <bits/stdc++.h>
#define int long long

using namespace std;

const int INF = 4 * 1e18, N = 1e5 + 7;
int a[N], b[N];

int calc(int a, int b) {
    return a - 3 * b * b + 3 * b - 1;
}

int get0(int a, int c) {
    int l = 0, r = a + 1, mid;
    while (r - l > 1) {
        mid = (l + r) / 2;
        int cc = calc(a, mid);
        if (cc >= c) l = mid;
        else r = mid;
    }
    return l;
}

int get(int n, int c) {
    int res = 0;
    for (int i = 1; i <= n; i++) {
        b[i] = get0(a[i], c);
        res += b[i];
    }
    return res;
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int l = -INF, r = INF, mid;
    while (r - l > 1) {
        mid = (l + r) / 2;
        int t = get(n, mid);
        if (t >= k) l = mid;
        else r = mid;
    }
    int rest = k - get(n, r);
    for (int i = 1; i <= n; i++) {
        if (rest == 0) break;
        while (b[i] != a[i] && calc(a[i], b[i] + 1) == l) {
            b[i]++;
            rest--;
        }
    }
    assert(rest == 0);
    for (int i = 1; i <= n; i++) cout << b[i] << ' ';
    cout << endl;
}