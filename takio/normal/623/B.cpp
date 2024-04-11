#include <bits/stdc++.h>
#define LL long long
#define pii pair <int, int>
#define xx first
#define yy second
using namespace std;

const int N = 1000100;

vector <int> g;
//int a[N];

int jug (int a, int b) {
    int t = a % b;
    return t == 1 || t == b - 1;
}

void solve (vector <int> &g, int x) {
//    g.clear();
//    if (x != 1) {
//        g.push_back (x);
//        g.push_back (x + 1);
//        if (x != 2) g.push_back (x - 1);
    int t = x;
    for (int i = 2; i * i <= t; i++) if (t % i == 0) {
        g.push_back (i);
        while (t % i == 0) t /= i;
    }
    if (t != 1) g.push_back(t);
    t = x + 1;
    for (int i = 2; i * i <= t; i++) if (t % i == 0) {
        g.push_back (i);
        while (t % i == 0) t /= i;
    }
    if (t != 1) g.push_back(t);
    t = x - 1;
    for (int i = 2; i * i <= t; i++) if (t % i == 0) {
        g.push_back (i);
        while (t % i == 0) t /= i;
    }
    if (t != 1) g.push_back(t);
//        x++;
    sort (g.begin(), g.end());
    g.resize(unique (g.begin(), g.end()) - g.begin());
//    }
}

int a[N], b[N], n, sum[N];
LL A, B;

LL solve (int x) {
    for (int i = 1; i <= n; i++) {
        if (a[i] % x == 0) b[i] = 0;
        else if (jug (a[i], x)) b[i] = 1;
        else b[i] = -1;
    }
    int mx = 0, mn = n + 1;
    for (int i = 1; i <= n; i++) if (b[i] == -1) {
        mx = max (mx, i);
        mn = min (mn, i);
    }
//    cout << x << ' ' << mn <<' ' << mx << endl;
    if (mx == 0 && mn == n + 1) {
        for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + b[i];
//        for (int i = 1; i <= n; i++) cout << b[i] << ' '; cout << endl;
        LL res = B * sum[n], mn = 0;
        for (int i = 1; i <= n; i++) {
//            cout << i << ' ' << mn << endl;
            res = min (res, A * i + mn + B * (sum[n] - sum[i]));
            mn = min (mn, B * sum[i] - A * i);
        }
//        cout << res << endl;
        return res;
    }
    LL now = 0, res = A * (mx - mn + 1);
    for (int i = 1; i < mn; i++) now += B * b[i];
    LL resmn = now;
    for (int i = mn - 1; i >= 1; i--) {
//        if (b[i] == 1)
        now -= B * b[i];
        now += A;
        resmn = min (resmn, now);
    }
//    cout << resmn << endl;
    res += resmn;
    now = 0;
    for (int i = mx + 1; i <= n; i++) now += B * b[i];
    resmn = now;
    for (int i = mx + 1; i <= n; i++) {
//        if (b[i] == 1)
        now -= B * b[i];
        now += A;
        resmn = min (resmn, now);
    }
//    cout << resmn << endl;
    res += resmn;
//    cout <<res << endl;
    return res;
}

int main () {
//    for (int i = 2; i < N; i++) if (!is[i]) {
//        g.push_back (i);
//        for (int j = i + i; j < N; j += i) {
//            is[j] = 1;
//        }
//    }
//    int n;
//    freopen ("in.txt", "r", stdin);
    cin >> n >> A >> B;
    int G = 0;
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &a[i]);
        G = __gcd (G, a[i]);
    }
    if (G != 1) {
        cout << 0 << endl;
        return 0;
    }
    solve (g, a[1]);
    solve (g, a[n]);
//    int now = 0;
    LL res = 1LL << 60;
    for (int i = 0; i < g.size(); i++) {
//        cout << g[i] << ' ' << solve (g[i]) << endl;
        res = min (res, solve (g[i]));
    }
    cout << res << endl;
}